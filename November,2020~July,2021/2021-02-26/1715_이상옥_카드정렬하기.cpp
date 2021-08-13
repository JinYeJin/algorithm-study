#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    priority_queue<int> Q;
    int N,answer=0,card;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>card;
        Q.push(-card);
    }
    while(Q.size()>1){
        card=Q.top();Q.pop();
        card+=Q.top();Q.pop();
        answer-=card;
        Q.push(card);
    }
    cout<<answer;
    return 0;
}
