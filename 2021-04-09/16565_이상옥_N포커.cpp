#include <iostream>

using namespace std;

int inv(int a){
    int b=1,pow=10005;
    for(;pow;pow/=2){
        if(pow%2){
            (b*=a)%=10007;
        }
        (a*=a)%=10007;
    }
    return b;
}
int nCr(int n,int r){
    r=min(r,n-r);
    int a=1,b=1;
    for(int i=0;i<r;i++){
        (a*=(n-i))%=10007;
        (b*=(i+1))%=10007;
    }
    return (a*inv(b))%10007;
}

int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int N,answer=0,h=1;
    cin>>N;
    
    for(int i=1;i<=N/4;i++){
        (answer+=h*nCr(13,i)*nCr(52-i*4,N-i*4))%=10007;
        h*=-1;
    }
    cout<<(answer+10007)%10007;
    return 0;
}
