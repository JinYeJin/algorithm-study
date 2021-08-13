#include <iostream>
#include <cstring>

using namespace std;

int T,n,pick[100001],cycle_node,answer;
bool visited[100001],flag;
void DFS(int node){
    if(pick[node]==0){
        flag=0;
        return;
    }
    if(visited[node]){
        flag=1;
        cycle_node=node;
        return;
    }
    visited[node]=1;
    DFS(pick[node]);
    if(flag){
        pick[node]=0;
        if(cycle_node==node) flag=0;
    }
    else{
        pick[node]=0;
        answer++;
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    for(cin>>T;T--;){
        cin>>n;
        answer=0;
        memset(visited,0,sizeof(visited));
        for(int i=1;i<=n;i++) cin>>pick[i];
        for(int i=1;i<=n;i++){
            if(pick[i]>0){
                DFS(i);
            }
        }
        cout<<answer<<'\n';
    }
    return 0;
}
