// https://www.acmicpc.net/problem/14502
// 14502 연구소

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 8

int map[MAX][MAX];
int map_copy[MAX][MAX];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0, -1, 1 };
vector<pair<int, int>> virus;

int n, m;
int answer = -1;


void goVirus() {

	queue<pair<int, int>> que;

	for (int i = 0; i < virus.size(); i++) {
		que.push(make_pair(virus[i].first, virus[i].second)); // que에 바이러스 위치 저장
	}

	// 1. 바이러스 위치를 큐에 담아서 바이러스를 전파
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;

		que.pop();

		for (int i = 0; i < 4; i++) {
			int new_x = x + dx[i];
			int new_y = y + dy[i];

			if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m) {
				if (map_copy[new_x][new_y] == 0) {
					map_copy[new_x][new_y] = 2;
					que.push(make_pair(new_x, new_y));
				}
			}
		}
	}// end of while

	// 2. 안전구역 체크하기 
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map_copy[i][j] == 0) cnt++;
		}
	}

	if (cnt > answer) answer = cnt;

	return;
}


void wall(int cnt) {
	
	// 벽 3개를 세웠음
	if (cnt == 3) {

		// map_copy에 벽 3개 세운 현재 배열 map을 복사 한 후 map_copy배열에서 바이러스를 퍼지게 한다
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				map_copy[i][j] = map[i][j];
			}
		}
		// 바이러스 전파시킴
		goVirus();

		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				wall(cnt + 1); // 벽을 세운다.
				map[i][j] = 0;
			}
		}
	}

}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	// 1. map 입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];

			if (map[i][j] == 2) virus.push_back(make_pair(i, j));
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				// 벽을 세웠다고 가정
				map[i][j] = 1;
				wall(1); // i,j는 벽을 세운것을 고정으로 wall =3이 될때까지 수행함
				map[i][j] = 0; // 초기화
			}
		}
	}

	cout << answer;
	return 0;
}
