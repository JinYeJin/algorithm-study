/*
[백준 10164 격자상의 경로] https://www.acmicpc.net/problem/10164
*/
#include <stdio.h>
#include <iostream> 
#include <string.h>


using namespace std;

int main(){
    FILE *stream =freopen("S2\\25\\input\\10164.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 행, 열, 동그라미의 위치
    int N, M, K;
    int r, c, k_row, k_col;
    int dp[16][16];

    cin >> N >> M >> K;
    memset(dp, 0, sizeof(dp));
    

    dp[1][1] = 1;
    r = c = k_row = k_col = 1;


    // K가 주어질 때 추가계산
    if(K != 0){
        r = 1;
        k_row = K / M + 1;
        k_col = K % M;

        if(k_row != N && k_col != M){
            if(k_col == 0) k_col = M;
            for(r; r <=k_row; r++){
                for(c = 1; c <= k_col; c++){
                    dp[r][c] += dp[r-1][c] + dp[r][c-1];
                }
            }
        r = k_row;
        c = k_col + 1;
        }
    }

    for(r; r <= N; r++){
        for(c; c <= M; c++){
            dp[r][c] += dp[r-1][c] + dp[r][c-1];
        }
        c = k_col;
    }


    cout << dp[N][M];

    return 0;
}
