/*
2020-06-15 진예진
[백준 14502] https://www.acmicpc.net/problem/14502
참고 https://jongnan.tistory.com/entry/%EB%B0%B1%EC%A4%80-14502-%EC%97%B0%EA%B5%AC%EC%86%8C
*/

#include <stdio.h>
#include <string.h>

using namespace std;

typedef struct Coord{
    Coord(int x, int y): x(x), y(y){};
    int x, y;
}Coord;

int N, M;
int maximum_safety_zone;
int lab[8][8];
int infected_lab[8][8];
int temp_lab[8][8];
int visited[8][8];
// 상, 우, 하, 좌
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};


bool boundary_check(Coord coord){
    if(coord.x < 0 || coord.x >= M || coord.y < 0 || coord.y >= N) return false;
    else return true;
}

int count_safety_zone(){
    int return_value = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            // 빈공간이면 카운트
            if(infected_lab[i][j] == 0) return_value++; 
        }
    }

    return return_value;
}

void spread_virus(Coord current){
    // 방문 표시
    visited[current.y][current.x] = true;
    // 현재 방문한 곳에 바이러스 표시를 한 후
    infected_lab[current.y][current.x] = 2;

    // 4 방향으로 탐색
    for(int i = 0; i < 4; i++){
        Coord new_coord = Coord(current.x + dx[i], current.y + dy[i]);

        // 범위를 벗어나거나(or) 방문한 곳이면 다음 반복문
        if(boundary_check(new_coord) == false || visited[new_coord.y][new_coord.x]) continue;
        // 빈 벽인 경우 바이러스를 퍼뜨림
        if(infected_lab[new_coord.y][new_coord.x] == 0) spread_virus(new_coord);
    }
}

void set_wall(int num_of_wall){
    // 3개의 벽을 모두 세운 경우
    if(num_of_wall >= 3){
        // 방문체크 배열 초기화
        memset(visited, false, sizeof(visited));
        
        // temp_lab의 원래상태를 바꾸면 안되기에 infected_lab에 배열 복사
        mempcpy(infected_lab, temp_lab, sizeof(temp_lab));

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                // 방문한 적이 없고, 바이러스 일 때 함수 호출
                if(visited[i][j] == false && temp_lab[i][j] == 2) spread_virus(Coord(j, i));
            }
        }

        // safety zone의 칸수 셈
        int local_safety_zone = count_safety_zone();

        // local값과 global 값을 비교해서 safety_zone의 최대값 구함
        maximum_safety_zone = maximum_safety_zone > local_safety_zone ? maximum_safety_zone : local_safety_zone;
        return;
    }


    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            // 빈공간이면 벽을 세우고 다음 벽 세우기위한 함수 호출
            if(temp_lab[i][j] == 0){
                temp_lab[i][j] = 1;
                set_wall(num_of_wall + 1);
                temp_lab[i][j] = 0;
            }
       }
    }

}


int main(){
    FILE *stream = freopen("S2\\3\\14502_input.txt", "r", stdin);
    if(!stream) perror("freopen");
    
    scanf("%d %d", &N, &M);

    // 0: 빈칸. 1: 벽, 2: 바이러스
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%d", &lab[i][j]);
        }
    }

    maximum_safety_zone = 0;


    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            // 빈공간이면 벽 세움 (이 부분 참고함!!)
            if(lab[i][j] == 0){
                memcpy(temp_lab, lab, sizeof(lab));
                temp_lab[i][j] = 1;
                set_wall(1);
                // 원래대로 돌려놓음
                temp_lab[i][j] = 0;
            }
       }
    }

    printf("%d", maximum_safety_zone);

    return 0;
}
