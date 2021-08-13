#include "bits/stdc++.h"

#define check(i,j) (0<=i && i<N && 0<=j && j<M)
using namespace std;

int N,M,di[]={1,-1,0,0}, dj[]={0,0,1,-1};
char board[20][20];
queue<pair<int,int>> coin;

bool visited[20][20][20][20]={0};
int bfs(){
    for(int answer=1;answer<11;answer++){
        int size=coin.size()/2;
        while(size--){
            pair<int,int> coin1=coin.front(); coin.pop();
            pair<int,int> coin2=coin.front(); coin.pop();
            for(int d=0;d<4;d++){
                int ni1=coin1.first+di[d], nj1=coin1.second+dj[d];
                int ni2=coin2.first+di[d], nj2=coin2.second+dj[d];
                if(board[ni1][nj1]=='#'){
                    ni1-=di[d]; nj1-=dj[d];
                }
                if(board[ni2][nj2]=='#'){
                    ni2-=di[d]; nj2-=dj[d];
                }
                if(check(ni1,nj1) && check(ni2,nj2)){
                    if(visited[ni1][nj1][ni2][nj2]) continue;
                    visited[ni1][nj1][ni2][nj2]=1;
                    
                    coin.push({ni1,nj1});
                    coin.push({ni2,nj2});
                }else if(check(ni1,nj1) || check(ni2,nj2)){
                    return answer;
                }
            }
        }
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>board[i][j];
            if(board[i][j]=='o') coin.push({i,j});
        }
    }
    auto [i1,j1]=coin.front();
    auto [i2,j2]=coin.back();
    visited[i1][j1][i2][j2]=1;
    cout<<bfs();

    return 0;
}


