#include <iostream>
#include <string.h>

using namespace std;

int N,T[15],P[15],dp[15];
int DFS(int i){
    if(i>N) return 0;
    if(dp[i]==-1){
        dp[i]=DFS(i+1);
        if(i+T[i]<=N) dp[i]=max(dp[i], P[i]+DFS(i+T[i]));
    }
    return dp[i];
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    memset(dp,-1,sizeof(dp));
    cin>>N;
    for(int i=0;i<N;i++) cin>>T[i]>>P[i];
    cout<<DFS(0);
    return 0;
}
