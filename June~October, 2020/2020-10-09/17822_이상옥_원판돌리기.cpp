#include <iostream>

using namespace std;

int N,M,T,x,d,k,board[50][50],state[50]={0};
bool del[50][50]={0};

int get_point(){
    int answer=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(!del[i][j]) answer+=board[i][j];
    return answer;
}
void rotate_board(){
    if(d) for(int i=x;i<=N;i+=x) state[i-1]=(state[i-1]+k)%M;
    else for(int i=x;i<=N;i+=x) state[i-1]=(state[i-1]+M-k)%M;
    bool check=1;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(!del[i][j]){
                if(!(board[i][(j-1+M)%M]!=board[i][j] and
                   board[i][(j+1)%M]!=board[i][j] and
                   (i<=0 or board[i-1][(j+state[i-1]-state[i]+M)%M]!=board[i][j]) and
                   (i+1>=N or board[i+1][(j+state[i+1]-state[i]+M)%M]!=board[i][j]))){
                    del[i][j]=1;
                    check=0;
                }
            }
        }
    }
    if(check){
        float avg=0;
        int cnt=0;
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                if(!del[i][j]){
                    avg+=board[i][j];
                    cnt++;
                }
        if(cnt==0) return;
        avg/=cnt;
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                board[i][j]+=(board[i][j]<avg)-(board[i][j]>avg);
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(del[i][j]) board[i][j]=0;
}
int main(){
    cin.tie(NULL);ios::sync_with_stdio(false);
    cin>>N>>M>>T;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>board[i][j];
    while(T--){
        cin>>x>>d>>k;
        rotate_board();
    }
    cout<<get_point();
    return 0;
}
