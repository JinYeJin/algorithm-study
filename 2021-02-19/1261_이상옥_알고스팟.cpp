#include <stdio.h>
#include <queue>

#define check(n,m) (0<n && n<=N && 0<m && m<=M)
using namespace std;

int N, M, map[101][101],answer=0, dn[]={1,0,-1,0}, dm[]={0,1,0,-1};
bool visited[101][101]={0};
queue<pair<int,int>> Q[2];
void BFS(){
    while(Q[answer&1].size()){
        auto q=Q[answer&1].front();Q[answer&1].pop();
        for(int d=0;d<4;d++){
            int nn=q.first+dn[d], nm=q.second+dm[d];
            if(check(nn,nm) and !visited[nn][nm]){
                visited[nn][nm]=1;
                if(map[nn][nm]) Q[~answer&1].push({nn,nm});
                else Q[answer&1].push({nn,nm});
            }
        }
    }
}
int main(){
    scanf("%d%d",&M, &N);
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            scanf("%1d", map[i]+j);
    Q[0].push({1,1});
    visited[1][1]=1;
    while(1){
        BFS();
        if(visited[N][M]) break;
        answer++;
    }
    printf("%d",answer);
    return 0;
}
