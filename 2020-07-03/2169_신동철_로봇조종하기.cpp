//dp���ذ�
//dp �� �Ͽ������� �ұ��ϰ� �ð��ʰ��� ������ �˾����� ������ ���.
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
	//N>1�ϰ��
	for(int i=1 ; i<N ; i++)
		for (int j = 0; j < M; j++) {
			int local_max = -2147483647;  //��󵵸��ߴ�.. ���⼭ Ʋ����,. ó���� 0���� �ʱ�ȭ �ߴµ�  �׷��� �ȵǾ���.
			for (int j2 =0 ; j2 < M; j2++) {
				int a = 0;
				//j2<j ; j�� dp �̿밡��
				if (j2 < j) {
					if (j2 - 1 >= 0)
						a = tbf[i][j2 - 1];
					local_max = max(local_max, dp[i - 1][j2] + tbf[i][j] - a);
				
				}
				
					//j2 == j ; i-1�� dp �̿�
				else if ( j2 == j)
					local_max = max(local_max, dp[i - 1][j] + map[i][j]);

				// j2 > j   ; tbf�̿�
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
	ios_base::sync_with_stdio(false);//1288ms  ���ѽð�2���ε� �������� ������.
	cin.tie(NULL);
	cout.tie(NULL);
	In();

	func();

	cout << dp[N - 1][M - 1];
}