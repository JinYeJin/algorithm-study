/*
[백준 1965 상자넣기] acmicpc.net/problem/1965
11053 가장 긴 증가하는 부분수열과 완전히 같은 문제
*/
#include <stdio.h>
#include <iostream> 
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, answer = 0;
    int arr[1000];
    int dp[1000];

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
        int current_dp_value = 0;
        for(int j = i; j >= 0; j--){
            if(arr[i] > arr[j]){
                current_dp_value = max(dp[j], current_dp_value);
            }
            dp[i] = current_dp_value + 1;
            answer = max(answer, dp[i]);
        }
    }

    cout << answer;

    return 0;
}
