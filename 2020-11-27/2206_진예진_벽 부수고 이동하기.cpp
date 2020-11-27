/*
[백준 2206 벽 부수고 이동하기] acmicpc.net/problem/2206
1600번과 비슷한 문제, 1600은 부술 수 있는 벽의 개수가 1개 이상임
*/
#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>
#define MAX 987654321;

using namespace std;

typedef struct Coord{
    Coord(int x, int y, int moved, bool can_break): x(x), y(y), moved(moved), can_break(can_break) {}
    int x, y, moved;
    bool can_break;
}Coord;

int N, M;
bool map[1002][1002];
// 방문체크라기보단 x, y 좌표에 왔을 때 벽을 부수고 왔는지 아닌지 여부
int visited[1002][1002];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool boundary(Coord c){
    return c.x >= 0 && c.x < M && c.y >= 0 && c.y < N;
}

int main(){
    FILE *stream =freopen("S2\\22\\input\\2206.txt", "r", stdin);
    if(!stream) perror("freopen");

    queue<Coord> q;

    scanf("%d %d", &N, &M);

    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++){
            scanf("%1d", &map[r][c]);
            visited[r][c] = -1;
        }
    }
    

    q.push(Coord(0, 0, 0, 1));
    visited[0][0] = 1;

    while(!q.empty()){
        Coord cur = q.front();
        q.pop();

        if(cur.x == M-1 && cur.y == N-1){
            printf("%d", cur.moved+1);
            return 0;
        }

        for(int d = 0; d < 4; d++){
            Coord new_c = {cur.x + dx[d], cur.y + dy[d], cur.moved+1, cur.can_break};

            if(!boundary(new_c)) continue;

            // 부실 수 있는 게 더 큰 경우에 이동
            if(new_c.can_break > visited[new_c.y][new_c.x]){
                if(map[new_c.y][new_c.x] == 1){ // 벽이 있을 때
                    if(new_c.can_break > 0){
                        new_c.can_break = 0;
                        visited[new_c.y][new_c.x] = new_c.can_break;
                        q.push(new_c);
                    }
                }
                else{
                    visited[new_c.y][new_c.x] = new_c.can_break;
                    q.push(new_c);
                }
            }
        }
    }

    printf("-1");
    return 0;
}
