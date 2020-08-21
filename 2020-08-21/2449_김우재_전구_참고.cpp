/*

*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int N, K;
int p[201];
int dp[201][201];

int dfs(int start, int end) {
    if (start == end) return 0; // 끝까지 왔다면
    dp[start][end]; // 메모라이즈를 위한 값
    if (dp[start][end] != -1) return dp[start][end]; // 리턴
    dp[start][end] = 987654321;

    for (int i = start; i < end; i++) { // 시작부터 끝까지
        int tmp = p[start] != p[i+1] ? 1 : 0; // 현재와 다음이 다르면 1, 같으면 0
        // start start + start+1, end
        // start start+1 + start+2, end
        // start start+2 + start+3, end
        // start start+3 + start+4, end
        // 하나씩 진행을 하는거네
        // 즉 [1] [전체-1]
        // [2] [전체-2]
        // [3] [전체-3]
        dp[start][end] = min(dp[start][end], dfs(start, i) + dfs(i + 1, end) + tmp);
    }
    return dp[start][end];
}

int main()
{
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> p[i];
    memset(dp, -1, sizeof(dp));
    
    
    cout << dfs(1, N);
}

