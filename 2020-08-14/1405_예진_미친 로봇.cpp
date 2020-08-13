/*
[백준 1405 미친 로봇] https://www.acmicpc.net/problem/1405
미완, 확률부분 이해 못함!
2020-08-10
*/
#include <stdio.h>
#include <string.h>
#define OFFSET 14

using namespace std;

typedef struct Coord{
    Coord(): x(x), y(0) {}
    Coord(int x, int y) : x(x), y(y) {}
    int x, y;
}Coord;

int N, success, fail; // success: 중복되는 경로 없이 N만큼 무사히 탐색한 횟수
int probability[4] = {0,};
int visited[29][29];
// 동, 서, 남, 북 순서
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool boundary_check(Coord c){
    return c.x >= (OFFSET - N) && c.x <= (OFFSET + N) && c.y >= (OFFSET - N) && c.y <= (OFFSET + N);
}

void move(Coord c, int count, bool overlap, int visited_check[][29]){
    // if(!boundary_check(c)) return;
    int &cur_visited = visited_check[c.y][c.x];
    cur_visited++;

    // 방문한 적이 있으면(중복)
    if(cur_visited > 1){  
        // unvisited(c);
        overlap = true;
        // return;
    }

    // 중복없이 N번을 탐색했을 때
    if(count >= N) {
        // 한 번이라도 중복이 없었으면, overlap == false
        if(!overlap) success ++;
        else fail++;
        if(cur_visited > 0) cur_visited--;
        return;
    }

    for(int i = 0; i < 4; i++){
        Coord n = { c.x + dx[i], c.y + dy[i] };
        move(n, count + 1, overlap, visited_check);
    }
}
    

int main(){
    FILE *stream =freopen("S2\\11\\input\\1405.txt", "r", stdin);
    if(!stream) perror("freopen");


    scanf("%d", &N);
    
    for(int i = 0; i < 4; i++){
        scanf("%d", &probability[i]);
    }

    // init
    success = 0;
    fail = 0;
    memset(visited, 0, sizeof(visited));

    move(Coord(0 + OFFSET, 0 + OFFSET), 0, false, visited);

    float a = float(12/16);
    float b = 12.343;
    printf("%.9g", float(success) / float(success + fail));
    return 0;
}
