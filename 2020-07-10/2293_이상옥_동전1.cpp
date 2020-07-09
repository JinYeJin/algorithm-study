#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,k,c[100],dp[10001]={0,};

    cin>>n>>k;

    for(int i=0;i<n;i++)
        cin>>c[i];

    dp[0]=1;
    for(int i=0;i<n;i++)
        for(int j=c[i];j<=k;j++)
            dp[j]+=dp[j-c[i]];

    cout<<dp[k]<<endl;
    return 0;
}
