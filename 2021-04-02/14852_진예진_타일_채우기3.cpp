/*
14852 타일 채우기
*/
#include <stdio.h>
#include <iostream> 

using namespace std;

int dp[1000000];

int main(){
    FILE *stream =freopen("S2\\37\\input\\14852.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;

    cin >> N;

    dp[1] = 2;

    for(int i = 2; i <= N; i++){
        for(int j = i; j > 0; j--){
            for(int k = 0; k < i-j; k++){
                dp[i] += dp[k];
            }
        }
    }

    cout << dp[N];

    return 0;
}
