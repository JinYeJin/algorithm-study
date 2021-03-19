#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N,M,zero=0,answer;
char board[10][10];
int di[4]={1,0,-1,0},dj[4]={0,1,0,-1};

vector<pair<int,int>> cctvs;

void DFS(int cctv){
    if(cctv==cctvs.size()){
        answer=min(answer,zero);
        return;
    }
    char copy_board[10][10];
    int copy_zero=zero;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            copy_board[i][j]=board[i][j];
        }
    }
    int i=cctvs[cctv].first,j=cctvs[cctv].second,ni,nj;
    char kind=board[i][j];
    if(kind=='1'){
        for(int d=0;d<4;d++){
            ni=i+di[d],nj=j+dj[d];
            while(board[ni][nj]!='6'){
                if(board[ni][nj]=='0'){
                    board[ni][nj]='#';
                    zero--;
                }
                ni+=di[d],nj+=dj[d];
            }
            DFS(cctv+1);
            
            zero=copy_zero;
            for(int i=1;i<=N;i++){
                for(int j=1;j<=M;j++){
                    board[i][j]=copy_board[i][j];
                }
            }
        }
    }else if(kind=='2'){
        for(int d=0;d<2;d++){
            ni=i+di[d],nj=j+dj[d];
            while(board[ni][nj]!='6'){
                if(board[ni][nj]=='0'){
                    board[ni][nj]='#';
                    zero--;
                }
                ni+=di[d],nj+=dj[d];
            }
            ni=i-di[d],nj=j-dj[d];
            while(board[ni][nj]!='6'){
                if(board[ni][nj]=='0'){
                    board[ni][nj]='#';
                    zero--;
                }
                ni-=di[d],nj-=dj[d];
            }
            
            DFS(cctv+1);

            zero=copy_zero;
            for(int i=1;i<=N;i++){
                for(int j=1;j<=M;j++){
                    board[i][j]=copy_board[i][j];
                }
            }
        }
        
    }else if(kind=='3'){
        for(int d=0;d<4;d++){
            for(int n=0;n<2;n++){
                ni=i+di[(d+n)%4],nj=j+dj[(d+n)%4];
                while(board[ni][nj]!='6'){
                    if(board[ni][nj]=='0'){
                        board[ni][nj]='#';
                        zero--;
                    }
                    ni+=di[(d+n)%4],nj+=dj[(d+n)%4];
                }
            }
            DFS(cctv+1);

            zero=copy_zero;
            for(int i=1;i<=N;i++){
                for(int j=1;j<=M;j++){
                    board[i][j]=copy_board[i][j];
                }
            }
        }
        
    }else if(kind=='4'){
        int di[4]={1,0,-1,0},dj[4]={0,1,0,-1};
        for(int d=0;d<4;d++){
            for(int n=0;n<3;n++){
                ni=i+di[(d+n)%4],nj=j+dj[(d+n)%4];
                while(board[ni][nj]!='6'){
                    if(board[ni][nj]=='0'){
                        board[ni][nj]='#';
                        zero--;
                    }
                    ni+=di[(d+n)%4],nj+=dj[(d+n)%4];
                }
            }
            DFS(cctv+1);

            zero=copy_zero;
            for(int i=1;i<=N;i++){
                for(int j=1;j<=M;j++){
                    board[i][j]=copy_board[i][j];
                }
            }
        }
    }else if(kind=='5'){
        int di[4]={1,0,-1,0},dj[4]={0,1,0,-1};
        for(int d=0;d<4;d++){
            ni=i+di[d],nj=j+dj[d];
            while(board[ni][nj]!='6'){
                if(board[ni][nj]=='0'){
                    board[ni][nj]='#';
                    zero--;
                }
                ni+=di[d],nj+=dj[d];
            }
        }
        
        DFS(cctv+1);
        zero=copy_zero;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                board[i][j]=copy_board[i][j];
            }
        }
    }
    
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            board[i][j]='6';
        }
    }
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>board[i][j];
            if(board[i][j]=='0'){
                zero++;
            }else if(board[i][j]!='6'){
                cctvs.push_back({i,j});
            }
        }
    }
    answer=zero;
    DFS(0);
    cout<<answer;
    return 0;
}


