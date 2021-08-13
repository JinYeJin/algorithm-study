#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;

vector<int> n2n[2001];
int visited[2000]={0};
int N,M,a,b,answer=0;

bool friends(int now,int n){
    if(n==0) return 1;
    for(int i : n2n[now]){
        if(!visited[i]){
            visited[i]=1;
            if(friends(i,n-1)) return 1;
            visited[i]=0;
        }
    }
    return 0;
}
int main(){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>a>>b;
        n2n[a].push_back(b);
        n2n[b].push_back(a);
    }
    for(int i=0;i<N;i++) n2n[N].push_back(i);
    cout<<friends(N,5);
    return 0;
}
