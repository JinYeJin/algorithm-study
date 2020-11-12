#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n,dp[10001]={0,},w[10001]={0,};
    cin>>n;
    
    for(int i=1;i<=n;i++)
        cin>>w[i];

    dp[1]=w[1];
    dp[2]=w[1]+w[2];
    dp[3]=max(w[1], w[2])+w[3];
    
    for(int i=4;i<=n;i++)
        dp[i] = w[i]+max(w[i-1]+max(dp[i-3], dp[i-4]), dp[i-2]);

    cout<<max(dp[n-1],dp[n])<<endl;
    
    return 0;
}
