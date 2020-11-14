#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int N,T;
string ambi(vector<string> arr){
    for(int i=1;i<arr.size();i++) if(arr[i].substr(0,arr[i-1].size()) == arr[i-1]) return "NO\n";
    return "YES\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    for(cin>>T;T--;){
        cin>>N;
        vector<string> numbers(N);
        for(int i=0;i<N;i++) cin>>numbers[i];
        sort(numbers.begin(), numbers.end());
        cout<<ambi(numbers);
    }
    return 0;
}
