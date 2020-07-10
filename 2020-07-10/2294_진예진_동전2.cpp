/*
2020-07-08 진예진
[백준 2294 동전 2] https://www.acmicpc.net/problem/2294
*/

#include <stdio.h>
#include <algorithm>
#define VALUE_MAX 10001

using namespace std;

int main(){
    FILE *stream = freopen("S2/6/input/2294_input.txt", "r", stdin);
    if(!stream) perror("freopen");

    int N, K;
    int coins[101];
    int dp[VALUE_MAX];

    scanf("%d %d", &N, &K);

    for(int i = 0; i < N; i++){
        scanf("%d", &coins[i]);
    }
    
    // 최솟값을 구해야 하므로 나올 수 있는 최대값보다 1이 큰 10001로 초기화
    for(int i = 1; i <= K; i++){
        dp[i] = VALUE_MAX;
    }

    // 0 원을 만드는 동전의 개수는 0!
    // 맨첨의 dp[1]을 생각해보면, min(dp[1], dp[0] + 1)이기 때문에 dp[0]이 0으로 초기화 되어야 동전개수 1개라는 값이 나옴
    dp[0] = 0;

    for(int i = 0; i < N; i++){
        // coins[i] 이전의 값은 계산할 필요가 없숨
        for(int j = coins[i]; j <= K; j++){
            // 밑에 if 조건을 주는 것 보다 위에 for 문의 시작을 j = 1 이 아니라 coins[i] 부터 시작하는 게 효율적
            //if(j - coins[i] >= 0)
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }

    // 불가능 한 경우!!! 잊지말고 생각해주기, 모든 동전의 가치가 100,000 이 들어올 때 불가능 k 가 훨씬 작음
    if(dp[K] == VALUE_MAX) printf("-1");
    else printf("%d", dp[K]);

    return 0;
}
