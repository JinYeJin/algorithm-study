#include "bits/stdc++.h";

using namespace std;

int R,C,dr[]={1,-1,0,0},dc[]={0,0,1,-1};
char board[52][52];

int bfs(int i, int j) {
    if(board[i][j]=='W') return 0;

    bool visited[51][51]={0};
    queue<pair<int,int>> Q;

    Q.push({i,j});
    visited[i][j]=1;
    int size,cnt=-1;
    while(size=Q.size()) {
        while(size--) {
            auto q= Q.front();Q.pop();
            int r=q.first, c=q.second;
            
            for (int d = 0; d < 4; d++) {
                int nr=r+dr[d], nc=c+dc[d];
                if (board[nr][nc]=='L' && !visited[nr][nc]) {
                    Q.push({nr,nc});
                    visited[nr][nc]=1;
                }

            }

        }
        cnt++;
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int answer=0;
    memset(board,'W',sizeof(board));
    cin>>R>>C;
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin>>board[r][c];
        }
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            answer=max(answer,bfs(r,c));
        }
    }
    cout<<answer;
    return 0;
}
