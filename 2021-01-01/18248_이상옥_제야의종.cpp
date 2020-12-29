#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N,M;
string arr[1000];
bool answer(){
    for(int j=0;j<M;j++){
        for(int i=1;i<N;i++){
            if(arr[i-1][j]=='1'&&arr[i][j]=='0'){
                return false;
            }
        }
    }
    return true;
}
int main() {
    char c;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>c;
            arr[i].push_back(c);
        }
    }
    sort(arr,arr+N);
    cout<<(answer()?"YES\n":"NO\n");
    return 0;
}
