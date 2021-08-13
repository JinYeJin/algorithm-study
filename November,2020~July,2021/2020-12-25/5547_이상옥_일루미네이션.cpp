#include <iostream>
#include <algorithm>

#define check(i,j) (0<=i && i<H+2 && 0<=j && j<W+2)
using namespace std;

int W,H,board[102][102]={0}, di[6]={1,1,0,0,-1,-1}, dj[2][6]={{-1,0,-1,1,-1,0},{0,1,-1,1,0,1}},answer=0;

void DFS(int i,int j){
    board[i][j]=2;
    for(int d=0;d<6;d++){
        int ni=i+di[d], nj=j+dj[i&1][d];
        if(check(ni,nj)){
            if(board[ni][nj]==0){
                DFS(ni,nj);
            }
            else if(board[ni][nj]==1){
                answer++;
            }
        }
    }
}
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    cin>>W>>H;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            cin>>board[i][j];
        }
    }
    DFS(0,0);
    cout<<answer;
    return 0;
}


