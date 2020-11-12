/*
[백준 1103 게임] https://www.acmicpc.net/problem/1103
참고 https://lcs11244.tistory.com/63
*/

#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

typedef struct Coord{
    Coord(): x(0), y(0) {}
    Coord(int x, int y): x(x), y(y) {}
    int x, y;
}Coord;

int N, M, max_move;
int board[51][51];
int dp[51][51];
bool visited[51][51];
// 상, 우, 하, 좌
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

bool boundary_check(Coord coord){
    return coord.x >= 0 && coord.x < M && coord.y >= 0 && coord.y < N; }

int dfs(Coord cur){
    // 바운더리를 벗어나면 아무움직임도 하지 않은 것과 같으므로 0 return
    if(boundary_check(cur) == false) return 0;
    // 사이클 체크, 한번이라도 방문한 곳에 돌아오면 사이클이 생긴다.
    if(visited[cur.y][cur.x] == true) {printf("-1"); exit(0);}
    // dp 값이 저장되어있으면, dp 값을 그대로 리턴해서 불필요한 계산을 줄인다.
    if(dp[cur.y][cur.x] != -1) return dp[cur.y][cur.x];
    // 방문체크
    visited[cur.y][cur.x] = true;
    // dp는 왜 0으로 초기화해주는거지?!
    dp[cur.y][cur.x] = 0;
    // max_move =  count_move > max_move ? count_move : max_move;

    Coord next;

    // 4 방향으로 탐색
    for(int i = 0; i < 4; i++){
        next = {cur.x + board[cur.y][cur.x] * dx[i], cur.y + board[cur.y][cur.x] * dy[i]};
        // 왜 + 1을 해주는가?!?!
        dp[cur.y][cur.x] = max(dp[cur.y][cur.x], dfs(next) + 1);
    }
    visited[cur.y][cur.x] = false;
    return dp[cur.y][cur.x];
}

int main(){
    FILE *stream =freopen("S2\\10\\input\\1103.txt", "r", stdin);
    if(!stream) perror("freopen");


    scanf("%d %d", &N, &M);
    getchar();

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            char temp;
            scanf("%c", &temp);
            // 구멍은 아무곳으로도 갈 수 없다는 것과 같으므로 0 으로 초기화
            if(temp == 'H') board[i][j] = 0;
            else board[i][j] = temp - '0';
        }
        getchar();
    }

    memset(dp, -1, sizeof(dp));
    memset(visited, false, sizeof(visited));

    printf("%d", dfs(Coord(0, 0)));
    return 0;
}
