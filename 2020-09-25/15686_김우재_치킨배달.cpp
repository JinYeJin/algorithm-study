#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

#define INF 1000000
using namespace std;

vector<pair<int, int>> chicken;

int map[50][50];
int d[50][50];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n, m;
int chickenAmount = 0;


int bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    d[x][y] = 0;
    while (!q.empty()) {
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();
        if(map[now_x][now_y] == 2) return d[now_x][now_y];
        for(int i=0; i < 4; i++){
            int next_x = now_x +dx[i];
            int next_y = now_y +dy[i];
            if(next_x >= 0 && next_x < n && next_y >= 0 && next_y < n){
                d[next_x][next_y] = d[now_x][now_y]+1;
                q.push(make_pair(next_x, next_y));
            }
        }
    }
    return 0;
}

int getDistance(){
    int distance = 0;
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            if(map[i][j] == 1) distance += bfs(i,j);
        }
    }
    return distance;
}

int dfs(int index, int count){
    if(count == chickenAmount-m){
        return getDistance();
    }
    if(index == chicken.size()) return INF;
    
    int minValue = INF;
        
    minValue = min(minValue, dfs(index+1, count));
    map[chicken[index].first][chicken[index].second] = 0;
    
    minValue = min(minValue, dfs(index+1, count+1));
    map[chicken[index].first][chicken[index].second] = 2;

    return minValue;
}




int main() {
    // 빈칸 0
    // 집 1
    // 치킨집 2
    
    cin >> n >> m; // 길이, 폐업 갯수
    for(int i=0; i < n ; i++){
        for(int j=0; j < n; j++){
            cin >> map[i][j];
            if(map[i][j] == 2) chicken.push_back(make_pair(i, j));
        }
    }
    chickenAmount = chicken.size();
    
    cout << dfs(0, 0) << "\n";
    
    return 0;
}
