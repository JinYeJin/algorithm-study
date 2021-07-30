#include "bits/stdc++.h";

using namespace std;

char board[10][10];
int di[] = { 1,0,-1,0 }, dj[] = { 0,1,0,-1 },N,M,answer=11;
map<char, pair<int, int>> balls;

bool move(char ball, int dir) {
    auto ball_location = balls[ball];
    int i = ball_location.first, j = ball_location.second;
    int ni = i + di[dir], nj = j + dj[dir];

    for (; board[ni][nj] == '.'; ni += di[dir], nj += dj[dir]);

    if (board[ni][nj] == 'O') {
        board[i][j] = '.';
        return true; //도착지점!
    }
    //도착지점에서 이전에 멈추면됨.
    ni -= di[dir]; nj -= dj[dir];
    swap(board[i][j], board[ni][nj]);
    balls[ball] = { ni,nj };
    return false;
}

void dfs(int n) {
    if (n == 11) {
        return;
    }

    char copy_board[10][10];

    memcpy(copy_board, board, sizeof(board));
    auto R_location = balls['R'], B_location = balls['B'];
    for (int d = 0; d < 4; d++) {
        move('R', d);
        if (move('B', d)){
            memcpy(board, copy_board, sizeof(board));
            balls['R'] = R_location, balls['B'] = B_location;
            continue;
        }
        if (move('R', d)){
            answer=min(answer,n);
            return;
        }
        dfs(n+1);

        memcpy(board, copy_board, sizeof(board));
        balls['R']=R_location, balls['B']=B_location;
    }

    return;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            balls[board[i][j]] = { i,j };
        }
    }
    dfs(1);
    cout << (answer == 11 ? -1 : answer);
    return 0;
}
