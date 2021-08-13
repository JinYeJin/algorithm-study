#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int N,K,doll,answer=1<<20,add=0;
    queue<int> Q;
    cin>>N>>K;
    for(int i=0;i<N;i++){
        cin>>doll;
        if(doll==1){
            Q.push(i);
            if(Q.size()==K){
                answer=min(answer,Q.back()-Q.front()+1);
                Q.pop();
            }
        }
    }
    cout<<(answer==(1<<20)?-1:answer);
    return 0;
}
