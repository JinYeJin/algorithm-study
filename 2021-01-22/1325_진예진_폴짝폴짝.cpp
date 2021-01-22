/*
1325 폴짝폴짝 acmicpc.net/problem/1326
*/
#include <stdio.h>
#include <iostream> 
#include <string.h>

using namespace std;

int main(){
    FILE *stream =freopen("S2\\29\\input\\1326.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, min_v = 987654321;
    int a, b;
    int jump[1001];
    int dp[1001];
    int dp_l[1001];
    int dp_r[1001];

    cin >> N;

    cin >> a >> b;

    for(int i = 1; i <= N; i++){
        cin >> jump[i];
        dp[i] = 0;
    }

    dp[1] = dp[N] = 0;

    // a를 기준으로 양쪽으로 퍼져나가게 dp를 채움

    for(int i = a; i <= N; i++){
        // j: i 지점에서 몇칸 떨어져 있는가
        for(int j = 1; i-j >= a; j++){
            if(i % jump[i-j] == 0) dp[i] = dp[i-j] + 1;
        }
    }

    for(int i = a; i > 0; i--){
        for(int j = 1; i+j <= a; j++){
            if(i % jump[i+j] == 0) dp[i] = dp[i+j] + 1;
        }
    }

    // a -> b 경로 찾기
    memcpy(dp_l, dp, sizeof(dp));
    memcpy(dp_r, dp, sizeof(dp));

    for(int i = 1; i <= b; i++){
        for(int j = 1; i-j > 0; j++){
            if(i % jump[i-j] == 0) dp_l[i] = dp_l[i-j] + 1;
        }
    }

    for(int i = N-1; i >= b; i--){
        for(int j = 1; i+j <= N; j++){
            if(i % jump[i+j] == 0) dp_r[i] = dp_r[i+j] + 1;
        }
    }

    if((dp_l[b] == 0) && (dp_r[b] == 0)) cout << -1;
    else cout << (dp_l[b] > dp_r[b] ? dp_r[b] : dp_l[b]);

    return 0;
}
