/*
[백준 1915 가장 큰 정사각형] https://www.acmicpc.net/problem/1915
*/

#include <stdio.h>
#include <algorithm>

using namespace std;

int array[1001][1001];
int dp[1001][1001];

int main(){
    FILE *stream =freopen("S2\\8\\input\\1915_input.txt", "r", stdin);
    if(!stream) perror("freopen");

    int N, M, max_value;

    max_value = -1;

    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%1d", &array[i][j]);
            dp[i][j] = array[i][j];
            if(i == 0){
                if(j == 0) continue;
                else dp[i][j] = array[i][j-1];
                continue;
                // j만 0일 때
            }else if(j == 0) dp[i][j] = array[i-1][j];
            // 현재 값의 윗줄

            if(array[i-1][j-1] == 1 && array[i-1][j] && array[i][j-1]){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]) + 1;
            }
            max_value = dp[i][j] > max_value ? dp[i][j] : max_value;
        }
    }


    printf("%d", max_value * max_value);

    return 0;
}
