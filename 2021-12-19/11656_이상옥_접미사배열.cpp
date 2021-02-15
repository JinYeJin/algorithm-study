#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int main(){
    string S;
    priority_queue<string,vector<string>,greater<string>> Ss;
    cin>>S;
    for(int s=0;s<S.size();s++){
        Ss.push(S.substr(s));
    }
    while(Ss.size()){
        cout<<Ss.top()<<'\n';Ss.pop();
    }
    return 0;
}
