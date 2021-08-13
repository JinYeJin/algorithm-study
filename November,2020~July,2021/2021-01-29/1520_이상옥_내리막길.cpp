#include <iostream>
#include <string.h>

#define check(i,j) (0<=i and i<M and 0<=j and j<N)

using namespace std;

int N,M,map[500][500],dp[500][500], di[]={1,-1,0,0}, dj[]={0,0,-1,1};

int DFS(int i,int j){
    if(i==M-1 and j==N-1) return 1;
    if(dp[i][j]==-1){
        dp[i][j]=0;
        for(int x=0;x<4;x++){
            int ni=i+di[x], nj=j+dj[x];
            if(check(ni,nj) and map[i][j]>map[ni][nj]) dp[i][j]+=DFS(ni,nj);
        }
    }
    return dp[i][j];
}
int main(){
    cin.tie(NULL);ios::sync_with_stdio(false);
    cin>>M>>N;
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            cin>>map[i][j];
    memset(dp,-1,sizeof(dp));
    cout<<DFS(0,0);
    return 0;
}
