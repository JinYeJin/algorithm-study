#include <string>
#include <vector>
#include <queue>
#include <set>

#define X first
#define Y second
#define check(i,j) (0<=i && i<4 && 0<=j && j<4)
using namespace std;
int di[]={1,-1,0,0}, dj[]={0,0,1,-1},N;
vector<int> pair_location;
vector<pair<int,int>> card_location;
vector<vector<int>> g_board;
bool visited[12]={0};

int bfs(pair<int,int> s, pair<int,int> e){
    bool visited[4][4]={0};
    queue<pair<int,int>> Q;
    Q.push(s);
    visited[s.X][s.Y]=1;
    int cnt=0;
    while(Q.size()){
        int size=Q.size();
        while(size--){
            auto q=Q.front();Q.pop();
            if(q==e) return cnt;
            for(int d=0;d<4;d++){
                int ni=q.X+di[d], nj=q.Y+dj[d];
                if(check(ni,nj)){
                    if(!visited[ni][nj]){
                        visited[ni][nj]=1;
                        Q.push({ni,nj});
                    }
                    for(;g_board[ni][nj]==0&&check(ni+di[d],nj+dj[d]);
                        ni+=di[d], nj+=dj[d]);
                    if(!visited[ni][nj]){
                        visited[ni][nj]=1;
                        Q.push({ni,nj});
                    }
                }
            }
        }
        cnt++;
    }

}
int dfs(pair<int,int> now,int num){
    if(num==0) return 0;
    num-=2;
    int answer=987654321;
    for(int i=0;i<N;i++){
        if(!visited[i]){
            int cnt=0,card=g_board[card_location[i].X][card_location[i].Y];
            cnt+=bfs(now, card_location[i])+1;
            visited[i]=1;
            g_board[card_location[i].X][card_location[i].Y]=0;

            int j=pair_location[i];
            cnt+=bfs(card_location[i],card_location[j])+1;
            visited[j]=1;
            g_board[card_location[j].X][card_location[j].Y]=0;

            cnt+=dfs(card_location[j],num);

            visited[i]=0;
            g_board[card_location[i].X][card_location[i].Y]=card;
            visited[j]=0;
            g_board[card_location[j].X][card_location[j].Y]=card;
            answer=min(answer, cnt);
        }
    }
    return answer;
}
int solution(vector<vector<int>> board, int r, int c) {
    g_board=board;
    int answer = 0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(board[i][j]!=0){
                card_location.push_back({i,j});
            }
        }
    }
    N=card_location.size();
    pair_location.resize(N);
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(board[card_location[i].X][card_location[i].Y]==
               board[card_location[j].X][card_location[j].Y]){
                pair_location[i]=j;
                pair_location[j]=i;
            }
        }
    }
    return dfs({r,c},N);
}
