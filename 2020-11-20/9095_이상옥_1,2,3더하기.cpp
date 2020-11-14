#include <iostream>

using namespace std;
int T,n,dp[12]={1};
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    for(int i=1;i<12;i++){
        if(i-1>=0) dp[i]+=dp[i-1];
        if(i-2>=0) dp[i]+=dp[i-2];
        if(i-3>=0) dp[i]+=dp[i-3];
    }
    for(cin>>T;T--;){
        cin>>n;
        cout<<dp[n]<<'\n';
    }
    return 0;
}
