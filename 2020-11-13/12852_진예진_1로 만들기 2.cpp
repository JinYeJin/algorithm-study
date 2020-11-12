/*
[백준 12852] https://www.acmicpc.net/problem/12852
*/
#include <stdio.h>
#include <iostream> 

using namespace std;

int dp[1000001]; // dp[i] : i에서 연산을 사용한 횟수
int answer[1000001]; // dp[i] 값을 가져온 인덱스를 표시함

int main(){
    FILE *stream =freopen("S2\\20\\input\\12852.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;

    cin >> N;
    dp[1] = 0;

    for(int i = 2; i <= N; i++){
        // 1번 전에서 값을 가져옴
        dp[i] = dp[i-1] + 1;
        answer[i] = i-1;

        if(i%2 == 0){
            if(dp[i/2] < dp[i]){
                dp[i] = dp[i/2] + 1;
                answer[i] = i/2;
            }
        }

        if(i%3 == 0){
            if(dp[i/3] < dp[i]){
                dp[i] = dp[i/3] + 1;
                answer[i] = i/3;
            }
        }
    } 

    printf("%d\n", dp[N]);
    printf("%d ", N);

    for(int i = N; i > 1; i){
        printf("%d ", answer[i]);
        i = answer[i];
    }

    return 0;
}
