#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

class Dron{
    public :
    int x;
    int y;
    int d; // 0이면 세로 // 1이면 가로 방향
    int v;
    public :
    Dron(int tx, int ty, int td, int tv){
        x = tx;
        y = ty;
        d = td;
        v = tv;
    }
};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int d[100][100];

int solution(vector<vector<int>> board) {
    int answer = 0;
    int col = board.size();
    int row = board[0].size();
    memset(d, -1, sizeof(d));
    queue<Dron> q;
    d[0][0] = 0;
    d[0][1] = 0;
    q.push(Dron(0,0,1,0));
    
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int dir = q.front().d;
        int value = q.front().v;
        q.pop();
        
        // 4방향 이동하기
        for(int i=0; i < 4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            int nvalue = value+1;
            if(nx < 0 || nx >= row || ny < 0 || ny >= col) continue; // 기준이 넘었을 경우
            if(dir == 0){if(nx+1 < 0 || nx+1 >= row || ny < 0 || ny >= col) continue;} // 세로 넘었을 경우
            else if(dir == 1){if(nx < 0 || nx >= row || ny+1 < 0 || ny+1 >= col) continue;} // 가로 넘었을 경우
            if(dir == 0){
                if(board[nx][ny] != 1 && board[nx+1][ny] != 1){
                    if(d[nx][ny] == -1 || d[nx][ny] > nvalue){
                        d[nx][ny] = nvalue;
                        q.push(Dron(nx, ny, 0, nvalue));
                    }
                }
            }else if(dir == 1){
                if(board[nx][ny] != 1 && board[nx][ny+1] != 1){
                    if(d[nx][ny] == -1 || d[nx][ny] > nvalue){
                        d[nx][ny] = nvalue;
                        q.push(Dron(nx, ny, 0, nvalue));
                    }
                }
            }
        }
        // 방향 바꾸기

        // -1/-1  ㅇ     -1/1
        // ㅇ      ㅇ     ㅇ
        // 1/-1   ㅇ     1/1

        // 기존 nx ny 기준으로 바꾸기
        // 세로
        // 시계방향
        if(dir == 0){
            if(x+1 >= 0 && x+1 < row && y-1 >= 0 && y-1 < col){
                if(board[x+1][y-1] != 1){
                    if(board[x][y-1] != 1){
                        if(d[x][y-1] == -1 || d[x][y-1] > value+1){
                            d[x][y-1] = value+1;
                            q.push(Dron(x, y-1, 1, value+1));
                        }
                    }
                }
            }
        }
        // 시계 반대방향
        if(dir == 0){
            if(x+1 >= 0 && x+1 < row && y+1 >= 0 && y+1 < col){
                if(board[x+1][y+1] != 1){
                    if(board[x][y+1] != 1){
                        if(d[x][y+1] == -1 || d[x][y+1] > value+1){
                            d[x][y] = value+1;
                            q.push(Dron(x, y, 1, value+1));
                        }
                    }
                }
            }
        }
        // 가로
        if(dir == 1){
            if(x-1 >= 0 && x-1 < row && y+1 >= 0 && y+1 < col){
                if(board[x-1][y+1] != 1){//-1/1
                    if(board[x-1][y] != 1){
                        if(d[x-1][y] == -1 || d[x-1][y] > value+1){
                            d[x-1][y] = value+1;
                            q.push(Dron(x-1, y, 0, value+1));
                        }
                    }
                }
            }
        }
        
        if(dir == 1){
            if(x+1 >= 0 && x+1 < row && y+1 >= 0 && y+1 < col){
                if(board[x+1][y+1] != 1){//1/1
                    if(board[x+1][y] != 1){
                        if(d[x+1][y] == -1 || d[x+1][y] > value+1){
                            d[x][y] = value+1;
                            q.push(Dron(x, y, 0, value+1));
                        }
                    }
                }
            }
        }
        
        // 기존 앞 노드를 기준으로 바꾸기
        //-1-1 위로 올라가기
        if(dir == 0){
            if(x+1 >= 0 && x+1 < row){
                if((x+1)-1 >= 0 && (x+1)-1 < row && y-1 >= 0 && y-1 < col){
                    if(board[(x+1)-1][y-1] != 1){
                        if(board[(x+1)][y-1] != 1){
                            if(d[x+1][y-1] == -1 || d[x+1][y-1] > value+1){
                                d[x+1][y-1] = value+1;
                                q.push(Dron(x+1, y-1, 1, value+1));
                            }
                        }
                    }
                }
            }
        }
        if(dir == 0){
            if(x+1 >= 0 && x+1 < row){
                if((x+1)-1 >= 0 && (x+1)-1 < row && y+1 >= 0 && y+1 < col){
                    if(board[(x+1)-1][y-1] != 1){
                        if(board[(x+1)][y+1] != 1){
                            if(d[x+1][y+1] == -1 || d[x+1][y+1] > value+1){
                                d[x+1][y] = value+1;
                                q.push(Dron(x+1, y, 1, value+1));
                            }
                        }
                    }
                }
            }
        }
        
        // 가로방향
        if(dir == 1){
            if(y+1 >= 0 && y+1 < col){
                if( x-1 >= 0 && x-1 < row && (y+1)-1 >= 0 && (y+1)-1 < col){
                    if(board[x-1][(y+1)-1] != 1){
                        if(board[(x-1)][y+1] != 1){
                            if(d[x-1][y+1] == -1 || d[x-1][y+1] > value+1){
                                d[x-1][y+1] = value+1;
                                q.push(Dron(x-1, y+1, 0, value+1));
                            }
                        }
                    }
                }
            }
        }
        if(dir == 1){
            if(y+1 >= 0 && y+1 < col){
                if( x+1 >= 0 && x+1 < row && (y+1)-1 >= 0 && (y+1)-1 < col){
                    if(board[x+1][(y+1)-1] != 1){
                        if(board[(x+1)][y+1] != 1){
                            if(d[x+1][y+1] == -1 || d[x][y+1] > value+1){
                                d[x][y+1] = value+1;
                                q.push(Dron(x, y+1, 0, value+1));
                            }
                        }
                    }
                }
            }
        }
    }
    if(d[row-1][col-1-1] != -1) answer = d[row-1][col-1-1];
    if(d[row-1-1][col-1] != -1) {
        if(answer != 0){
            answer = min(answer, d[row-1-1][col-1]);
        } else{
         answer = d[row-1-1][col-1];
        }
    }
    return answer;
}
