#include <iostream>
#include <algorithm>

using namespace std;

int R,C,N,t=1,dr[]={1,-1,0,0},dc[]={0,0,1,-1};
char board[202][202];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>R>>C>>N;
    for(int r=1;r<=R;r++){
        for(int c=1;c<=C;c++){
            cin>>board[r][c];
        }
    }
    if(N>0){
        while(1){
            if(t++==N) break;
            char pre_board[202][202];
            for(int r=1;r<=R;r++){
                for(int c=1;c<=C;c++){
                    pre_board[r][c]=board[r][c];
                    board[r][c]='O';
                }
            }
            if(t++==N) break;
            
            for(int r=1;r<=R;r++){
                for(int c=1;c<=C;c++){
                    if(pre_board[r][c]=='O'){
                        board[r][c]='.';
                        for(int d=0;d<4;d++){
                            int nr=r+dr[d],nc=c+dc[d];
                            board[nr][nc]='.';
                        }
                    }
                }
            }
        }
    }
    for(int r=1;r<=R;r++){
        for(int c=1;c<=C;c++){
            cout<<board[r][c];
        }cout<<'\n';
    }
    return 0;
}
