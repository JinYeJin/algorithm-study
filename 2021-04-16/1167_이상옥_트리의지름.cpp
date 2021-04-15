#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V,a,b,c;
vector<pair<int,int>> tree[100001];

pair<int,int> dijk(int s){
    int visited[100001]={0},cnt=0;
    priority_queue<pair<int,int>> H;
    H.push({0,s});
    while(H.size()){
        auto [cost,now]=H.top();H.pop();
        if(visited[now]) continue;
        visited[now]=1;
        if(++cnt==V) return {-cost,now};
        for(auto [next,next_cost]:tree[now]){
            if(!visited[next]){
                H.push({cost-next_cost,next});
            }
        }
    }
    return {-1,-1};
}

int main()
{
    cin>>V;
    for(int i=0;i<V;i++){
        cin>>a;
        while(1){
            cin>>b;
            if(b==-1) break;
            cin>>c;
            tree[a].push_back({b,c});
        }
    }
    cout<<dijk(dijk(1).second).first;
    
    return 0;
}

