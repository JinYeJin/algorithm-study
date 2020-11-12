/*
2020-07-08 진예진
[백준 2293 동전 1] https://www.acmicpc.net/problem/2293
참고 https://sihyungyou.github.io/baekjoon-2293/
*/

#include <stdio.h>

using namespace std;

int main(){
    FILE *stream = freopen("S2/6/input/2293_input.txt", "r", stdin);
    if(!stream) perror("freopen");

    int N, K;
    int coins[101];
    int dp[10001] = {0,};

    scanf("%d %d", &N, &K);

    for(int i = 0; i < N; i++){
        scanf("%d", &coins[i]);
    }

    dp[0] = 1;

    // i: 현재 선택된 동전의 인덱스
    for(int i = 0; i < N; i++){
        // j: 현재 계산하는 가치의 값
        for(int j = 1; j <= K; j++){
            // 이전동전 선택과정까지 계산된 dp[i] 값에 현재 선택한 동전의 가치만큼 뺀 인덱스의 dp 값을 더해준다.
            if(j - coins[i] >= 0) dp[j] += dp[j - coins[i]];
        }
    }

    printf("%d", dp[K]);

    return 0;
}
