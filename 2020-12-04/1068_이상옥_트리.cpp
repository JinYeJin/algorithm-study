#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,del,answer=0;
vector<vector<int>> child;
vector<int> input;
int main(){
    cin.tie(NULL);ios::sync_with_stdio(false);
    cin>>N;
    queue<int> Q;
    child.resize(N);
    input.resize(N);
    for(int i=0;i<N;i++) cin>>input[i];
    cin>>del;
    for(int i=0;i<N;i++){
        if(i==del) continue;
        if(input[i]==-1) Q.push(i);
        else child[input[i]].push_back(i);
    }
    while(Q.size()){
        int q=Q.front(); Q.pop();
        if(child[q].empty()) answer++;
        else for(int c:child[q]) Q.push(c);
    }
    cout<<answer;
    return 0;
}
