#include "bits/stdc++.h"

using namespace std;

set<int> child[100001];
int idx=0;
int arr[100001];
bool dfs(int now){
    //cout<<now<<'\n';
    while(child[now].size()){
        idx++;
        if(child[now].find(arr[idx])!=child[now].end()){//셋안에 요소가 있다면.
            child[now].erase(arr[idx]);
            child[arr[idx]].erase(now);
            if(!dfs(arr[idx])) return 0;
        }else{
            return 0;
        }
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int N,a,b;
    cin>>N;
    for(int i=1;i<N;i++){
        cin>>a>>b;
        child[a].insert(b);
        child[b].insert(a);
    }
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    if(arr[0]==1){
        cout<<dfs(1);
    }
    else{
        cout<<0;
    }
    
    return 0;
}


