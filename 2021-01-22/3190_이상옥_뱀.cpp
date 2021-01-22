#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

#define check(i,j) (0<i && i<=N && 0<j && j<=N)
using namespace std;

int N,di[]={1,0,-1,0},dj[]={0,1,0,-1},move_L[]={1,2,3,0},move_D[]={3,0,1,2};
char board[101][101];
queue<pair<int,int>> snake;
int snake_dir=1;

bool move_S(){
    auto head=snake.back();
    int ni=head.first+di[snake_dir], nj=head.second+dj[snake_dir];
    if(!check(ni,nj) || board[ni][nj]=='s'){
        return true;//벽에 부딪혔거나 꼬리먹음.
    }
    if(board[ni][nj]!='a'){
        auto tail=snake.front();snake.pop();
        board[tail.first][tail.second]='0';
    }
    snake.push({ni,nj});
    board[ni][nj]='s';
    
    return false;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>N;
    int K,a,b,L,t,time=0;
    char dir;
    memset(board,'0',sizeof(board));
    for(cin>>K;K--;){
        cin>>a>>b;
        board[a][b]='a';
    }
    snake.push({1,1});
    board[1][1]='s';
    for(cin>>L;L--;){
        cin>>t>>dir;
        while(time<t){
            time++;
            if(move_S()){
                cout<<time;
                return 0;
            }
        }        if(dir=='L') snake_dir=move_L[snake_dir];
        else snake_dir=move_D[snake_dir];
    }
    while(1){
        time++;
        if(move_S()){
            break;
        }
    }
    cout<<time;
    return 0;
}
