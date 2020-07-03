//dp로해결
//dp 로 하였음에도 불구하고 시간초과가 나올줄 알았지만 무사히 통과.
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int map[1000][1000];
int dp[1000][1000];
int tbf[1000][1000];
void In() {
	cin >> N >> M;
	for(int i=0 ; i<N; i++)
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (j == 0) {
				tbf[i][j] = map[i][j];
				if (i == 0)
					dp[i][j] = tbf[i][j];
			}
			else {
				tbf[i][j] = tbf[i][j - 1] + map[i][j];
				if( i== 0)
					dp[i][j] = tbf[i][j];
			}
		}
}
void func() {
	//N>1일경우
	for(int i=1 ; i<N ; i++)
		for (int j = 0; j < M; j++) {
			int local_max = -2147483647;  //상상도못했다.. 여기서 틀렸음,. 처음에 0으로 초기화 했는데  그러면 안되었음.
			for (int j2 =0 ; j2 < M; j2++) {
				int a = 0;
				//j2<j ; j행 dp 이용가능
				if (j2 < j) {
					if (j2 - 1 >= 0)
						a = tbf[i][j2 - 1];
					local_max = max(local_max, dp[i - 1][j2] + tbf[i][j] - a);
				
				}
				
					//j2 == j ; i-1행 dp 이용
				else if ( j2 == j)
					local_max = max(local_max, dp[i - 1][j] + map[i][j]);

				// j2 > j   ; tbf이용
				else  {
					if (j - 1 >= 0)
						a = tbf[i][j - 1];
					local_max = max(local_max, dp[i - 1][j2] + tbf[i][j2] - a);
				}
			}
			dp[i][j] = local_max;
		}
}
int main() {
	ios_base::sync_with_stdio(false);//1288ms  제한시간2초인데 이정도면 빡빡함.
	cin.tie(NULL);
	cout.tie(NULL);
	In();

	func();

	cout << dp[N - 1][M - 1];
}