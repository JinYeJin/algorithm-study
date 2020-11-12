/*
*/
#include <stdio.h>
#include <iostream> 
#include <queue>
#include <stack>


using namespace std;

int N;

typedef struct Coord{
    Coord(int y, int x, int d, int n): y(y), x(x), d(d), n(n) {}
    int x, y, d, n;
}Coord;

bool boundary(Coord c){
    return c.x >= 0 && c.x < N && c.y >= 0 && c.y < N;
}


int main(){
    FILE *stream =freopen("S2\\20\\input\\17780.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int chess[13][13]; // 체스판 배열
    vector<vector<queue<int>>> location(13, vector<queue<int>>(13, queue<int>())); // 체스말 배열
    queue<Coord> pieces;
    int K;
    int r, c, d;
    int moved= 0;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    int change_d[] = {1, 0, 3, 2};

    cin >> N >> K;

    for(r = 0; r < N; r++){
        // pieces.push_back(vector<queue<int>>);
        for(c = 0; c < N; c++){
            cin >> chess[r][c];
        }
    }

    for(int n = 0; n < K; n++){
        cin >> r >> c >> d;
        location[r][c].push(n);
        pieces.push(Coord(r, c, d, n));
    }


    while(moved <= 1001){
        Coord cur = pieces.front();
        pieces.pop();

        queue<int> *cur_pieces = &location[cur.y][cur.x];
        // 현재 순서의 체스말이 맨 바닥에 있는지 확인하는 코드 짜야함
        if(cur.n != cur_pieces->front()){
            pieces.push(cur);
            continue;
        }

        Coord new_c = {cur.y + dy[cur.d], cur.x + dx[cur.d], cur.d, cur.n};
        queue<int> *new_pieces = &location[new_c.y][new_c.x];

        // 흰색 => 체스말 옮김
        if(chess[new_c.y][new_c.x] == 0){
            while(!cur_pieces->empty()){
                new_pieces->push(cur_pieces->front());
                cur_pieces->pop();
            }
        }

        //빨간색
        else if(chess[new_c.y][new_c.x] == 1){
            stack<int> temp;
            while(!cur_pieces->empty()){
                // 반대로 넣기위해서 일단 스택에 쌓아줌
                temp.push(cur_pieces->front());
                cur_pieces->pop();
            }

            while(!temp.empty()){
                new_pieces->push(temp.top());
                temp.pop();
            }
        }

        //파란색 || 체스판 벗어남
        else if(chess[new_c.y][new_c.x] == 2 || !boundary(new_c)){
            new_c.d = change_d[cur.d]; // 방향변경
            new_c.x += dx[new_c.d];
            new_c.y += dy[new_c.d];

            // 이동하려는 지점이 파란색이 아니고 경계 안인 경우만 이동
            if(chess[new_c.y][new_c.x] != 2 && boundary(new_c)){
                queue<int> *new_pieces = &location[new_c.y][new_c.x];
                while(!cur_pieces->empty()){
                    new_pieces->push(cur_pieces->front());
                    cur_pieces->pop();
                }
            }
        }

        pieces.push(new_c);
        moved++;

        // 4개가 모이면 종료
        if(new_pieces->size() >= 4) break;
    }

    if(moved == 1001) printf("-1");
    else printf("%d", moved);

    return 0;
}
