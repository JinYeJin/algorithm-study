#include <iostream>
#include <string.h>

#define mod 1000000007
using namespace std;

long dp[101][101];
int N,M,P;
long DFS(int n, int p){
    if(dp[n][p]==-1){
        dp[n][p]=(DFS(n-1,p-1)*(N-n+1))%mod;
        if(n>M) (dp[n][p]+=DFS(n,p-1)(n-M)%=mod;
    }
    return dp[n][p];
}
int main(){
    ios::sync_with_stdio(0);
    cin>>N>>M>>P;
    memset(dp,-1,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<=N;i++)dp[i][0]=0;
    for(int i=1;i<=P;i++)dp[0][i]=0;
    
    printf("%ld",DFS(N,P));
    return 0;
}
