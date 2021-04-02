#include <iostream>
#include <cstring>

using namespace std;

long DP[1000001],N;

long DFS(long n){
    if(DP[n]==-1){
        DP[n]=0;
        for(int i=n;i>0;i--){
            (DP[n]+=2*DFS(n-i))%=1000000007;
            if(i==2){
               (DP[n]+=DP[n-i])%=1000000007;
            }
        }
    }
    return DP[n];
    
}
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    memset(DP,-1,sizeof(DP));
    DP[0]=1;
    cin>>N;
    cout<<DFS(N);
    return 0;
}


