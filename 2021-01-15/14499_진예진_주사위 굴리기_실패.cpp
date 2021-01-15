#include <stdio.h>
#include <iostream>

using namespace std;

int N, M, x, y, K;
int map[22][22];
int horizon[] = {0, 0};
int vertical[] = {0, 0, 0, 0};

void move_west(){
    int temp = horizon[0];
    horizon[0] = vertical[1];
    vertical[1] = horizon[1];
    horizon[1] = vertical[3];
    vertical[3] = temp;
}

void move_east(){
    int temp = horizon[1];
    horizon[1] = vertical[1];
    vertical[1] = horizon[0];
    horizon[0] = vertical[3];
    vertical[3] = temp;
}

void move_north(){
    int temp = vertical[0];
    for(int i = 0; i < 3; i++){
        vertical[i] = vertical[i+1];
    }
    vertical[3] = temp;
}

void move_south(){
    int temp = vertical[3];
    for(int i = 3; i > 0; i--){
        vertical[i] = vertical[i-1];
    }
    vertical[0] = temp;
}

void (*rotate_dice[])() = { move_east, move_west, move_north, move_south } ;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool boundary(int x, int y){
    return x >= 0 && x < M && y >= 0 && y < N;
}

int main(){
    FILE *stream = freopen("S2\\28\\input\\14499.txt", "r", stdin);
    if(!stream) perror("freopen");


    cin >> N >> M >> x >> y >> K;

    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++){
                cin >> map[r][c];
        }
    }

    for(int idx = 0; idx < K; idx++){

        if(map[y][x] != 0){
            vertical[3] = map[y][x];
            map[y][x] = 0;
        }
        else{
            map[y][x] = vertical[3];
        }


        int command;
        cin >> command;
        command--;

        int ny = y + dy[command];
        int nx = x + dx[command];

        if(!boundary(nx, ny)) continue;
        x = nx;
        y = ny;
        
        (*rotate_dice[command])();

        cout << vertical[1] << "\n";
    }

    return 0;
}
