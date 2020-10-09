/*
[백준 2636 치즈] https://www.acmicpc.net/problem/2636
https://j2wooooo.tistory.com/22
바깥과 치즈의 구분이 중요함!!
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
 
using namespace std;

int N, M;
int cheese[101][101];
int out[101][101];
int flag = 1;
 
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

bool boundary(int x, int y){
    return x >= 0 && x < N && y >= 0 && y < M;
}

void dfs(int _x, int _y){
    if(out[_x][_y] == 0) out[_x][_y] = 1;

    for(int i = 0; i < 4; i++){
        int mx = _x + dx[i];
        int my = _y + dy[i];
 
        if(boundary(mx, my) && cheese[mx][my] == 0 && out[mx][my] == 0)
            dfs(mx, my);
    }
    return;
}

int main(){
    FILE *stream =freopen("S2\\18\\input\\2636.txt", "r", stdin);
    if(!stream) perror("freopen");
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int prev_num = 0;
    int cnt = 0;
    int answer = 0;
    int num_of_cheese = 0;
 
    cin >> N >> M;
 
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> cheese[i][j];
            if (cheese[i][j]) num_of_cheese++;
        }
    }
 

    // flag는 1치즈가 한번도 녹지 않았을 때 false가 된다
    while(flag){
        if(num_of_cheese) prev_num = num_of_cheese;
        flag = 0;
        memset(out, 0, sizeof(out));

        // out 배열 업데이트, 가장자리는 어차피 항상 비어있음
        dfs(0, 0);

        for(int i = 1; i < N - 1; i++){
            for(int j = 1; j < M - 1; j++){
                // 4방향 탐색
                for(int k = 0; k < 4; k++){
                    int mx = i + dx[k];
                    int my = j + dy[k];
                    if(out[mx][my] == 1) cnt++;
                }
                if(cheese[i][j] == 1 && cnt >= 1){
                    cheese[i][j] = 0; flag = 1;
                    num_of_cheese--;
                }
                cnt = 0;
            }
        }
        answer++;
    }
 
    cout << answer-1 << "\n" << prev_num;
 
    return 0;
}
