/*
[2468] www.acmicpc.net/problem/2468
*/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

typedef struct Coord{
    Coord(int x, int y): x(x), y(y) {}
    int x, y;
}Coord;

int N;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int area[101][101];
int area_copy[101][101];

bool boundary_check(Coord cur){
    return cur.x >= 0 && cur.x < N && cur.y >= 0 && cur.y < N;
}

void count_safty_zone(Coord cur, int threshold){
    if(!boundary_check(cur)) return;
    area[cur.y][cur.x] = -1;

    for(int d = 0; d < 4; d++){
        Coord next = {cur.x + dx[d], cur.y + dy[d]};

        if(area[next.y][next.x] > threshold){
            count_safty_zone(next, threshold);
        }
    }
}

int main(){
    // FILE *stream =freopen("S2\\17\\input\\2468.txt", "r", stdin);
    FILE *stream =freopen("S2/17/input/2468.txt", "r", stdin);
    if(!stream) perror("freopen");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int max_level = -1;
    int safty_level = 0;
    int num_safty_zone = 0;
    int max_safty_zone = 1;

    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> area[i][j];
            area_copy[i][j] = area[i][j];
            if(area[i][j] > max_level) max_level = area[i][j];
        }
    }

    for(int threshold = 1; threshold <= max_level; threshold++){
        num_safty_zone = 0;
        memcpy(area, area_copy, sizeof(area));
        
        for(int y = 0; y < N; y++){
            for(int x = 0; x < N; x++){
                if(area[y][x] > threshold){
                    count_safty_zone(Coord(x, y), threshold);
                    num_safty_zone++;
                }
            }
        }
        if(num_safty_zone > max_safty_zone) max_safty_zone = num_safty_zone; 
    }

    cout << max_safty_zone;

    return 0;
}
