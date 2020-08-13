/*
[백준 6087 레이저 통신] https://www.acmicpc.net/problem/6087
미완 - 메모리 초과
*/
#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;

typedef struct Laser{
    Laser(): x(0), y(0), turn(0), direction(0) {}
    Laser(int x, int y, int turn, int d): x(x), y(y), turn(turn), direction(d) {}
    int x, y, turn, direction; // 똑같이 북동남서
}Laser;

int W, H, least_turn;
int dx[] = {0, 1, 0, -1}; // 북, 동, 남, 서
int dy[] = {-1, 0, 1, 0};
char map[101][101];
bool visited[101][101];
Laser dest;

bool boundary_check(Laser c){
    return c.x >= 0 && c.x < W && c.y >= 0 && c.y < H;
}

void lase(queue<Laser> &route){

    while(!route.empty()){
        Laser c = route.front();
        route.pop();
        visited[c.y][c.x] = true;

        for(int dir = 0; dir < 4; dir++){
            Laser n = {c.x + dx[dir], c.y + dy[dir], c.turn, dir};
            char &next = map[n.y][n.x];

            // 다음에 갈 좌표가 바운더리 밖이거나 벽이면
            if(!boundary_check(n) || next == '*' || visited[n.y][n.x]){
                continue;
            }else if(n.turn >= least_turn){ // 현재 구한 최소 턴보다 같거나 커지는 경우 탐색의 의미가 없음
                continue;
            }else if(n.x == dest.x && n.y == dest.y){ // 목적지에 도착하면
                least_turn = n.turn < least_turn ? n.turn : least_turn;
                break;
            }else{ // 위의 세가지 아니면 다음에 갈 곳 추가
                if(c.direction % 2 != n.direction % 2) n.turn++;
                route.push(n);
            }
        }
    }

}

int main(){
    FILE *stream =freopen("S2\\11\\input\\6087.txt", "r", stdin);
    if(!stream) perror("freopen");

    scanf("%d %d\n", &W, &H);

    Laser start;
    queue<Laser> route;
    bool start_switch = true;

    // input
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            scanf("%c", &map[i][j]);
            if(start_switch && map[i][j] == 'C'){
                start = {j, i, 0, 0};
                start_switch = false;
                route.push(start);
            }
            else if(!start_switch && map[i][j] == 'C') dest = {j, i, 0, 0};
        }
        scanf("\n");
    }
    
    // init
    memset(visited, 0, sizeof(visited));
    least_turn = 987654321;

    lase(route);
    printf("%d", least_turn);

    return 0;
}
