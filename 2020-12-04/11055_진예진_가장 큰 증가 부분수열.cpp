/*
[백준 11055 가장 큰 증가 부분 수열] https://www.acmicpc.net/problem/11055
*/
#include <stdio.h>
#include <iostream> 
#include <algorithm>
#include <string.h>

using namespace std;

int main(){
    FILE *stream =freopen("S2\\23\\input\\11055.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, answer = 0;
    int arr[1000];
    int dp[1000];

    memset(arr, 0, sizeof(arr));
    memset(dp, 0, sizeof(dp));

    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> arr[i];

        for(int j = i; j >= 0; j--){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
            answer = max(answer, dp[i]);
        }
    }

    cout << answer;
    return 0;
}
