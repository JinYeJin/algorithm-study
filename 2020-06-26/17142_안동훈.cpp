// 17142. 연구소 3
// https://www.acmicpc.net/problem/17141
// 그냥 이거 보고 함 https://yabmoons.tistory.com/254

#include<bits/stdc++.h>

using namespace std;

int N, M;
int empty_count;
int room[50][50];
int t[50][50];
bool S[10];
int ans = 987654321;

vector<pair<int, int>> v;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void calculate(queue<pair<int, int>> q) {
	int infect = 0;
	int tt = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (room[nx][ny] != 1 && t[nx][ny] == -1) {
				t[nx][ny] = t[x][y] + 1;
				if (room[nx][ny] == 0) {
					infect++;
					tt = t[nx][ny];
				}
				q.push({ nx,ny });
			}
		}
	}
	if (infect == empty_count) {
		ans = min(ans, tt);
	}
}

void choice(int idx, int cnt) {
	if (cnt == M) {
		queue<pair<int, int>> q;
		memset(t, -1, sizeof(t));
		for (int i = 0; i < v.size(); i++) {
			if (S[i]) {
				q.push({ v[i].first, v[i].second });
				t[v[i].first][v[i].second] = 0;
			}
		}

		calculate(q);
		return;
	}

	for (int i = idx; i < v.size(); i++) {
		if (S[i]) continue;
		S[i] = true;
		choice(i + 1, cnt + 1);
		S[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> room[i][j];
			if (room[i][j] == 0) empty_count++;
			else if (room[i][j] == 2) v.push_back({ i,j });
		}
	}

	choice(0, 0);

	if (ans == 987654321) cout << -1 << '\n';
	else cout << ans << '\n';

	return 0;
}
