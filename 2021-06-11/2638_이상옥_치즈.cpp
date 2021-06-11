#include "bits/stdc++.h"

#define 경계(i,j) (0<=i && i<N && 0<=j && j<M)
using namespace std;

bool 치즈[100][100],방문[100][100];
int 공기접촉[100][100];
int N,M,di[]={1,-1,0,0},dj[]={0,0,1,-1};
queue<pair<int,int>> 녹는치즈;

void dfs(int i,int j){
    if(!경계(i,j)) return;
    if(치즈[i][j]){
        if(++공기접촉[i][j]==2) 녹는치즈.push({i,j});
        return;
    }
    if(방문[i][j]) return;
    방문[i][j]=1;

    for(int d=0;d<4;d++) dfs(i+di[d],j+dj[d]);
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>치즈[i][j];
        }
    }
    int answer=0;
    while(1){
        memset(공기접촉,0,sizeof(공기접촉));
        memset(방문,0,sizeof(방문));
        dfs(0,0);
        if(녹는치즈.empty()){
            cout<<answer;
            break;
        }
        while(녹는치즈.size()){
            auto [i,j]=녹는치즈.front();녹는치즈.pop();
            치즈[i][j]=0;
        }
        answer++;
    }
    
    return 0;
}


