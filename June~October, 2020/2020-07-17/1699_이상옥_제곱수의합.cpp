#include <iostream>

#define MAX_NUM 100001
using namespace std;

int main(){
    int n, dp[100001]={0,};

    cin>>n;

    dp[0]=-MAX_NUM;
    for(int i=1; i<=n; i++)
        for(int j=1; j*j<=i; j++)
            dp[i] = min(dp[i], dp[i-(j*j)]+1);

    cout<<dp[n]+MAX_NUM<<endl;
    return 0;
}
