#include <iostream>
#include <algorithm>

using namespace std;

int N,arr[1000],a[1000],c=0;
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    cin>>N;
    for(int i=0;i<N;i++) cin>>arr[i];

    for(int i=0;i<N;i++){
        auto it=lower_bound(a,a+c,arr[i]);
        if(it==a+c) a[c++]=arr[i];
        else a[it-a]=arr[i];
    }
    cout<<c;
    return 0;
}
