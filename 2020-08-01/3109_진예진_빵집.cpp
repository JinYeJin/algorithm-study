/*
*/
#include <stdio.h>
#include <iostream>

using namespace std;

int map[10001][501];
int R, C, res;

int visited[10002][502];
char a[10002][502];

// 오른쪽 위, 오른쪽, 오른쪽 아래 순으로 탐색
int dx[] = { 1,1,1 };
int dy[] = { -1,0,1 };


int dfs(int y, int x) {
    map[y][x] = -1;

    if (y == C - 1)return true;

    for (int i = 0; i < 3; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (map[ny][nx] == -1 && map[ny][nx] == 0) {
            int return_value = dfs(ny, nx);
            if(return_value) return return_value;
        }
    }
    return false;
}

int main(){
    FILE *stream = freopen("s2\\9\\input\\3109_input.txt", "r", stdin);
    if(!stream) perror("freopen");

    char temp;

    scanf("%d %d", &R, &C);

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> temp;
            // 빈칸
            if(temp == '.') map[i][j] = 0;
            // 파이프가 못지나가는 건물
            else if(temp == 'x') map[i][j] = -1;
        }
    }

    // 한 라인마다 dfs
    for (int i = 0; i < R; i++) res += dfs(i, 0);

    printf("%d\n", res);
    return 0;
}
