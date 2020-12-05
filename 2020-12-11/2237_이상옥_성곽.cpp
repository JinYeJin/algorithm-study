#include <iostream>
#include <algorithm>
#include <cstring>

#define check(i,j) (0<=i and i<m and 0<=j and j<n)
using namespace std;

int n,m,castle[50][50], di[]={0,-1,0,1},dj[]={-1,0,1,0}, dd[]={1,2,4,8},visited[50][50], room_area[2500]={0},room=0;

void DFS(int i,int j){
    visited[i][j]=room;
    room_area[room]++;
    for(int d=0;d<4;d++){
        int ni=i+di[d],nj=j+dj[d];
        if(!check(ni,nj) || visited[ni][nj]!=-1) continue;
        if(!(castle[i][j]&dd[d])) DFS(ni,nj);
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    
    cin>>n>>m;
    for(int i=0;i<m;i++)for(int j=0;j<n;j++)cin>>castle[i][j];
    
    memset(visited,-1,sizeof(visited));

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
            if(visited[i][j]==-1){
                DFS(i,j);
                room++;
            }
        }
    cout<<room<<'\n';
    int max_area=0;
    for(int i=0;i<room;i++) max_area=max(max_area,room_area[i]);
    cout<<max_area<<'\n';

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
            if(i>0 and visited[i-1][j]!=visited[i][j]) max_area=max(max_area,room_area[visited[i-1][j]]+room_area[visited[i][j]]);
            if(j>0 and visited[i][j-1]!=visited[i][j]) max_area=max(max_area,room_area[visited[i][j-1]]+room_area[visited[i][j]]);
        }
    cout<<max_area;
    return 0;
}
