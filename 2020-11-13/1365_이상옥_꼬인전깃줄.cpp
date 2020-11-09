#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    vector<int> arr;
    int N,a;
    cin>>N;
    
    for(int i=0;i<N;i++){
        cin>>a;
        auto it = lower_bound(arr.begin(), arr.end(), a);
        if(it==arr.end()) arr.push_back(a);
        else *it=a;
    }
    N-=arr.size();
    cout<<N;
    return 0;
}
