#include "bits/stdc++.h"

#define def DP[visit][n]
using namespace std;


vector<int> child[1000001];
int DP[2][1000001];
int dfs(int pnt, bool is_early, int n){
    if(def==-1){
        def=is_early;
        if(is_early){
            for(int next:child[n]){
                if(next==pnt) continue;
                def+=min(dfs(n,1,next),dfs(n, 0,next));
            }
        }else{//얼리어답터가 아니라면 친구들이 전부 얼리 어답터여야한다.
            for(int next:child[n]){
                if(next==pnt) continue;
                def+=dfs(n, 1,next);
            }
        }
        //cout<<visit<<' '<<pnt<<' '<<n<<' '<<def<<'\n';
    }
    return def;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N,a,b;
    bool not_root[1000001]={0};
    memset(DP,-1,sizeof(DP));
    cin>>N;
    for(int i=1;i<N;i++){
        cin>>a>>b;
        child[a].push_back(b);
        child[b].push_back(a);
        
    }
    cout<<min(dfs(0,1,1),dfs(0,0,1));
    
    return 0;
}


