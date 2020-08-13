#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int N, M, max_side;
int square_map[1000][1000], dp[1000][1000], dist[3][2] = { {0,-1},{-1,-1},{-1,0} } ;
int main() {
	//입력
	cin >> N >> M;
	for(int i=0; i<N; i++)
		for (int j = 0; j < M; j++) {
			scanf("%1d", &square_map[i][j]);
			if ((i == 0 || j == 0) && square_map[i][j] == 1) {
				dp[i][j] = 1; max_side = 1;
			}
		}
	//계산
	for (int i = 1; i < N; i++)
		for (int j = 1; j < M; j++) {
			if (square_map[i][j] == 1) {
				int local_min_dp = 1000;
				for (int tp = 0; tp < 3; tp++) {
					int nexti = i + dist[tp][0];
					int nextj = j + dist[tp][1];
					local_min_dp = min(local_min_dp, dp[nexti][nextj]);
				}
				dp[i][j] = local_min_dp + 1;
				max_side = max(dp[i][j], max_side);
			}
		}
	//출력
	cout << max_side * max_side;
}