/*
2020-06-16 진예진
[백준 7576] https://www.acmicpc.net/problem/7576
*/

#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;

typedef struct Coord{
    Coord(int x, int y): x(x), y(y){};
    int x, y;
}Coord;

int M, N;
int days;
int warehouse[1000][1000];
bool visited[1000][1000];
queue<Coord> tomatos;
// 상, 우, 하, 좌
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

bool boundary_check(Coord coord){
    // 가로 M 세로 N 헷갈리지 않기...씁
    if(coord.x < 0 || coord.x >= M || coord.y < 0 || coord.y >= N){
        return false;
    }
    else return true;
}

void ripe_tomato(){
    queue<Coord> temp_tomatos;

    // tomatos의 내용을 temp_tomatos로 다 옮김
    while(!tomatos.empty()){
        temp_tomatos.push(tomatos.front());
        tomatos.pop();
    }

    while(!temp_tomatos.empty()){
        Coord cur_tomato = temp_tomatos.front();
        temp_tomatos.pop();
        
        for(int i = 0; i < 4; i++){
            Coord new_tomato = {cur_tomato.x + dx[i], cur_tomato.y + dy[i]};

            // 범위를 벗어났거나 방문한 적이 있거나 토마토가 없을 때 다음 반복문
            if(boundary_check(new_tomato) == false 
            || visited[new_tomato.y][new_tomato.x] == true
            || warehouse[new_tomato.y][new_tomato.x] == -1) continue;

            // 다음 토마토가 익지 않았으면
            if(warehouse[new_tomato.y][new_tomato.x] == 0){
                tomatos.push(new_tomato);

                // 익었당~
                warehouse[new_tomato.y][new_tomato.x] = 1;
                visited[new_tomato.y][new_tomato.x] = true;
            }
        }
        
    }
}

int main(){
    FILE *stream = freopen("S2\\3\\7576_input.txt", "r", stdin);
    if(!stream) perror("freopen");

    // 가로 세로
    scanf("%d %d", &M, &N);

    int num_ripe_tomatos = 0;
    int empty = 0;

    // 1: 익은 토마토, 0: 익지 않은 토마토, -1: 토마토 없음
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%d", &warehouse[i][j]);
            // 익은 토마토면 큐에 넣음
            if(warehouse[i][j] == 1){
                tomatos.push(Coord(j, i));
                num_ripe_tomatos++;
            }
            // 토마토 없는 경우도 세줌
            else if(warehouse[i][j] == -1)
                empty++;
        }
    }

    // 모든 토마토가 익어있는 상태: 0, 예외처리, 탐색 들어가기 전에 해줌
    if(num_ripe_tomatos == N * M - empty){
        printf("0");
        return 0;
    }

    // 토마토가 다 익기까지의 날짜
    days = -1; // day 0에도 ++가 동작하므로 -1 부터 시작
    memset(visited, false, sizeof(visited));

    // BFS 시작
    while(!tomatos.empty()){
        ripe_tomato();
        days++;
    }

    num_ripe_tomatos = 0;
    
    // 모든 토마토가 익었는지 검사
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            // 익은 토마토이거나 토마토가 없는 경우를 셈
            if(warehouse[i][j] == 1 || warehouse[i][j] == -1) num_ripe_tomatos++;
        }
    }

    // 모든 토마토가 익었으면 익을 때 필요한 날짜 출력
    if(num_ripe_tomatos >= N * M) printf("%d", days);

    // 안익은 토마토가 있는 상태: -1
    else printf("%d", -1);

    return 0;
}
