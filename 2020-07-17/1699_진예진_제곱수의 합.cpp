/*
2020-07-12 진예진
[백준 1699 제곱수의 합] https://www.acmicpc.net/problem/1699
참고 https://lmcoa15.tistory.com/43
*/
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    FILE *stream = freopen("S2\\7\\input\\1699_input.txt", "r", stdin);
    if(!stream) perror("freopen");

    int N;
    int dp[100000];

    scanf("%d", &N);

    
    for(int i = 1; i <= N; i++){
        dp[i] = i;
        for(int j = 1; j*j <= i; j++){
            // dp[i]는 i일 때 최소항의 개수
            // j^2 전의 항에서 최소값을 가져온 뒤 i^2한 값을 더하는 것과 같음
            // dp[5]=dp[5-1*1]+1 (dp[4]인 경우에 1을 제곱한 값을 더한 경우)
            // dp[5]=dp[5-2*2]+1 (dp[1]인 경우에 2를 제곱한 값을 더한 경우)
            dp[i] = min(dp[i], dp[i - j*j] + 1);
        }
    }

    printf("%d", dp[N]);

    return 0;
}
