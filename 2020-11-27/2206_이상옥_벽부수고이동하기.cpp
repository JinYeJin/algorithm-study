#include <iostream>
#include <queue>

#define check(i,j) (0<=i && i<N && 0<=j && j<M)
#define INF 987654321

using namespace std;

int N,M, di[]={1,-1,0,0}, dj[]={0,0,1,-1};
char MAP[1000][1000];
bool visited[2][1000][1000]={0};

int BFS(){
    queue<pair<pair<int,int>,pair<int,int>>> Q;
    Q.push({{0,1},{0,0}});
    while(Q.size()){
        auto q=Q.front(); Q.pop();
        int b=q.first.first, cnt=q.first.second, i=q.second.first, j=q.second.second;
        if(visited[b][i][j]) continue;
        visited[1][i][j]=1;
        if(b==0) visited[0][i][j]=1;
        if(i==N-1 and j==M-1) return cnt;
        for(int d=0;d<4;d++){
            int ni=i+di[d], nj=j+dj[d];
            if(check(ni,nj)){
                if(MAP[ni][nj]=='0') Q.push({{b,cnt+1},{ni,nj}});
                else if(b==0) Q.push({{1,cnt+1},{ni,nj}});
            }
        }
    }
    return -1;
}
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    cin>>N>>M;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>MAP[i][j];
    cout<<BFS();
    return 0;
}
