/*
2020-06-28 진예진
[백준 14503 로봇 청소기] https://www.acmicpc.net/problem/14503
*/
#include <stdio.h>
#include <map>
#include <queue>

using namespace std;

typedef struct Robot{
    Robot(): x(0), y(0), d(0){}
    Robot(int x, int y, int d): x(x), y(y), d(d){}
    int x, y, d;
}Robot;

int N, M, r, c, d;
int num_clean;
int space[50][50];
bool cleaned[50][50];
// 북->서, 동->북, 남->동, 서->남
map<int, int> turn_left = {{0, 3}, {1, 0}, {2, 1}, {3, 2}};
map<int, int> turn_opposite = {{0, 2}, {2, 0}, {1, 3}, {3, 1}};
// 북, 동, 남, 서
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
queue<Robot> path;

bool boundary_check(Robot coord){
    return coord.x >= 0 && coord.x < N && coord.y >= 0 && coord.y < N;
}

void clean(){
    Robot new_coord;
    Robot cur;
    bool reverse_check;

    while(!path.empty()){
        cur = path.front();
        path.pop();
        // printf("%d %d %d\n", cur.x, cur.y, cur.d);
        reverse_check = true;


        for(int i = 0; i < 4; i++){
            // 왼쪽으로 돌았을 때 방향
            int new_d = turn_left[cur.d];
            new_coord = {cur.x + dx[new_d], cur.y + dy[new_d], new_d};

            // 바운더리 넘어갈 땐 바로 컨티누
            if(boundary_check(new_coord) == false) continue;

            // 이미 청소한 곳이거나
            // 벽이면 청소할 공간이 없으므로 좌표는 그대로, 회전만 함
            // if(cleaned[new_coord.y][new_coord.x] == true
            //    || space[new_coord.y][new_coord.x] == 1){
            //     cur.d = new_d;
            // }
            // 청소함
            else{ 
                path.push(new_coord);
                // 청소 했다고 표시
                cleaned[new_coord.y][new_coord.x] = true;
                cur = new_coord;
                num_clean++;
                space[new_coord.y][new_coord.x] = num_clean;
                // printf("%d %d %d\n", new_coord.x, new_coord.y, new_coord.d);
                reverse_check = false;
            }
        }
        // 네 방향을 다 탐색해도 갈 곳이 없으면 후진 1칸
        if(reverse_check == true){
            int backward = turn_opposite[cur.d];
            // 현재 방향유지한채로 후진
            new_coord = {cur.x + dx[backward], cur.y + dy[backward], cur.d};
            if(boundary_check(new_coord) == true){
                // 빈공간이면 탐색
                if(space[new_coord.y][new_coord.x] == 0) {
                    path.push(new_coord);
                    // cleaned[new_coord.y][new_coord.x] = true;
                }
            }
        }
    }
}

int main(){
    FILE *stream = freopen("S2\\5\\input\\14503_input.txt", "r", stdin);
    if(!stream) perror("freopen");

    scanf("%d %d", &N, &M); //N: 세로, M: 가로
    scanf("%d %d %d", &r, &c, &d); // (r, c): 로봇청소기가 있는 좌표, d: 보고있는 방향
    // d: 0 북, 1 동, 2 남, 3 서

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%d", &space[i][j]);
        }
    }
    
    path.push(Robot(c, r, d));
    cleaned[r][c] = true;
    num_clean++;
    
    clean();

    printf("%d\n", num_clean);

    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < M; j++){
    //         printf("%d ", space[i][j]);
    //     }
    //     printf("\n");
    // }

    return 0;
}
