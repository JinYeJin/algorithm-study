#include <iostream>
#include <string.h>
#include <queue>

#define check(i,j) (0<=i && i<N && 0<=j && j<M)
#define INF 987654321
using namespace std;

struct POINT{
    int cnt, i, j;
    bool b;
};
int N,M, di[]={1,-1,0,0}, dj[]={0,0,1,-1};
char MAP[1000][1000];
bool visited[2][1000][1000]={0};

int BFS(){
    queue<POINT> Q;
    Q.push({1,0,0,0});
    while(Q.size()){
        auto q=Q.front(); Q.pop();
        if(visited[q.b][q.i][q.j]) continue;
        visited[1][q.i][q.j]=1;
        if(q.b==0) visited[0][q.i][q.j]=1;
        if(q.i==N-1 and q.j==M-1) return q.cnt;
        for(int d=0;d<4;d++){
            int ni=q.i+di[d], nj=q.j+dj[d];
            if(check(ni,nj)){
                if(MAP[ni][nj]=='0') Q.push({q.cnt+1,ni,nj,q.b});
                else if(q.b==0) Q.push({q.cnt+1,ni,nj,1});
            }
        }
    }
    return -1;
}
int main(){
    cin.tie(NULL);ios::sync_with_stdio(false);
    cin>>N>>M;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>MAP[i][j];
    cout<<BFS();
    return 0;
}
