#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include<tuple>
#include <algorithm>

using namespace std;

int n;
int map[2001][2001];
bool d[2001][2001];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void dfs(int now_x, int now_y){
    if(d[now_x][now_y]) return; // 방문한적이 있으면 리턴
    d[now_x][now_y] = true; // 방문 안했다는 로직이므로 true 처리.
    for(int i=0; i < 4; i++){ // 4방향
        int nx = now_x + dx[i]; // 다음 x
        int ny = now_y + dy[i]; // 다음 y
        if(nx >= 0 && nx < 2001 && ny >= 0 && ny < 2001){ // 범위내에 존재하는지.
            if(map[nx][ny] == 1){ // 만약 다음이 갈 수 있다면
                dfs(nx,ny); // 가즈앗
            }
        }
    }
}

int main(void){
    cin >> n;
    
    for(int i=0; i < n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        x1 = (x1 + 500) * 2;
        y1 = (y1 + 500) * 2;
        x2 = (x2 + 500) * 2;
        y2 = (y2 + 500) * 2;

        if(x1 > x2){
            int temp = x1; x1 = x2; x2 = temp;
            temp = y1; y1 = y2; y2 = temp;
        }
        for(int i=x1; i <= x2; i++){
            map[i][y1] = 1; // 연결
            map[i][y2] = 1; // 연결

        }
        for(int j=y1; j <= y2; j++){
            map[x1][j] = 1; // 연결
            map[x2][j] = 1; // 연결
        }
    }
    int cnt = 0; // 카운트.
    for(int i=0; i < 2001; i++){ // 0 ~ 2000 까지
        for(int j=0; j < 2001; j++){ // 0 ~ 2000 까지
            // 일단 전부 false 상태이다.
            // 만약 값이 1이면 방문할 수 있다는 뜻이므로 방문을 시작한다.
            if(d[i][j]==false && map[i][j] == 1){ // 방문을 안했었고 연결되어 있다면
                dfs(i,j); // dfs 시작
                cnt++; // 연결 요소 증가
            }
        }
    }
    if(d[1000][1000] == true) cnt--; // 시작점이 입력값의 범위로 포함되어 있는 경우 한개 올릴 필요가 없으니 -1
    cout << cnt << "\n";
    
    return 0;
}
/*
 -495 -193 38 -126
 -195 -357 101 -23
 -159 92 319 435
 -466 -74 -138 82
 -159 337 319 350
 -438 -328 -343 -294
 -422 -328 487 -289
 -348 424 282 454
 */

