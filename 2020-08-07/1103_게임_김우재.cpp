#include <iostream>
#include <vector>
#include <cstring>


using namespace std;

int map[51][51];
int dp[51][51];
bool passed[51][51];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n,m;

int dfs(int x, int y){
    if(map[x][y] == 0) return 0;
    if(x < 0 || x >= n || y < 0 || y >= m) return 0;
    if(passed[x][y]){
        cout << -1;
        exit(0);
    }
    if(dp[x][y] != -1) return dp[x][y];

    passed[x][y] = true;
    for(int i=0; i < 4; i++){
        int nx = x + dx[i] * map[x][y];
        int ny = y + dy[i] * map[x][y];
        dp[x][y] = max(dp[x][y], dfs(nx,ny)+1);
    }
    passed[x][y] = false;
    return dp[x][y];
}

int main(void){
    cin >> n >> m;
    vector<string> temp(n);
    
    for(int i=0; i < n; i++){
        cin >> temp[i];
    }
    
    for(int i=0; i < n; i++){
        int j = 0;
        for(char temp : temp[i]){
            if(temp == 'H' || temp == 'h') map[i][j] = 0; // 구멍이라는 뜻
            else map[i][j] = temp - '0';
            j++;
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(0,0) << "\n";
    
    
    return 0;
}

/*
 10 10
 1111111111
 1111111111
 1111111111
 1111111111
 1111111111
 1111111111
 1111111111
 1111111111
 1111111111
 1111111111
 */
