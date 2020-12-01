#include <iostream>
#include <algorithm>

using namespace std;
#define mod 1000000007
long INV_NUM(long num){
    long inv=mod-2,answer=1;
    for(;inv;inv/=2){
        if(inv&1){
            answer*=num;
            answer%=mod;
        }
        num*=num;
        num%=mod;
    }
    return answer;
}
long comb(long n,long k){
    long answer=1,div=1;
    k=min(k,n-k);
    for(long i=0;i<k;i++){
        answer*=n-i;
        answer%=mod;
        div*=i+1;
        div%=mod;
    }
    return (answer*INV_NUM(div))%mod;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    long N,K;
    cin>>N>>K;
    cout<<comb(N,K);
    return 0;
}
