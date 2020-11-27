/*
[백준 11504 가장 긴 바이토닉 부분 수열] acmicpc.net/problem/11054
*/
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int N;

int get_len(int arr[], int dp[]){
    int len = 0;
    int current;

    for(int i = 1; i <= N; i++) {
        current = 0;
        for(int j = 1; j < i; j++){
            if(arr[i] > arr[j]) current = max(current, dp[j]);
        }
        dp[i] = current + 1;
        len = max(len, dp[i]);    
    }
    return len;
}

int main(){
    FILE *stream =freopen("S2\\22\\input\\11054.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int temp;
    int numbers[1001], dp_numbers[1001];
    int reverse[1001], dp_reverse[1001];

    cin >> N;

    memset(dp_numbers, 0, sizeof(dp_numbers));
    memset(dp_reverse, 0, sizeof(dp_reverse));
    memset(numbers, 0, sizeof(dp_numbers));
    memset(reverse, 0, sizeof(dp_reverse));
    
    for(int i = 1; i <= N; i++){
        cin >> temp;
        numbers[i] = temp;
        reverse[N-i+1] = temp;
    }

    
    int increase = get_len(numbers, dp_numbers);
    int decrease = get_len(reverse, dp_reverse);

    int max_v;

    for(int i = 1; i <= N; i++){
        max_v = max(dp_numbers[i] + dp_reverse[N-i+1], max_v);
    }

    cout << max_v - 1;

    return 0;
}
