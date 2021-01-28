#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int,int>>> n2n;
int answer[201][201],n,m;

void djik(int s){
    priority_queue<pair<int,pair<int,int>>> H;
    int cnt=0;
    bool visited[201]={0};
    H.push({0,{s,-1}});
    while(H.size()){
        auto h=H.top();H.pop();
        int cost=h.first, now=h.second.first, pre=h.second.second;
        
        if(visited[now]){
            continue;
        }
        visited[now]=1;
        answer[now][s]=pre;

        if(++cnt==n){
            return;
        }
        for(auto next: n2n[now]){
            H.push({cost-next.first,{next.second,now}});
        }
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    n2n.resize(n+1);
    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        n2n[a].push_back({c,b});
        n2n[b].push_back({c,a});
    }
    for(int i=1;i<=n;i++){
        djik(i);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(answer[i][j]==-1) cout<<"- ";
            else cout<<answer[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
