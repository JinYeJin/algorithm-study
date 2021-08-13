/*
[백준 11051 이항계수 2] https://www.acmicpc.net/problem/11051
*/
#include <stdio.h>
#include <iostream> 
#define MOD 10007

using namespace std;

int dp[1001][1001];

// top-down
int binomial(int n, int k){
	if(k == 0 || n == k) 
		return 1;
    if(dp[n][k] == 0) dp[n][k] = (binomial(n-1, k-1)+ binomial(n-1, k))%MOD;
	return dp[n][k];
}

int main(){
    FILE *stream =freopen("S2\\23\\input\\11051.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long N, K, n_k;

    cin >> N >> K;

    cout << binomial(N, K);

/* bottom-up
    // 이항계수 조건 0 < K < N
    for(int i = 1; i <= N; i++){
        // 이항계수 조건 2
        // dp[i][0] => 하나도 안고르는 경우 = 한가지
        // dp[i][i] => 모든 것을 고르는 경우 = 한가지
        dp[i][0] = 1; dp[i][i] = 1;
        for(int j = 1; j < i; j++){
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%MOD;
        }
    }

    cout << dp[N][K];
*/
    return 0;
}
