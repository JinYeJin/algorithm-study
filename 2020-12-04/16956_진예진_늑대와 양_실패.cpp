/*
[백준 16956] https://www.acmicpc.net/problem/16956
*/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

typedef struct Coord{
    Coord(int y, int x): y(y), x(x) {}
    int x, y;
}Coord;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int farm[501][501];
int visited[501][501];


int main(){
    FILE *stream =freopen("S2\\23\\input\\16956.txt", "r", stdin);
    if(!stream) perror("freopen");

    int R, C;
    vector<Coord> wolves;

    scanf("%d %d", &R, &C);
    memset(farm, 0, sizeof(farm));
    scanf("\n");

    for(int r = 0; r < R; r++){
        for(int c = 0; c < C; c++){
            char temp;
            scanf("%c", &temp);
            if(temp == 'S') farm[r][c] = 1;
            else if(temp == 'W'){
                farm[r][c] = 2;
                wolves.push_back(Coord(r, c));
            }
            else if(temp == '.') farm[r][c] = 3;
        }
        scanf("\n");
    }


    for(auto wolf = wolves.begin(); wolf != wolves.end(); wolf++){
        for(int d = 0; d < 4; d++){                
            Coord new_path = {wolf->y + dy[d], wolf->x + dx[d]};
            int *value1 = &farm[new_path.y][new_path.x];

            // 늑대와 양이 인접해 있는 경우
            if(*value1 == 1){
                cout << 0;
                return 0;
            }
            else if(*value1 == 0){
                *value1 = -1; // 방문 표시

                for(int d2 = 0; d < 4; d++){
                    Coord new_path2 = {new_path.y + dy[d2], new_path.x + dx[d]};
                    int *value2 = & farm[new_path2.y][new_path2.x];

                    if(*value2 == 1){ // 한 번 건너 양이 있으면
                        *value1 = 3; // 벽으로 바꿈 
                    }
                }
            }
        }
    }

    cout << 1 << "\n";

    for(int r = 0; r < R; r++){
        for(int c = 0; c < C; c++){
            if(farm[r][c] == 1) cout << 'S';
            else if(farm[r][c] == 2) cout << 'W';
            else if(farm[r][c] == 3) cout << 'D';
            else cout << '.';
        }
        cout << "\n";
    }


    return 0;
}
