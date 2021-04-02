#include <stdio.h>
#include <iostream>

using namespace std;


int main(){
    FILE *stream =freopen("S2\\37\\input\\12865.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    int item[102][2];
    int dp[102][100002];

    cin >> N >> K;
    for(int i = 1; i <= N;i++){
        cin >> item[i][0] >> item[i][1];
    }

    for(int i = 1; i <= N; i++){
        int weight = item[i][0];
        int val = item[i][1];

        for(int j = 0; j <= K;j++){
            if(j < item[i][0])
                dp[i][j]=dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j - weight] + val);
        }
    }
    
    cout << dp[N][K];
}
