/*
*/
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

typedef struct Coord{
    Coord(int x, int y): x(x), y(y) {}
    int x, y;
    bool candidate[10] = { false, true, true, true, true, true, true, true, true, true };
}Coord;

int sudoku[9][9];
// 북, 동, 남, 서
vector<Coord> dxdy = { {0, -1}, {1, 0}, {0, 1}, {-1, 0}};
vector<Coord> blanks;

Coord operator+(Coord a, Coord b){
    return Coord(a.x + b.x, a.y + b.y);
}

bool boundary_check(Coord c){
    return c.x >= 0 && c.x < 9 && c.y >= 0 && c.y < 9;
}

void print_sudoku(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            printf("%d", sudoku[i][j]);
        }
        printf("\n");
    }
}

void set_possible_number(Coord c){
    // 4방위 탐색
    Coord temp = c;
    for(int i = 0; i < 4; i++){
        while(boundary_check(temp)){
            temp = c + dxdy[i];
            c.candidate[sudoku[temp.y][temp.x]] = false;
        }
    }

    // 3 * 3 영역 탐색
    for(int i = c.y - (c.y % 3); i < 3; i++){
        for(int j = c.x - (c.x % 3); j < 3; j++){
            c.candidate[sudoku[i][j]] = false;
        }
    }

    blanks.push_back(c);
}

void dfs_fill_sudoku(int index){
    // 빈칸을 모두 채운 경우
    if(index == blanks.size()) {
        print_sudoku();
        exit(0);
    }

    for(int i = 1; i < 10; i++){
        Coord &cur = blanks[index];
        // 후보숫자에 있으면 dfs 호출
        if(cur.candidate[i]){
            sudoku[cur.y][cur.x] = cur.candidate[i];
            dfs_fill_sudoku(index + 1);
            sudoku[cur.y][cur.x] = 0;
        }
    }
}

int main(){
    FILE *stream =freopen("S2\\12\\input\\2580.txt", "r", stdin);
    if(!stream) perror("freopen");


    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            scanf("%d", &sudoku[j][i]);
        }
    }

    // blanks 배열 초기화
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            // 공백이면
            if(sudoku[j][i] == 0) set_possible_number(Coord(j, i));
        }
    }

    dfs_fill_sudoku(0);

    return 0;
}
