#include <iostream>
#include <algorithm>

using namespace std;

int N, a[1000],b[1000]={0,},c[1000]={0,},m=0;

int main(){
    cin>>N;
    for(int i=0;i<N;i++) cin>>a[i];
    for(int i=0;i<N;i++)
        for(int j=0;j<i;j++){
            if(a[i]>a[j]) b[i]=max(b[i],b[j]+1);
            if(a[i]<a[j]) c[i]=max(c[i],max(b[j]+1,c[j]+1));
        }
    for(int i=0;i<N;i++) m=max(m,max(b[i],c[i]));
    cout<<m+1;
    return 0;
}
//////////
#include <iostream>
#include <algorithm>

using namespace std;

int N, arr[1000],dp[1000]={0},b[1000]={0},n=0,answer=0;

int main(){
    cin>>N;
    for(int i=0;i<N;i++) cin>>arr[i];
    for(int i=0;i<N;i++){
        auto it=lower_bound(dp,dp+n,arr[i]);
        if(it==dp+n) dp[n++]=arr[i];
        else *it=arr[i];
        b[i]=it-dp+1;
    }
    n=0;
    for(int i=N-1;i>=0;i--){
        auto it=lower_bound(dp,dp+n,arr[i]);
        if(it==dp+n) dp[n++]=arr[i];
        else *it=arr[i];
        answer=max(answer,b[i]+(int)(it-dp));
    }
    cout<<answer;
    return 0;
}
