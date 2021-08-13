#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int n,a,b;
    priority_queue<int> Q;
    for(cin>>n;n--;){
        cin>>a;
        if(a){
            while(a--){
                cin>>b;
                Q.push(b);
            }
        }else if(Q.size()){
            cout<<Q.top()<<'\n';
            Q.pop();
        }else{
            cout<<"-1\n";
        }
    }
    return 0;
}
