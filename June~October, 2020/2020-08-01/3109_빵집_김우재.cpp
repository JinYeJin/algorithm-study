#include <iostream>
#include <vector>

using namespace std;

int r,c;

int dx[3] = {-1,0,1};
int dy[3] = {1,1,1};

vector<vector<char>> map;
bool passed[10000][500];

int go(int x, int y){
    passed [x][y] = true;
    if(y == c-1) return 1;
    for(int i=0; i < 3; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < r && 0 <= ny && ny < c) { // 범위내에 있으면
            if(passed[nx][ny] == false && map[nx][ny] == '.'){
                int result = go(nx, ny);
                if(result == 1) return 1;
            }
        }
    }
    return 0;
}

int main() {

    cin >> r >> c;
    
    // 사이즈 //
    map.resize(r, vector<char>(c));

    // 초기화 //
    for(int i=0; i < map.size(); i++){
        for(int j=0; j < map[i].size(); j++){
            cin >> map[i][j];
        }
    }

    int count = 0;
    for(int i=0; i < r; i++){
        count += go(i, 0);
    }
    
    cout << count << "\n";
    return 0;
}
