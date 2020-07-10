/*
2020-07-10 진예진
[백준 10835 카드게임] https://www.acmicpc.net/problem/10835
*/

#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;

int left[2000];
int right[2000];
int dp[2000][2000];

int main(){
    // FILE *stream = freopen("S2\\6\\input\\10835_input.txt", "r", stdin);
    FILE *stream = freopen("S2/6/input/10835_input.txt", "r", stdin);
    if(!stream) perror("freopen");
    
    int N;

    scanf("%d", &N);

    memset(dp, 0, sizeof(dp));

    // input 값 받기
    for(int i = 0; i < N; i++){
        scanf("%d", &left[i]);
    }
    for(int i = 0; i < N; i++){
        scanf("%d", &right[i]);
    }

    dp[0][0] = 1;

    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            // 왼쪽카드가 오른쪽보다 커 오른쪽을 버리고 점수 얻음
            if(left[i] > right[j]) dp[i][j+1] = dp[i][j] + right[j];
            // zk
            else if(i != 0 && dp[i-1][j-1] != -1) dp[i][j+1] = max(dp[i-1][j+1], dp[i-1][j+1]);
            // 더 이상 버릴 없으니 break
            else{
                dp[i][j+1] = -1;
                break;
            }
        }
    }

    printf("%d", dp[N][N]);
    return 0;
}
