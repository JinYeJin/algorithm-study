#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321
using namespace std;

int des;
vector<pair<int,int>> bus[1001];
bool visited[1001]={0};

int dijk(int s){
    priority_queue<pair<int,int>> H;
    H.push({0,s});
    while(H.size()){
        auto h=H.top(); H.pop();
        int cost=h.first, now=h.second;
        if(visited[now]){
            continue;
        }
        if(now==des) return -cost;
        visited[now]=1;
        for(auto next : bus[now]){
            if(!visited[next.first]){
                H.push({cost-next.second, next.first});
            }
        }
    }
    return -1;
}

int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int N,M,A,B,C;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>A>>B>>C;
        bus[A].push_back({B,C});
    }
    cin>>A>>des;
    cout<<dijk(A);
    return 0;
}
