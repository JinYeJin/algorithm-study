#include <iostream>
#include <vector>

using namespace std;

const int INF=(1e9);

int N,idx,dp[30]={0};

void make_dp(int i){
    dp[i]=dp[i-1]*2+i+2;
    idx=i;
    if(dp[i]<INF) make_dp(i+1);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    make_dp(1);
    cin>>N;
    N--;
    while(1){
        idx--;
        if(dp[idx]+idx+2<N)
            N-=dp[idx]+idx+3;
        else if(dp[idx]<=N){
            N-=dp[idx];
            break;
        }
    }
    
    cout<<(N?"o":"m");
    return 0;
}
