#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;


int N,di[2][2]={{1,-1},{0,0}},dj[2][2]={{0,0},{1,-1}};
bool visited[2][52][52]={0};
char board[52][52];
queue<pair<pair<int,int>,pair<int,int>>> Q;

int BFS(int si,int sj){
    Q.push({{0,0},{si,sj}});//cnt,dir,i,j
    Q.push({{0,1},{si,sj}});

    while(Q.size()){
        auto q=Q.front();Q.pop();
        int cnt=q.first.first,dir=q.first.second,i=q.second.first,j=q.second.second;

        if(visited[1-dir][i][j]){
            continue;
        }
        visited[1-dir][i][j]=1;
        for(int d=0;d<2;d++){
            int ni=i,nj=j;
            while(1){
                ni+=di[1-dir][d],nj+=dj[1-dir][d];
                if(board[ni][nj]=='*'){
                    break;
                }
                if(board[ni][nj]=='#'){
                    return cnt;
                }
                if(board[ni][nj]=='!'){
                    Q.push({{cnt+1,1-dir},{ni,nj}});
                }
                visited[1-dir][ni][nj]=1;
            }
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int si,sj;
    cin>>N;
    memset(board,'*',sizeof(board));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>board[i][j];
            if(board[i][j]=='#'){
                si=i,sj=j;
            }
        }
    }
    cout<<BFS(si,sj);

    return 0;
}
