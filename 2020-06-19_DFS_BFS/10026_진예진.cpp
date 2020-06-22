/*
2020-06-16 진예진
[백준 10026] https://www.acmicpc.net/problem/10026
*/

#include <stdio.h>
#include <queue>
#include <string.h>
// #include <cstring>
#include <iostream>

using namespace std;

typedef struct Coord{
    Coord(int x, int y): x(x), y(y) {};
    int x, y;
}Coord;

int N;
int num_of_group;
char temp;
queue<Coord> searching;
char original_picture[100][100];
char blindness_picture[100][100];
bool visited[100][100];
// 상, 우, 하, 좌
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

bool boundary_check(Coord coord){
    if(coord.x < 0 || coord.x >= N || coord.y < 0 || coord.y >= N) return false;
    else return true;
}


// BFS
void grouping(char picture[][100], Coord start){
    searching.push(start);
    visited[start.y][start.x] = true;
    char *start_char = &picture[start.y][start.x];

    while(!searching.empty()){
        Coord current = searching.front();
        searching.pop();

        // 상 우 하 좌 탐색
        for(int i = 0; i < 4; i++){
            Coord next = {current.x + dx[i], current.y + dy[i]};

            // 바운더리를 넘어가거나 방문한 적이 있으면 다음으로 넘어감
            // printf("%s ", boundary_check(next)? "true" : "false");
            // printf("%s\n", visited[next.y][next.x]? "true" : "false");
            if((boundary_check(next) == false) || (visited[next.y][next.x] == true)) continue;

            // 새로운 좌표의 문자가 그루핑 하고 있는 문자와 같으면 큐에 넣음
            if(*start_char == picture[next.y][next.x]){
                searching.push(next);
                visited[next.y][next.x] = true;
            }
        }
    }

}

int main(){
    FILE *stream = freopen("S2\\3\\10026_input.txt", "r", stdin);
    if(!stream) perror("freopen");

    scanf("%d", &N);
    // 개행 넘기기
    getchar();

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%1c", &temp);
            original_picture[i][j] = temp;
            // G를 모두 R로 바꿈
            if(temp == 'G') blindness_picture[i][j] = 'R';
            else blindness_picture[i][j] = temp;
        }
        // 여기도 개행 주의
        getchar();
    }

    num_of_group = 0;
    memset(visited, false, sizeof(visited));

    // 정상인
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            // 방문한 적이 없으면 그루핑 시작
            if(visited[i][j] == false){
                grouping(original_picture, Coord(j, i));
                // 그루핑 한 번이 끝나면 그룹개수 하나 증가
                num_of_group++;
            }
        }
    }

    // 정상일 때 그룹개수 출력
    printf("%d ", num_of_group);

    // init
    num_of_group = 0;
    memset(visited, false, sizeof(visited));

    // 적녹색맹
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(visited[i][j] == false){
                grouping(blindness_picture, Coord(j, i));
                num_of_group++;
            }
        }
    }

    // 색맹일 때 그룹개수 출력
    printf("%d", num_of_group);

    return 0;
}
