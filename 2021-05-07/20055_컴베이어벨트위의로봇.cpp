#include "/usr/local/include/bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    FILE *stream =freopen("/Users/sangoklee/Documents/workspace/test/test/test.txt", "r", stdin);
    if(!stream) perror("freopen");
    int I,N,board[22][22],di[]={1,-1,0,0},dj[]={0,0,1,-1};
    set<int> like[401];
    
    memset(board,-1,sizeof(board));
    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            board[i][j]=0;
        }
    }
    for(int n=0;n<N*N;n++){
        cin>>I;
        for(int d=0;d<4;d++){
            int f;
            cin>>f;
            like[I].insert(f);
        }
        pair<int,int> max_like_empty={-1,-1};
        int si,sj;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                pair<int,int> like_empty={0,0};
                if(board[i][j]==0){
                    for(int d=0;d<4;d++){
                        int ni=i+di[d],nj=j+dj[d];
                        if(board[ni][nj]==0){
                            like_empty.second++;
                        }
                        if(like[I].find(board[ni][nj])!=like[I].end()){//set 안에 있으면
                            like_empty.first++;
                        }
                    }
                    if(max_like_empty<like_empty){
                        max_like_empty=like_empty;
                        si=i, sj=j;
                    }
                }
            }
        }
        board[si][sj]=I;
    }
    int answer=0,score[]={0,1,10,100,1000};
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            int cnt=0;
            for(int d=0;d<4;d++){
                int ni=i+di[d],nj=j+dj[d];
                if(like[board[i][j]].find(board[ni][nj])!=like[board[i][j]].end()) cnt++;
            }
            answer+=score[cnt];
        }
    }
    cout<<answer;
    return 0;
}


