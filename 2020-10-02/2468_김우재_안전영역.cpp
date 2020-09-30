#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int n;
int map[101][100][100];
bool d[100][100][100];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int main() {
    cin >> n;
    
    int maxValue = 0;
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            int value; cin >> value;
            if(maxValue < value) maxValue = value;
            for(int k=0; k < 101; k++){
                map[k][i][j] = value;
                if(value <= k) map[k][i][j] = -1;
            }
        }
    }
    
    int answer = 0;
    for(int k=0; k <= maxValue; k++){
        int count = 0;
        for(int i=0; i < n; i++){
            for(int j=0; j < n; j++){
                if(map[k][i][j] != -1){
                    count++;
                    queue<pair<int, int>> q;
                    q.push(make_pair(i, j));
                    map[k][i][j] = -1;
                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for(int h=0; h < 4; h++){
                            int nx = x+dx[h];
                            int ny = y+dy[h];
                            if(nx >=0 && nx < n && ny >=0 && ny < n){
                                if(map[k][nx][ny] != -1){
                                    map[k][nx][ny] = -1;
                                    q.push(make_pair(nx, ny));
                                }
                            }
                        }
                    }
                }
            }
        }
        answer = max(answer, count);
    }
    
    cout << answer << "\n";
    
    return 0;
}
