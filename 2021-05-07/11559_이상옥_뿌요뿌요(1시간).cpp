#include "bits/stdc++.h"

using namespace std;

int di[]={1,-1,0,0}, dj[]={0,0,1,-1};
bool visited[14][8];
char board[14][8];

void gravity(){
    for(int j=1;j<7;j++){
        int cnt=0;
        for(int i=12;i>0;i--){
            if(board[i][j]=='.') cnt++;
            else swap(board[i][j],board[i+cnt][j]);
        }
    }
}
void puyo(int i,int j){
    char c=board[i][j];
    board[i][j]='.';
    for(int d=0;d<4;d++){
        int ni=i+di[d], nj=j+dj[d];
        if(c==board[ni][nj]){
            puyo(ni,nj);
        }
    }
}
int ispuyo(int i,int j){
    visited[i][j]=1;
    int same=1;
    for(int d=0;d<4;d++){
        int ni=i+di[d], nj=j+dj[d];
        if(board[i][j]==board[ni][nj] && !visited[ni][nj] ){
            same+=ispuyo(ni,nj);
        }
    }
    return same;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    memset(board,'.',sizeof(board));
    for(int i=1;i<13;i++){
        for(int j=1;j<7;j++){
            cin>>board[i][j];
        }
    }
    queue<pair<int,int>> Q;
    int answer=0;
    while(1){
        memset(visited,0,sizeof(visited));
        for(int i=1;i<13;i++){
            for(int j=1;j<7;j++){
                if(board[i][j]!='.' && ispuyo(i,j)>3){
                    Q.push({i,j});
                }
            }
        }
        if(Q.empty()) break;
        while(Q.size()){
            auto [i,j]=Q.front();Q.pop();
            puyo(i,j);
        }
        answer++;
        gravity();
    }
    
    cout<<answer;
    return 0;
}


