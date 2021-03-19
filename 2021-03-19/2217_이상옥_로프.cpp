#include <iostream>
#include <algorithm>

using namespace std;


int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int N,rope[100000],max_weight=0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>rope[i];
    }
    sort(rope,rope+N);
    for(int i=0;i<N;i++){
        max_weight= max(max_weight,rope[i]*(N-i));
    }
    cout<<max_weight;
    return 0;
}
