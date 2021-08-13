#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N,M, di[]={1,-1,0,0}, dj[]={0,0,1,-1};
int earth[2][302][302]={0},visited[302][302],year=0,cnt;

void DFS(int i, int j){
    if(earth[year&1][i][j]>0 && !visited[i][j]){
        visited[i][j]=1;
        for(int d=0;d<4;d++){
            int ni=i+di[d], nj=j+dj[d];
            if(earth[year&1][ni][nj]<1) earth[~year&1][i][j]--;
            DFS(ni,nj);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    
    cin>>N>>M;
    for(int i=1;i<=N;i++)for(int j=1;j<=M;j++)cin>>earth[0][i][j];
    for(;;year++){
        for(int i=1;i<=N;i++)
            for(int j=1;j<=M;j++)
                earth[~year&1][i][j]=earth[year&1][i][j];
        cnt=0;
        memset(visited,0,sizeof(visited));
        for(int i=1;i<=N;i++)
            for(int j=1;j<=M;j++)
                if(earth[year&1][i][j]>0 && !visited[i][j]){
                    cnt++;
                    DFS(i,j);
                }
        if(cnt!=1) break;
        
    }
    if(cnt==0) cout<<0;
    else cout<<year;
    return 0;
}
