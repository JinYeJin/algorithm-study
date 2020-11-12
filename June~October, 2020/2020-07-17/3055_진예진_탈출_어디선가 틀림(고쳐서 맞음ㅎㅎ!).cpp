/*
2020-07-13 진예진
[백준 3055 탈출] https://www.acmicpc.net/problem/3055
*/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct Coord{
    Coord(int x, int y): x(x), y(y) {}
    int x, y;
}Coord;

char map[50][50];
int R, C, answer;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
queue<Coord> water;
queue<Coord> hedgehog;

bool boundary_check(Coord c){
    return c.x >= 0 && c.x < C && c.y >= 0 && c.y < R;
}

void flood(){
    int size = water.size();
 
    for(int i = 0; i < size; i++){
        Coord current = water.front();
        water.pop();

        for(int j = 0; j < 4; j++){
            Coord new_coord = {current.x + dx[j], current.y + dy[j]};
 
            if(boundary_check(new_coord)){ 
                // 빈공간이면 물이 차오름
                if(map[new_coord.y][new_coord.x] == '.'){ 
                    map[new_coord.y][new_coord.x] = '*';
                    water.push(Coord(new_coord.x, new_coord.y));
                }
            }
        }
    }
}
 
bool move_hedgehog(){
    // 계속 도는 게 아니라 현재 고슴도치 경로만큼만 돌아야함 
    int size = hedgehog.size();
 
    for(int i = 0; i < size; i++){
        Coord current = hedgehog.front();
        hedgehog.pop();

        for(int j = 0; j < 4; j++){
            Coord new_coord = {current.x + dx[j], current.y + dy[j]};
 
            if(boundary_check(new_coord)){
                // 도착한 경우
                if(map[new_coord.y][new_coord.x] == 'D'){
                    hedgehog.push(Coord(new_coord.x, new_coord.y));
                    return true;
                }
                // 비어있으면 이동
                if(map[new_coord.y][new_coord.x] == '.'){
                    map[new_coord.y][new_coord.x] = 'S';
                    hedgehog.push(Coord(new_coord.x, new_coord.y));
                }
            }
        }
    }
    // 다 돌아도 도착 못하면 false
    return false;
}
 

int main(){
    // FILE *stream = freopen("S2\\7\\input\\3055_input.txt", "r", stdin);
    FILE *stream = freopen("S2/7/input/3055_input.txt", "r", stdin);
    if(!stream) perror("freopen");


    scanf("%d %d\n", &R, &C);
    
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            scanf("%c", &map[i][j]);

            // 여기가 틀렸었음!! j, i 순서 조심하기!! 행렬 잘 생각하기
            if(map[i][j] == '*') water.push(Coord(j, i));
            if(map[i][j] == 'S') hedgehog.push(Coord(j, i));
        }
        scanf("\n");
    }

    answer = 0;

    while (true) {
        answer++;
        if (hedgehog.size() == 0) {
            printf("KAKTUS");
            return 0;
        }
 
        flood();

        // 움직이다 비버집에 도착하면 True 리턴
        if(move_hedgehog()){
            printf("%d", answer);
            return 0;
        }
    }

    return 0;
}
