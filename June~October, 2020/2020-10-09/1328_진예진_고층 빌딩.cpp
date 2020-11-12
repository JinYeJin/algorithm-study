/*
[1328 고층 빌딩] https://www.acmicpc.net/problem/1328
https://ksj14.tistory.com/entry/BackJoon1328-%EA%B3%A0%EC%B8%B5-%EB%B9%8C%EB%94%A9
*/
#include <stdio.h>
#include <iostream>
#define MOD 1000000007

using namespace std;

int n, l, r;
int dp[101][101][101];

int main(){
    FILE *stream =freopen("S2\\18\\input\\1328.txt", "r", stdin);
    if(!stream) perror("freopen");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, j, k;
    long long int temp;

    cin >> n >> l >> r;
 
    dp[1][1][1] = 1;
    dp[2][2][1] = 1;
    dp[2][1][2] = 1;
 
    for(int i = 3; i <= n; i++){
        dp[i][i][1] = dp[i][1][i] = 1;
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                temp = dp[i - 1][j][k];
                temp = (temp * (i - 2)) % MOD;
                temp = (temp + dp[i - 1][j - 1][k]) % MOD;
                temp = (temp + dp[i - 1][j][k - 1]) % MOD;
 
                dp[i][j][k] = temp;
            }
        }
    }
 
    cout << dp[n][l][r];
    return 0;
}
