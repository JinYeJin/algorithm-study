#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int DP[100][100001],N,K,answer=0;
pair<int,int> things[100];

int DFS(int n,int k){
    if(n==N || k==0) return 0;
    if(DP[n][k]==-1){
        DP[n][k]=DFS(n+1,k);
        if(k-things[n].first>=0){
            DP[n][k]=max(DP[n][k],DFS(n+1,k-things[n].first)+things[n].second);
        }
    }
    return DP[n][k];
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    memset(DP,-1,sizeof(DP));
    cin>>N>>K;
    for(int i=0;i<N;i++){
        cin>>things[i].first>>things[i].second;
    }
    cout<<DFS(0,K);
    return 0;
}
