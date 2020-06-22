/*
2020-05-17 진예진
[백준 7569] https://www.acmicpc.net/problem/7569
*/

#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;

typedef struct Coord{
    Coord(int x, int y, int h): x(x), y(y), h(h) {};
    int x, y, h;
}Coord;

int M, N, H;
int days;
int warehouse[100][100][100];
bool visited[100][100][100];
queue<Coord> tomatos;
// 뒤, 오른쪽, 앞, 왼쪽, 위, 아래,
int dx[] = {0, 1, 0, -1, 0, 0};
int dy[] = {-1, 0, 1, 0, 0, 0};
int dh[] = {0, 0, 0, 0, -1, 1};

bool boundary_check(Coord coord){
    if(coord.x < 0 || coord.x >= M || coord.y < 0 || coord.y >= N || coord.h < 0 || coord.h >= H) return false;
    else return true;
}

void ripe_tomato(){
    queue<Coord> temp_tomatos;

    while(!tomatos.empty()){
        temp_tomatos.push(tomatos.front());
        tomatos.pop();
    }

    while(!temp_tomatos.empty()){
        Coord tomato = temp_tomatos.front();
        temp_tomatos.pop();

        for(int i = 0; i < 6; i++){
            Coord new_location = {tomato.x + dx[i], tomato.y + dy[i], tomato.h + dh[i]};
            // 넘길어서 포인터만듬
            int *new_tomato = &warehouse[new_location.h][new_location.y][new_location.x];
            bool *visit_check = &visited[new_location.h][new_location.y][new_location.x];

            // 바운더리 벗어나거나 방문한 곳 이거나, 토마토가 없으면 패쑤
            if(boundary_check(new_location) == false 
              || *visit_check == true
              || *new_tomato == -1) continue;
            
            // 다음 도마도가 안 익었으면 큐에 푸쉬
            if(*new_tomato == 0){
                tomatos.push(new_location);
                *new_tomato = 1;
                *visit_check = true;
            }
        }
    }
}

int main(){
    FILE *stream = freopen("S2\\3\\7569_input.txt", "r", stdin);
    if(!stream) perror("freopen");

    // M: 가로(x), N: 세로(y), H: 높이(h) 
    scanf("%d %d %d", &M, &N, &H);

    int num_of_ripe_tomato = 0; 
    int empty = 0;

    for(int i = 0; i < H; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
                scanf("%d", &warehouse[i][j][k]);
                // 1: 익은 토마토, 0: 익지 않은 토마토, -1: 토마토가 들어있지 않음
                if(warehouse[i][j][k] ==  1){
                    num_of_ripe_tomato++;
                    // x, y, h 순서주의
                    tomatos.push(Coord(k, j, i));
                }
                else if(warehouse[i][j][k] == - 1){
                    empty++;
                }
            }
        }
    }

    // 토마토가 이미 모두 익어있는 경우 예외처리
    if(num_of_ripe_tomato == H * N * M - empty){
        // 0 출력하고 프로그램 종료
        printf("0");
        return 0;
    }

    memset(visited, false, sizeof(visited));
    days = -1;

    while(!tomatos.empty()){
        ripe_tomato();
        days++;
    }

    num_of_ripe_tomato = 0;
    empty = 0;

    for(int i = 0; i < H; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
                if(warehouse[i][j][k] == 1) num_of_ripe_tomato++;
                else if(warehouse[i][j][k] == -1) empty++;
            }
        }
    }

    // 토마토가 전부 이그면 날짜출력
    if((num_of_ripe_tomato + empty) >= H * N * M) printf("%d", days);
    // 하나라도 안 익은 토마토가 있으면 -1
    else printf("%d", -1);

    return 0;
}
