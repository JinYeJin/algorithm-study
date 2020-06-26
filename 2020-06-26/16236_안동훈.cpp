// 16236. 아기 상어
// 풀다맘
// https://www.acmicpc.net/problem/16236

#include<bits/stdc++.h>

using namespace std;

int N;
int room[20][20];
int dist[20][20];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

class user { //상어의 상태 정의
public:
	int x;
	int y;
	int size;
	int exp;
	int step;

public:
	void init(int a, int b)
	{
		x = a;
		y = b;
		size = 2;
		exp = 0;
		step = 999;
	}
};

user S;

void find(int cx, int cy) { // 상어보다 작은 물고기 체크

	queue<pair<int, int>> q;
	dist[cx][cy] = 0;
	q.push({ cx,cy });

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int x = cur.x;
		int y = cur.y;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue; // 맵 벗어남
			if (dist[nx][ny] != -1 || room[nx][ny] > S.size) continue; // 이미 방문, 상어보다 큼
			dist[nx][ny] = dist[x][y] + 1; // 이동거리 갱신

			if (room[nx][ny] != 0 && room[nx][ny] < S.size) { // 먹을 수 있음
				if (S.step > dist[nx][ny]) {
					S.step
				}
			}


		}

	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (room[i][j] != 0 && room[i][j] < S.size) {
				// 먹을 수 있는 지 확인
				if()
			}
		}
	}

	return false;
}

void calculate() {
	while (1) {
		find(S.x, S.y); // 먹을 수 있는 물고기 찾기

	}
}

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> room[i][j];
			if (room[i][j] == 9) {
				S.init(i, j);
				room[i][j] = 0;
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();
	calculate();

	cout << S.step;

	system("pause");

	return 0;
}
