#include <iostream>
#include <algorithm>

const int MOD=1000000007;
using namespace std;

int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    long N,mul=2,answer=1;
    cin>>N;
    if(N==0)answer=1;
    else{
        N--;
        for(;N;N/=2){
            if(N&1){
                answer*=mul;
                answer%=MOD;
            }
            mul*=mul; //2^2mul
            mul%=MOD;
        }
    }
    //2^(N-1) =
    cout<<answer;
    return 0;
}
