/*
1261 알고스팟
*/
#include <stdio.h>
#include <iostream>
#include <queue>
#define MAX 987654321

using namespace std;

int M, N;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dp[101][101];
int map[101][101];
int answer = MAX;

typedef struct Coord{
    Coord(int x, int y): x(x), y(y) {}
    int x, y;
}Coord;

bool boundary(Coord c){
    return c.x > 0 && c.x <= M && c.y > 0 && c.x <= N;
}


int main(){
    FILE *stream = freopen("S2\\31\\input\\1261.txt", "r", stdin);
    if(!stream) perror("freopen");
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);



    // cin >> M >> N; // 가로 세로
    scanf("%d %d", &M, &N);

    for(int r = 1; r <= M; r++){
        for(int c = 1; c <= N; c++){
            int temp;
            scanf("%1d", &map[r][c]);
            dp[r][c] = -1;
        }
    }

    queue<Coord> path;

    path.push(Coord(1, 1));
    dp[1][1] = 0;

    while(!path.empty()){
        Coord cur = path.front();
        path.pop();

        int *c = &dp[cur.y][cur.x];

        // 목적지 도착
        if(cur.y == M && cur.x == N){
            if(answer > *c) answer = *c;
        }

        for(int d = 0; d < 4; d++){
            Coord next = {cur.x + dx[d], cur.y + dy[d]};

            if(!boundary(next)) continue;
            if(dp[next.y][next.x] =! MAX) continue;

            int *n = &dp[next.y][next.x];


            // 방문 체크
            if(*c > *n){
                path.push(next);
                *n = map[next.y][next.x] == 1? *n + 1 : *n;

            }
        }
    }

    // cout << answer;
    printf("%d", answer);

    return 0;
}
