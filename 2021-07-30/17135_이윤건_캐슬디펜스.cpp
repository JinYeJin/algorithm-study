#include "bits/stdc++.h";

using namespace std;

#define check(i,j) (0<=i && i<N && 0<=j && j<M)

int N,M,D,copy_board[15][15],turn,cnt;

void find_target(int i,int j, int d) {
    queue<pair<int,int>> Q;
    bool visited[15][15]={0};
    int size;
    Q.push({i,j});
    while(size=Q.size()){
        if (d-- == 0) return;
        while (size--) {
            auto q=Q.front(); Q.pop();
            int i=q.first, j=q.second;
            visited[i][j]=1;
            if (copy_board[i][j] == 1){
                copy_board[i][j]=turn;
                cnt++;
                return;
            }
            if(copy_board[i][j]==turn) return;
            if(check(i, j-1) && !visited[i][j-1]) Q.push({i,j-1});
            if(check(i-1, j) && !visited[i-1][j]) Q.push({i-1,j});
            if(check(i, j+1) && !visited[i][j+1]) Q.push({i,j+1});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>>N>>M>>D;
    
    int board[15][15]={0};
    for (int i=0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin>>board[i][j];
        }
    }
    int answer=0;
    for (int j1 = 0; j1 < M; j1++) {
        for (int j2 = j1 + 1; j2 < M; j2++) {
            for (int j3 = j2 + 1; j3 < M; j3++) {
                turn = -1;
                cnt=0;
                memcpy(copy_board,board,sizeof(board));
                for (int i = N; i > 0; i--) {
                    find_target(i-1,j1,D);
                    find_target(i-1,j2,D);
                    find_target(i-1,j3,D);
                    turn--;
                }
                answer=max(answer,cnt);
            }
        }
    }

    cout<<answer;

    return 0;
}
