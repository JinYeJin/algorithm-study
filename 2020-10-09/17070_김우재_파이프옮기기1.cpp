#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <tuple>
#include <queue>

#define MAX 16
#define DIRECTION 3

using namespace std;

int n;
int map[MAX][MAX];
//pair<int, int> next[] = {{0,1},{1,0},{1,1}};

int go(int x, int y, int dir){
    if (x == n-1 && y == n-1) {
        return 1;
    }
    
    int result = 0;
    if(dir == 0){
        if(y+1 < n && map[x][y+1] == 0){
            result += go(x, y+1, 0);

        }
        if(x+1 < n && y+1 < n && map[x+1][y+1] == 0 && map[x+1][y] == 0 && map[x][y+1] == 0){
            result += go(x+1, y+1, 2);
        }
    }
    if(dir == 1){
        if(x+1 < n && map[x+1][y] == 0){
            result += go(x+1, y, 1);
        }
        if(x+1 < n && y+1 < n && map[x+1][y+1] == 0 && map[x+1][y] == 0 && map[x][y+1] == 0){
            result += go(x+1, y+1, 2);
        }
    }
    if(dir == 2){
        if(x+1 < n && y+1 < n && map[x+1][y+1] == 0 && map[x+1][y] == 0 && map[x][y+1] == 0){
            result += go(x+1, y+1, 2);
        }
        if(y+1 < n && map[x][y+1] == 0){
            result += go(x, y+1, 0);
        }
        if(x+1 < n && map[x+1][y] == 0){
            result += go(x+1, y, 1);
        }
    }
    
    return result;
}

int main() {
    cin >> n;
    
    memset(map, -1, sizeof(map));

    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            cin >> map[i][j];
        }
    }
    cout << go(0,1,0) << "\n";

    return 0;
}


