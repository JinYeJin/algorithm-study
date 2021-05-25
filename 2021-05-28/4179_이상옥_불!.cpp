#include "bits/stdc++.h"

#define check(i,j) (0<=i && i<N && 0<=j && j<M)
using namespace std;

int N,M,di[]={1,-1,0,0}, dj[]={0,0,1,-1};
char board[1000][1000];
queue<pair<int,int>> JH;
queue<pair<int,int>> Fire;

string bfs(){
    int answer=0;
    while(JH.size()){
        auto size=Fire.size();
        while(size--){
            auto [i,j]=Fire.front(); Fire.pop();
            for(int d=0;d<4;d++){
                int ni=i+di[d], nj=j+dj[d];
                if(!check(ni,nj)) continue;
                if(board[ni][nj]=='.'){
                    board[ni][nj]='F';
                    Fire.push({ni,nj});
                }
            }
        }
        
        size=JH.size();
        while(size--){
            auto [i,j]=JH.front(); JH.pop();
            for(int d=0;d<4;d++){
                int ni=i+di[d], nj=j+dj[d];
                if(!check(ni,nj)) return to_string(answer+1);
                if(board[ni][nj]=='.'){
                    board[ni][nj]='J';
                    JH.push({ni,nj});
                }
            }
        }
        answer++;
    }
    return "IMPOSSIBLE";
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>board[i][j];
            if(board[i][j]=='J') JH.push({i,j});
            else if(board[i][j]=='F') Fire.push({i,j});
        }
    }
    cout<<bfs();

    return 0;
}


