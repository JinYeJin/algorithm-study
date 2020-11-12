// https://www.acmicpc.net/problem/7576
// 토마토 7576 2차원

// 런타임에러

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int m, n;

int dx[4] = {-1,1,0,0 };
int dy[4] = {0,0,-1,1 };

vector<vector<int>> tomato;
vector<vector<int>> visited;
queue<pair<int, int>> que;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tomato[i][j];

			//토마토가 익었으면 큐에 넣는다
			if (tomato[i][j] == 1) {
				que.push(make_pair(i, j));
				visited[i][j]++;
			}
		}
	}
	
	// 모든 토마토가 익어있었다면
	if (que.size() == n * m) {
		cout << 0;
		return 0;
	}

	int day = 0;


	while (!que.empty()) {
		// 런타임주의
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < m && ny >= 0 && ny < n ) {
				if (tomato[nx][ny] == 0 && visited[nx][ny] == false) {
					visited[nx][ny]++;
					tomato[nx][ny] = 1;
					que.push(make_pair(nx, ny));
					day++;
				}
			
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tomato[i][j] == 0) {
				day = -1;
				break;
			}
		}
	}

	cout << day;

	return 0;
}
