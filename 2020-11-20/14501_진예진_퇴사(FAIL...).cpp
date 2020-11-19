/*
[14501 백준] acmicpc.net/problem/14501
*/
#include <stdio.h>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;


int main(){
    FILE *stream =freopen("S2\\21\\input\\14501.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    int dp[16];
    int T[16]; // 일을 하는 기간
    int P[16]; // 이익

    cin >> N;
    

    memset(dp, 0, sizeof(dp));
    memset(T, 0, sizeof(T));
    memset(P, 0, sizeof(P));

    for(int n = 1; n <= N; n++){
        cin >> T[n] >> P[n];
    }


    for(int i = 1; i <= N+1; i++){
        for(int k = 1; k <= 5; k++){
            if(i-k >= 0){
                int profit = 0;
                if(T[i-k] <= k){
                    profit = dp[i-k] + P[i];
                    dp[i] = max(profit, dp[i]);
                }
            }
        }
    }

    // for(int i = 0; i <= N+1; i++)
    // cout << dp[i];

    cout << dp[N+1];

    return 0;
}
