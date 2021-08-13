#include "bits/stdc++.h"

using namespace std;

int N,pre[1001],left_node[1001],idx,i;

void DFS(int left,int right){
    if(i==N) return;
    int node=pre[i];
    if(left_node[node]-left>1){
        //go_left
        i++;
        DFS(left,left_node[node]);
    }
    if(right-left_node[node]>1){
        i++;
        DFS(left_node[node],right);
    }
    cout<<node<<' ';
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T;
    for(cin>>T;T--;){
        cin>>N;
        for(int i=0;i<N;i++){
            cin>>pre[i];
        }
        for(int i=0;i<N;i++){
            cin>>idx;
            left_node[idx]=i;
        }
        i=0;
        DFS(-1,N);
        cout<<'\n';
    }
    return 0;
}


