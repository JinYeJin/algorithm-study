#include "bits/stdc++.h";

using namespace std;

int R,C, dr[]={1,-1,0,0}, dc[]={0,0,1,-1},o,v;
char board[252][252];
bool visited[252][252]={0};

void dfs(int r, int c) {
    if(board[r][c]=='#') return;
    if(visited[r][c]) return;
    visited[r][c]=1;
    if(board[r][c]=='o') o++;
    if(board[r][c]=='v') v++;
    for(int d=0;d<4;d++) dfs(r+dr[d],c+dc[d]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int answer_o=0, answer_v=0;

    memset(board,'#',sizeof(board));

    cin>>R>>C;
    
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin>>board[i][j];
        }
    }
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (!visited[r][c]) {
                v=0; o=0;
                dfs(r,c);
                if(v<o) answer_o+=o;
                else answer_v+=v;
            }
        }
    }
    cout<<answer_o<<' '<<answer_v;
    

    return 0;
}
