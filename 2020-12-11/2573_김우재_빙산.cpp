#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int dx [] = {0,0,-1,1};
int dy [] = {1,-1,0,0};

int main() {
    int n, w;
    cin >> n >> w;
    vector<vector<int>> map(n, vector<int>(w));

    for (int i=0; i < n; i++) {
        for (int j=0; j < w; j++) {
            cin >> map[i][j];
        }
    }
    
    int answer = 0;
    bool flag = false;
    while (true) {
        vector<vector<int>> deleteCount(n, vector<int>(w, 0));
        vector<vector<int>> visite(n, vector<int>(w, -1));

        for (int i=0; i < n; i++) {
            for (int j=0; j < w; j++) {
                if(map[i][j] == 0) continue;
                for(int k=0; k < 4; k++){
                    int nx = i+dx[k];
                    int ny = j+dy[k];
                    if(map[nx][ny] == 0) deleteCount[i][j]++;
                }
            }
        }
        for (int i=0; i < n; i++) {
            for (int j=0; j < w; j++) {
                if(deleteCount[i][j] > 0){
                    if(deleteCount[i][j] >= map[i][j]) map[i][j] = 0;
                    else map[i][j] = map[i][j] - deleteCount[i][j];
                }
            }
        }
        
        int group = 0;
        for (int i=0; i < n; i++) {
            for (int j=0; j < w; j++) {
                if(visite[i][j] == -1 && map[i][j] > 0){
                    group++;
                    queue<pair<int, int>> q;
                    q.push(make_pair(i, j));
                    visite[i][j] = 0;
                    
                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        
                        for(int i=0; i < 4; i++){
                            int nx = x+dx[i];
                            int ny = y+dy[i];
                            
                            if(nx >= 0 && nx < n && ny >= 0 && ny < w){
                                if(visite[nx][ny] == -1 && map[nx][ny] > 0){
                                    visite[nx][ny] = 0;
                                    q.push(make_pair(nx, ny));
                                }
                            }
                        }
                    }
                }
            }
        }
        answer++;
        if(group > 1) break;
        if(group == 0) {flag = true; break;}
        
    }
    if(flag) cout << 0 << "\n";
    else cout << answer << "\n";
    
    return 0;
}







