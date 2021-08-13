/*
[백준 9095] 1,2,3 더하기 https://www.acmicpc.net/problem/9095
*/
#include <stdio.h>
#include <iostream> 
#include <string.h>

using namespace std;

int main(){
    FILE *stream =freopen("S2\\21\\input\\9095.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T, N;
    int dp[12];

    cin >> T;

    for(int t = 0; t < T; t++){
        cin >> N;
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for(int i = 3; i <= N; i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }

        cout << dp[N] << "\n";
    }

    return 0;
}
