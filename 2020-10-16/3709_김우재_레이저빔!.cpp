#include <iostream>
#include <vector>

#define INF 1000000
using namespace std;

int dx[] = {0,1,0,-1}; // 오른 아래 왼 위
int dy[] = {1,0,-1,0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        
        int n, r; cin >> n >> r; // 그리드 크기, 우향우 갯수;
        vector<vector<int>> map(n+2, vector<int>(n+2, -2));
        vector<vector<vector<bool>>> visite(4, vector<vector<bool>>(n+2, vector<bool>(n+2, false)));
        for(int i=1; i <=n; i++){
            for(int j=1; j <= n; j++){
                map[i][j] = 1;
            }
        }
        for(int i=0; i < r; i++){
            int x, y; cin >> x >> y;
            map[x][y] = -1;
        }
        int now_x, now_y; cin>> now_x >> now_y;
        int dir = 0;
        if(now_y == 0) dir = 0; // 오른
        if(now_x == 0) dir = 1;//아래
        if(now_y == n+1) dir = 2; // 왼
        if(now_x == n+1) dir = 3; // 위
        visite[dir][now_x][now_y] = true;
        now_x += dx[dir];
        now_y += dy[dir];
        bool isRecursive = false;
        while (true) {
            if(visite[dir][now_x][now_y]) {isRecursive = true; break;}
            if(map[now_x][now_y] == -2) {isRecursive = false; break;} // 정상적인 종료
            visite[dir][now_x][now_y] = true;
            if(map[now_x][now_y] == -1){
                if(dir == 3) dir = 0;
                else dir++;
            }
            now_x += dx[dir];
            now_y += dy[dir];
        }
        if(isRecursive) { cout << "0 0" << "\n"; continue;}
        cout << now_x << " " << now_y << "\n";
    }

}
