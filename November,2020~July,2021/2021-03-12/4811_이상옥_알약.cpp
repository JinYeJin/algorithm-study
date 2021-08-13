#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

long DP[31][31];

long DFS(int h,int n){
    if(DP[h][n]==-1){
        DP[h][n]=0;
        if(h>0) DP[h][n]+=DFS(h-1,n);
        if(n>0) DP[h][n]+=DFS(h+1,n-1);
    }
    return DP[h][n];
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    memset(DP,-1,sizeof(DP));
    DP[0][0]=1;
    int N;
    DFS(0,30);
    while(cin>>N){
        if(N==0) break;
        cout<<DP[0][N]<<'\n';
    }
    return 0;
}
