/*
yabmoons.tistory.com/197
namu.wiki/w/%EC%B5%9C%EC%9E%A5%20%EC%A6%9D%EA%B0%80%20%EB%B6%80%EB%B6%84%20%EC%88%98%EC%97%B4
*/
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main(){
    // FILE *stream =freopen("S2\\17\\input\\2631.txt", "r", stdin);
    FILE *stream =freopen("S2/17/input/2631.txt", "r", stdin);
    if(!stream) perror("freopen");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int max_value, N;
    int array[201], dp[201];

    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> array[i];
    }

    max_value = 0;
    memset(array, 0, sizeof(array));
    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= N; i++){
        dp[i] = 1;
        for (int j = 1; j <= i; j++){
            if (array[j] < array[i] && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
            }
        }
        if (max_value < dp[i]) max_value = dp[i];
    }
 
    cout << N - max_value;

    return 0;
}
