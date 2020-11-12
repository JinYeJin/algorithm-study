#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <tuple>
#include <queue>

using namespace std;

int row, column;
int cheeze_time = 0;
int answer = 0;
int map[100][100];
int d[100][100];
bool visite[100][100];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool ok;
void bfs(int x, int y){
    queue<pair<int, int>> q;
    memset(visite, false, sizeof(visite));
    answer = 0;
    visite[x][y] = true;
    d[x][y] = 0;
    q.push(make_pair(x, y));
    while (!q.empty()) {
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();
        for(int i=0; i < 4; i++){
            int next_x = now_x+dx[i];
            int next_y = now_y+dy[i];
            if(next_x >=0 && next_x < row && next_y >= 0 && next_y < column){
                if(map[next_x][next_y] == 0 && visite[next_x][next_y] == false){
                    visite[next_x][next_y] = true;
                    q.push(make_pair(next_x, next_y));
                }
                if(map[next_x][next_y] == 1 && visite[next_x][next_y] == false){
                    map[next_x][next_y] = 0;
                    d[next_x][next_y] = cheeze_time;
                    answer++;
                    visite[next_x][next_y] = true;
                }
            }
        }
    }
}

bool isFinish(){
    for(int i=0; i < row; i++){
        for(int j=0; j < column; j++){
            if(map[i][j] == 1) return false;
        }
    }
    return true;
}


int main() {
    cin >> row >> column;
    
    for (int i=0; i < row; i++) {
        for(int j=0; j < column; j++){
            cin >> map[i][j];
        }
    }
    
    while (true) {
        cheeze_time++;
        bfs(0, 0);
        /*
        cout << "\n";
        for(int i=0; i < row; i++){
            for(int j=0; j < column; j++){
                cout << map[i][j] << "\t";
            }
            cout << "\n";
        }
        
        cout << "\n";
        for(int i=0; i < row; i++){
            for(int j=0; j < column; j++){
                cout << visite[i][j] << "\t";
            }
            cout << "\n";
        }

        cout << "\n";
        for(int i=0; i < row; i++){
            for(int j=0; j < column; j++){
                cout << d[i][j] << "\t";
            }
            cout << "\n";
        }
        */
        if(isFinish())break;
    }
    cout << cheeze_time << "\n";
    cout << answer << "\n";

    return 0;
}
