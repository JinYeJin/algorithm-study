#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue<int> Q;
vector<int> times,answer;
vector<vector<int>> build;

int N,a;

int main(){
    cin.tie(NULL);ios::sync_with_stdio(false);
    cin>>N;
    build.resize(N+1);
    times.resize(N+1);
    answer.resize(N+1,-1);
    for(int i=1;i<=N;i++){
        Q.push(i);
        cin>>times[i];
        for(;cin>>a,a!=-1;) build[i].push_back(a);
    }
    while(Q.size()){
        int q=Q.front(),i=0,max_time=0;
        Q.pop();
        for(;i<build[q].size();i++){
            if(answer[build[q][i]]==-1) break;
            max_time=max(max_time,answer[build[q][i]]);
        }
        if(build[q].size()==i)
            answer[q]=max_time+times[q];
        else Q.push(q);
    }
    for(int i=1;i<=N;i++) cout<<answer[i]<<'\n';
    return 0;
}

