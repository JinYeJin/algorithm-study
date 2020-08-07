/*
[2629] https://www.acmicpc.net/problem/2629
https://stillchobo.tistory.com/111
*/
#include <stdio.h>
#include <iostream>

using namespace std;

int dp[31][80002]; // dp[i][j] : i 번째 추까지 사용했을 때 j 라는 무게를 측정할 수 있는가?
int main(){
    FILE *stream =freopen("S2\\10\\input\\2629.txt", "r", stdin);
    // FILE *stream =freopen("S2/10/input/2629.txt", "r", stdin);
    if(!stream) perror("freopen");

    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int n; 
    int mid = 40000;
    cin >> n; 

    dp[0][mid] = true; 

    for(int i = 1; i <= n; i++){ 
        int w;
        cin >> w; 

        for(int j = 0; j <= 80002; j++){ 
            if(dp[i-1][j] == false) continue; 

            dp[i][j] = true; 

            if(j + w <= 80002) dp[i][j+w] = true; 
            if(j - w >= 0) dp[i][j-w] = true; 
        } 
    } 
    
    int m;
    cin >> m;

    for(int i = 0; i < m; i++){ 
        int w; 
        cin >> w; 

        if(dp[n][w+mid]) cout << "Y "; 
        else cout << "N "; 
    } 
    
    return 0;
}
