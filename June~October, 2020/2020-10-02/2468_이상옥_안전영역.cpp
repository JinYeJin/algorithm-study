#include <iostream>
#include <string.h>
#include <algorithm>

#define check(i,j) (0<=i and i<N and 0<=j and j<N)
using namespace std;

bool visited[100][100];
int N,map[100][100],H,max_area=1, di[]={1,-1,0,0}, dj[]={0,0,1,-1};


void DFS(int i,int j){
    if(visited[i][j]) return;
    visited[i][j]=1;
    for(int d=0;d<4;d++){
        int ni=i+di[d],nj=j+dj[d];
        if(check(ni,nj) and map[ni][nj]>H) DFS(ni,nj);
    }
}

int get_area(){
    int area=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            if(visited[i][j]) continue;
            if(map[i][j]>H){
                area++;
                DFS(i,j);
            }
        }
    return area;
}
int main(){
    cin.tie(NULL);ios::sync_with_stdio(false);
    cin>>N;
    
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>map[i][j];
    
    for(H=1;H<100;H++){
        memset(visited,0,sizeof(visited));
        int area=get_area();
        if(area==0) break;
        max_area=max(max_area,area);
    }
    cout<<max_area;
    return 0;
}

