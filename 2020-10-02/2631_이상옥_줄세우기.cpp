#include <iostream>
#include <algorithm>

using namespace std;

int N,c,dp[200]={0},idx=0;


int main(){
    cin.tie(NULL);ios::sync_with_stdio(false);
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>c;
        if(c>dp[idx]) dp[++idx]=c;
        else *lower_bound(dp,dp+idx,c)=c;
    }
    cout<<N-idx;
    return 0;
}
