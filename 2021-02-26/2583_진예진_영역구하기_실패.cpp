/*
2583 영역 구하기
실버 1
*/
#include <stdio.h>
#include <iostream> 
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int M, N, K;

typedef struct Coord{
    Coord(int x, int y): x(x), y(y) {}
    int x, y;
}Coord;


bool bounndary(Coord c){
    return c.x >= 0 && c.x < N && c.y >= 0 && c.x < M;
}


int main(){
    FILE *stream =freopen("S2\\32\\input\\2583.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    bool paper[101][101];
    bool visited[101][101];
    vector<pair<Coord, Coord>> rectangles;
    queue<Coord> path;

    cin >> M >> N >> K;
    memset(paper, false, sizeof(paper));
    memset(visited, false, sizeof(visited));


    for(int k = 0; k < K; k++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        rectangles.push_back({Coord(x1, y1), Coord(x2, y2)});
    }

    for(int i = 0; i < rectangles.size(); i++){
        Coord point1 = rectangles[i].first;
        Coord point2 = rectangles[i].second;

        for(int r = point1.y; r < point2.y; r++){
            for(int c = point1.x; c < point2.x; c++){
                paper[r][c] = true;
            }
        }
    }

    for(int r = 0; r < M; r++){
        for(int c = 0; c < N; c++){
            cout << paper[r][c] << " ";
        }
        cout << "\n";
    }

    int num_void = 0;

    for(int r = 0; r < M; r++){
        for(int c = 0; c < N; c++){

            // 빈 공간인경우 탐색시작
            if(!visited[r][c] && paper[r][c] == false){
                path.push(Coord(c, r));
                visited[r][c] = true;

                while(!path.empty()){
                    Coord cur = path.front();

                    for(int d = 0; d < 4; d++){
                        Coord next = {cur.x + dx[d], cur.y + dy[d]};

                        if(visited[next.y][next.x]) continue;
                        
                        // 다음 갈 곳도 빈공간이면
                        if(paper[next.y][next.x] == false){
                            visited[next.y][next.x] = true;
                            path.push(next);
                        }
                    }
                }

                num_void++;
            }

        }
    }

    cout << num_void;

    return 0;
}
