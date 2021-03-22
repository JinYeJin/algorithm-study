#include <iostream>

using namespace std;

long DP[5001]={1,1};

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int N;
    for(int i=2;i<5001;i++){
        for(int j=0;j<i/2;j++){
            (DP[i]+=DP[j]*DP[i-j-1])%=987654321;
        }
        (DP[i]*=2)%=987654321;
        if(i%2){
            int j=i/2;
            (DP[i]+=DP[j]*DP[i-j-1])%=987654321;
        }
    }
    cin>>N;
    cout<<DP[N/2];
    return 0;
}
