/*
[백준 17822] www.acmicpc.net/problem/17822
*/
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int M, N, T;
int X, D, K; // x배수 원판, d방향(0 시계, 1 반시계), k 칸
int circular[52][52];
bool visited[52][52];
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

void move_clockwise(int x, int k){
    for(int i = x; i <= N; i+=x){
        rotate(circular[i]+1, circular[i] + M-k+1, circular[i] + M+1);
    }
}

void move_counterclockwise(int x, int k){
    for(int i = x; i <= N; i+=x){
        rotate(circular[i]+1, circular[i] + k+1, circular[i] + M+1);
    }
}

int remove_number(int x, int y){
    int ret = 0;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        // 좌표 재조정
        if(ny == 0 || ny == N+1) continue;

        if(nx == 0) nx = M;
        else if(nx == M+1) nx = nx % M;

        // 인접한 수가 같으면
        if(!visited[ny][nx] && circular[y][x] == circular[ny][nx]){
            ret++;
            circular[y][x] = 0;
            visited[y][x] = true;
            ret += remove_number(nx, ny);
            circular[ny][nx] = 0;
            visited[ny][nx] = true;
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> M >> N >> T;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> circular[i][j];
        }
    }

    for(int i = 0; i < T; i++){
        cin >> X >> D >> K;

        if(D == 0) move_clockwise(X, K);
        else if(D == 1) move_counterclockwise(X, K);

        // 인접한 숫자들 없애기
        int removed = 0;
        int sum = 0;
        int num = 0;
        for(int y = 1; y <= N; y++){
            for(int x = 1; x <= M; x++){
                memset(visited, false, sizeof(visited));
                sum += circular[y][x];
                if(circular[y][x] != 0) 
                    num++;
                // 이미 방문한 곳 검사
                if(circular[y][x] != 0)
                    removed += remove_number(x, y);
            }
        }

        // 인접한 수가 하나도 없었으면
        if(removed == 0){
            double average = (double)sum / num;
            for(int y = 1; y <= N; y++){
                for(int x = 1; x <= M; x++){
                    if(circular[y][x] != 0){
                        if(circular[y][x] > average)
                            circular[y][x] -= 1;
                        else if(circular[y][x] < average) 
                            circular[y][x] += 1;
                    }
                }
            }
        }
    }



    int answer = 0;

    for(int y = 1; y <= N; y++){
        for(int x = 1; x <= M; x++){
            answer += circular[y][x];
        }
    }

    cout << answer;

    return 0;
}
