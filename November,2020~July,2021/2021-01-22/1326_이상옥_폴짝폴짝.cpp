#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int N,arr[10001],a,b;

int BFS(){
    bool visited[10001]={0};
    queue<pair<int,int>> Q;
    Q.push({0,a});
    visited[a]=1;
    while(Q.size()){
        auto [cnt, now]=Q.front();Q.pop();
        if(now==b)return cnt;
        
        for(int i=now+arr[now];i<=N;i+=arr[now]){
            if(!visited[i]){
                Q.push({cnt+1,i});
                visited[i]=1;
            }
        }
        for(int i=now-arr[now];i>0;i-=arr[now]){
            if(!visited[i]){
                Q.push({cnt+1,i});
                visited[i]=1;
            }
        }
    }
    
    return -1;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>arr[i];
    }
    cin>>a>>b;
    cout<<BFS();
}
