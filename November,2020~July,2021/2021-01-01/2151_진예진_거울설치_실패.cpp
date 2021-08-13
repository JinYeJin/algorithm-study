/*
[2151 거울설치]
*/
#include <stdio.h>
#include <iostream> 
#include <queue>
#include <string.h>
#define MAX 987654321;

using namespace std;

typedef struct Coord{
    Coord(): x(0), y(0), d(0), num_mirror(0) {}
    Coord(int x, int y, int d, int num_mirror): x(x), y(y), d(d), num_mirror(num_mirror) {}
    int x, y, d, num_mirror;
}Coord;

int N;

int set_direction(int x, int y){
    if(y == N-1) return 0; // 북
    else if(x == 0) return 1; // 동
    else if(y == 0) return 2; // 남
    else if(x == N-1) return 3; // 서
    return 0;
}

bool is_same_coord(Coord a, Coord b){
    return (a.x == b.x) && (a.y == b.y);
}

int main(){
    FILE *stream =freopen("S2\\27\\input\\2151.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int min_mirror = MAX;
    char room[50][50];
    bool visited[50][50];
    // 0 북, 1 동, 2 남, 3 서
    int change_dir[][2] = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    int dx[] = {0, 1, 0, -1};
    int dy[] = {-1, 0, 1, 0};
    queue<Coord> path;
    Coord door1, door2;

    bool is_first = true;
    memset(visited, false, sizeof(visited)); 
    cin >> N;
    
    for(int i = 0; i < N; i++)
        cin >> room[i];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(room[i][j] == '#'){
                if(is_first){
                    door1 = {j, i, set_direction(j, i), 0};
                    is_first = false;
                }
                else door2 = {j, i, set_direction(j, i), 0};
            }
        }
    }

    path.push(door1);

    while(!path.empty()){
        Coord c = path.front();
        path.pop();

        // 범위를 벗어난 경우
        if(room[c.y][c.x] == '*') continue;
        // 도착한 경우
        if(is_same_coord(door2, c)){
            min_mirror = min_mirror > c.num_mirror ? c.num_mirror : min_mirror;
            break;
        }

        Coord new_c = c;

        // 방향 안바꾸고 전진
        new_c.x += dx[new_c.d];
        new_c.y += dy[new_c.d];
        if(!visited[new_c.y][new_c.x]){
            visited[new_c.y][new_c.x] = true;
            path.push(new_c);
        }

        if(room[c.y][c.x] == '!'){
            for(int i = 0; i < 2; i++){
                new_c = c;
                // 방향 바꾸고 전진(거울을 놓음)
                new_c.d = change_dir[c.d][i];
                new_c.x += dx[new_c.d];
                new_c.y += dy[new_c.d];
                new_c.num_mirror++;
                if(!visited[new_c.y][new_c.x]){
                    visited[new_c.y][new_c.x] = true;
                    path.push(new_c);
                }

            }
        }

    }

    cout << min_mirror;
    return 0;
}
