// https://www.acmicpc.net/problem/10026
// 적록색약 10026

#include <iostream>
#include<string.h>
using namespace std;

char color[101][101] = { 0, };
int visit[101][101] = { 0, };

int dx[4] = {-1, 1, 0, 0}; // 
int dy[4] = {0 ,0, -1, 1};

int n;
int ans1 = 0, ans2 = 0;
void dfs(int x, int y) {

	visit[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int new_x = x + dx[i];
		int new_y = y + dy[i];

		if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < n && visit[new_x][new_y] == 0) {
			if(color[x][y] == color[new_x][new_y])
				dfs(new_x, new_y);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	cin >> n; 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> color[i][j];
		}
	}

	// 1. 적록색약 NO
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			if (visit[i][j] == 0) {
				dfs(i, j);
				ans1++;
			}
		}
	}

	memset(visit, 0, sizeof(visit)); // visit 초기화

	// 2. 적록색약 YES

	// G -> R로 변경
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (color[i][j] == 'G') color[i][j] = 'R';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			if (visit[i][j] == 0) {
				dfs(i, j);
				ans2++;
			}
		}
	}

	printf("%d %d\n", ans1, ans2);
}
