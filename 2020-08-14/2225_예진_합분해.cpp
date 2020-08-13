/*
[백준 2225 합분해] https://www.acmicpc.net/problem/2225
참고 https://sihyungyou.github.io/baekjoon-2225/
*/
#include <stdio.h>
#define MOD 1000000000

using namespace std;

int N, K;

int main(){
    FILE *stream =freopen("S2\\11\\input\\2225.txt", "r", stdin);
    if(!stream) perror("freopen");


    int dp[201][201] = { 0, };
    int N, K, i, j, l;

    scanf("%d %d", &N, &K);

    for(i = 0; i <= N; i++) {
        dp[0][i] = 0;
        dp[1][i] = 1;
    }

    for(i = 2; i <= K; i++) {
        for (j = 0; j <= N; j++) {
            for (l = 0; l <= j; l++) {
                dp[i][j] = (dp[i][j] + dp[i-1][j-l]) % MOD;
            }
        }
    }

    printf("%d\n", dp[K][N]);

    return 0;
}
