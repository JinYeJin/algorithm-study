https://www.acmicpc.net/problem/3109

#include<iostream>
 
#define MAX 10000
using namespace std;
 
int r, c, answer;
char arr[MAX][500];
bool visited[MAX][500];
bool ans;
 
int dx[] = { -1, 0, 1 };
int dy[] = { 1, 1, 1, };

void DFS(int x, int y)
{
    visited[x][y] = true;
    if (y == c - 1)
    {
        ans = true;
        answer++;
        return;
    }
 
    for (int i = 0; i < 3; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
 
        if (nx >= 0 && ny >= 0 && nx < r && ny < c)
        {
            if (arr[nx][ny] == '.' && visited[nx][ny] == false)
            {
                DFS(nx, ny);
                if (ans == true) return;
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    // 입력
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    // dfs 시작
    
    for (int i = 0; i < r; i++)
    {
        ans = false;
        DFS(i, 0);
    }
    cout << answer << endl;
 
    return 0;
}
 

