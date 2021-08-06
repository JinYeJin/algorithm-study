#include "bits/stdc++.h";

#define check(i,j) (0<=i && i<N && 0<=j && j<M)
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N,M,r,c,d,dr[]={-1,0,1,0}, dc[]={0,1,0,-1},answer=0;
    int board[50][50];
    cin>>N>>M;
    cin>>r>>c>>d;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin>>board[i][j];
        }
    }

    while(1){
        if(board[r][c]==0){
            board[r][c]=2; //1. 현재 위치를 청소한다.
            answer++;
        }
        int k=0;
        for (; k<4; k++) { //2. 현재위치기준 왼쪽(K) 부터 차례대로 탐색
            d=(d+3)%4; //a, b. 방향 회전
            int nr= r+dr[d], nc= c+dc[d];
            if(!check(nr,nc)) continue;
            if (board[nr][nc] == 0) { //a. 청소할 공간이 있다면,
                r=nr; c=nc;
                break;
            }
        }
        if(k<4) continue; //c, d. 네방향 중 하나를 청소함.

        int nr = r-dr[d], nc=c-dc[d];
        if(!check(nr,nc)) break; //크기가 넘어갈떄
        if(board[nr][nc]==1) break; //d. 돌아가는 곳이 벽일때.
        r=nr; c=nc;
    }

    cout<<answer;

    return 0;
}
