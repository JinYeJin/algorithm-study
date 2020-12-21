#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> prime;
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int L,U,x,y;
    prime.push_back(2);
    for(int i=3;i<1000001;i++){
        int size=prime.size(),j=0;
        bool check=true;
        for(;j<size;j++){
            if(prime[j]*prime[j]>i) break;
            if(i%prime[j]==0){
                check=false;
                break;
            }
        }
        if(check) prime.push_back(i);
    }
    while(1){
        cin>>L>>U;
        if(L==-1 && U==-1) break;
        x=0,y=0;
        auto it=lower_bound(prime.begin(),prime.end(),L);
        auto end=upper_bound(prime.begin(),prime.end(),U);
        for(;it!=end;it++){
            x++;
            if(*it%4==1)y++;
        }
        if(L<=2 and 2<=U)y++;
        cout<<L<<' '<<U<<' '<<x<<' '<<y<<'\n';
    }
    return 0;
}
