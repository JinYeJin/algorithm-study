// 시간초과 주의
// dfs 시간초과나서 dp와 같이 풀었음

// dp 참고 https://yabmoons.tistory.com/339

#include<iostream>
#include<string>
#include<cstring>

using namespace std;
 
int N, M, ans;
int arr[50][50];
int DP[50][50];
bool visited[50][50];
 
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
 
int Bigger(int A, int B) { if (A > B) return A; return B; }
 
int DFS(int x, int y)
{
    // 기저조건
    if (x < 0 || y < 0 || x >= N || y >= M || arr[x][y] == 0) return 0;
    
    if (visited[x][y] == true){
        cout << -1 << endl;
        exit(0);
    }
    if (DP[x][y] != -1) return DP[x][y];
 
    visited[x][y] = true;
    DP[x][y] = 0;
    
    // 기존 dfs 동일
    for (int i = 0; i < 4; i++){
        int nx = x + (arr[x][y] * dx[i]); // ???? arr[x][y] * dx[i] 곱해주는 이유는?? 
        int ny = y + (arr[x][y] * dy[i]);
        DP[x][y] = Bigger(DP[x][y], DFS(nx, ny) + 1);
    }
    visited[x][y] = false;
    return DP[x][y];
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string str; 
        cin >> str;
        
        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] == 'H') arr[i][j] = 0; // H는 구멍
            else arr[i][j] = str[j] - '0'; // 문자를 숫자로
        }
    }
    
    memset(DP, -1, sizeof(DP)); 
    ans = DFS(0, 0);
    cout << ans << endl;
    return 0;
}
 
