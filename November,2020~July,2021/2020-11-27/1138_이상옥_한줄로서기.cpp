#include <iostream>
#include <algorithm>

using namespace std;

int N,arr[11],answer[11];
bool visited[11]={0};

bool DFS(int n){
    if(n==N+1) return true;
    for(int i=1;i<=N;i++){
        if(!visited[i]){
            int cnt=0;
            for(int j=i+1;j<=N;j++){
                if(visited[j]){
                    cnt++;
                }
            }
            if(cnt!=arr[i]) continue;
            visited[i]=1;
            if(DFS(n+1)){
                answer[n]=i;
                return true;
            }
            visited[i]=0;
        }
    }
    return false;
}
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    cin>>N;
    for(int i=1;i<=N;i++) cin>>arr[i];
    DFS(1);
    for(int i=1;i<=N;i++) cout<<answer[i]<<' ';
    return 0;
}
