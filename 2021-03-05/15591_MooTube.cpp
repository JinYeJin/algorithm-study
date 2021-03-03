#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int N,Q;
vector<pair<int,int>> n2n[5001];

int dijk(int K, int v){
    queue<pair<int,int>> Q;
    bool visited[5001]={0};
    int num_node=1,answer=0;
    Q.push({1<<30,v});
    while(Q.size()){
        auto q=Q.front();Q.pop();
        int r=q.first, node=q.second;
        if(visited[node]) continue;
        visited[node]=1;
        for(auto next:n2n[node]){
            if(!visited[next.first]){
                int k=min(r,next.second);
                if(k>=K){
                    answer++;
                }
                Q.push({k,next.first});
            }
        }
        if(num_node++==N){
            return answer;
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int p,q,r,k,v;
    cin>>N>>Q;
    for(int i=1;i<N;i++){
        cin>>p>>q>>r;
        n2n[p].push_back({q,r});
        n2n[q].push_back({p,r});
    }
    for(int i=0;i<Q;i++){
        cin>>k>>v;
        cout<<dijk(k,v)<<'\n';
    }
    return 0;
}
