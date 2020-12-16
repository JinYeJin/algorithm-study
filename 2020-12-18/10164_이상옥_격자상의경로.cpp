#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int N,M,K,dp[226]={0,1};
    cin>>N>>M>>K;
    for(int i=1;i<N*M;i++){
        if(i==K) K=0;
        if(i%M){//오른쪽으로 가는 경우
            dp[i+1]+=dp[i];
        }
        if(i+M<=N*M){//아래로 가는경우
            if(K==0 || i+M<=K){
                dp[i+M]+=dp[i];
            }
        }
    }
    cout<<dp[N*M];
    
    return 0;
}
