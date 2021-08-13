/*
이차원 배열로 체크 안되는 이윰... https://www.acmicpc.net/board/view/46431
이차배열 방문체크...? https://j3sung.tistory.com/466
백준 1600 https://www.acmicpc.net/problem/1600
*/
#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

typedef struct Coord{
    Coord(int x, int y, int k, int moved): x(x), y(y), k(k), moved(moved) {}
    int x, y, k, moved;
}Coord;

int K, W, H;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
// 오른쪽부터 시계방향으로
int h_dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int h_dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool boundary(Coord cur){
    return cur.x >= 0 && cur.x < W && cur.y >= 0 && cur.y < H;
}

/*
int main(){
    FILE *stream =freopen("S2\\20\\input\\1600.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int map[201][201];
    int dp[201][201]; // x, y 지점에 몇 번 이동하여 도착했는지 저장
    queue<Coord> path;

    memset(map, 0, sizeof(map));
    memset(dp, 0, sizeof(dp));

    cin >> K;
    cin >> W >> H;

    for(int r = 0; r < H; r++){
        for(int c = 0; c < W; c++){
            cin >> map[r][c];
        }
    }


    path.push(Coord(0, 0, K, 0));

    while(!path.empty()){
        Coord cur = path.front();
        path.pop();

        if(cur.x == H-1 && cur.y == W-1){
            cout << cur.moved;
            return 0;
        }

        if(cur.k > 0){
            for(int i = 0; i < 8; i++){
                Coord new_c = { cur.x + h_dx[i], cur.y + h_dy[i],
                                cur.k - 1, cur.moved + 1 };
                if(boundary(new_c)){
                    if(map[new_c.y][new_c.x] == 0
                       && (new_c.moved < dp[new_c.y][new_c.x]
                           || dp[new_c.y][new_c.x] == 0)){
                           dp[new_c.y][new_c.x] = new_c.moved;
                           path.push(new_c);
                       }
                }
            }
        }

        for(int i = 0; i < 4; i++){
            Coord new_c = { cur.x + dx[i], cur.y + dy[i],
                            cur.k, cur.moved + 1 };
            if(boundary(new_c)){
                if(map[new_c.y][new_c.x] == 0
                   && (new_c.moved < dp[new_c.y][new_c.x]
                      || dp[new_c.y][new_c.x] == 0)){
                    dp[new_c.y][new_c.x] = new_c.moved;
                    path.push(new_c);
                }
            }

        }
    }

    cout << -1;

    return 0;
}
*/


int main(){
    FILE *stream =freopen("S2\\20\\input\\1600.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int map[201][201];
    bool dp[201][201][31]; // k 마다 다르게 방문체크
    queue<Coord> path;

    memset(map, 0, sizeof(map));
    memset(dp, 0, sizeof(dp));

    cin >> K;
    cin >> W >> H;

    for(int r = 0; r < H; r++){
        for(int c = 0; c < W; c++){
            cin >> map[r][c];
        }
    }


    path.push(Coord(0, 0, K, 0));
    dp[0][0][0] = true;

    while(!path.empty()){
        Coord cur = path.front();
        path.pop();

        if(cur.x == W-1 && cur.y == H-1){
            cout << cur.moved;
            exit(0);
        }

        if(cur.k > 0){
            for(int i = 0; i < 8; i++){
                Coord new_c = { cur.x + h_dx[i], cur.y + h_dy[i],
                                cur.k - 1, cur.moved + 1 };
                if(boundary(new_c)){
                    if(map[new_c.y][new_c.x] == 0 && dp[new_c.y][new_c.x][new_c.k] == false){
                           dp[new_c.y][new_c.x][new_c.k] = true;
                           path.push(new_c);
                       }
                }
            }
        }

        for(int i = 0; i < 4; i++){
            Coord new_c = { cur.x + dx[i], cur.y + dy[i],
                            cur.k, cur.moved + 1 };
            if(boundary(new_c)){
                if(map[new_c.y][new_c.x] == 0 && dp[new_c.y][new_c.x][new_c.k] == false){
                    dp[new_c.y][new_c.x][new_c.k] = true;
                    path.push(new_c);
                }
            }

        }
    }

    cout << -1;

    return 0;
}
