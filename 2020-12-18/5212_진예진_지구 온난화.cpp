#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
    FILE *stream = freopen("S2\\25\\input\\5212.txt", "r", stdin);
    if(!stream) perror("freopen");

    int R, C;
    int map[11][11];
    bool future_map[11][11];
    char temp;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {-1, 0, 1, 0};

    memset(map, 0, sizeof(map));
    memset(future_map, false, sizeof(future_map));

    cin >> R >> C;
    
    for(int r = 1; r <= R; r++){
        for(int c = 1; c <= C; c++){
            cin >> temp;
            // scanf("%c", temp);dd
            if(temp == '.') map[r][c] = 1;
            else if(temp == 'X') map[r][c] = 2;
        }
    }

    for(int r = 1; r <= R; r++){
        for(int c = 1; c <= C; c++){
            // 섬이 있으면
            if(map[r][c] == 2){
                int num_coast = 0;
                for(int d = 0; d < 4; d++){
                    if(map[r + dy[d]][c + dx[d]] == 1) num_coast++;
                }
                if(num_coast >= 3) future_map[r][c] = true;
            }
        }
    }

    int min_r, min_c, max_r, max_c;

    min_r = min_c = 11;
    max_r = max_c = 0;

    for(int r = 0; r <= R; r++){
        for(int c = 0; c <= C; c++){
            if(future_map[r][c]){
                min_r = r < min_r ? r : min_r;
                min_c = c < min_c ? c : min_c;
                max_r = r > max_r ? r : max_r;
                max_c = c > max_c ? c : max_c;
            }
        }
    }

    for(int r = min_r; r <= max_r; r++){
        for(int c = min_c; c <= max_c; c++){
            if(future_map[r][c]) printf("X");
            else printf(".");
        }
    }

    return 0;
}
