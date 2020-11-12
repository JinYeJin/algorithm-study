#include <iostream>
#include <string.h>

#define check(r,c) (0<=r && r<R+2 && 0<=c && c<C+2)
using namespace std;

int R,C,map[102][102]={0,},T=0,cheese=0,pre_cheese, dr[]={1,-1,0,0}, dc[]={0,0,1,-1};
bool visited[102][102];
void DFS(int r, int c){
    if(visited[r][c]) return;
    visited[r][c]=1;
    if(map[r][c]>0){
        map[r][c]=0;
        cheese--;
        return;
    }
    for(int d=0;d<4;d++){
        int nr=r+dr[d], nc=c+dc[d];
        if(check(nr, nc)) DFS(nr,nc);
    }
}
int main(){
    cin.tie(NULL);ios::sync_with_stdio(false);
    cin>>R>>C;
    for(int i=1;i<=R;i++)
        for(int j=1;j<=C;j++){
            cin>>map[i][j];
            if(map[i][j]==1) cheese++;
        }
    for(;cheese;T++){
        pre_cheese=cheese;
        memset(visited,0,sizeof(visited));
        DFS(0,0);
    }
    cout<<T<<'\n';
    cout<<pre_cheese;
    return 0;
}
