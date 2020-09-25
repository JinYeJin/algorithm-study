#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

#define INF 1000000
using namespace std;

int main() {
    int n; // 노드
    int r; // 로드
    cin >> n >> r; // 입력
    
    int map[400][400];
    fill(&map[0][0], &map[400 - 1][400], INF);

    for(int i=0; i < r; i++){
        int temp_x, temp_y, value;
        cin >> temp_x >> temp_y >> value;
        map[temp_x-1][temp_y-1] = value;
    }
    
    for(int k=0; k < n; k++){ // 거치는 노드
        for(int i=0; i < n; i++){ // 출발 노드
            for(int j=0; j < n; j++){ // 도착 노드
                if(map[i][j] > map[i][k]+map[k][j]){
                    map[i][j] = map[i][k]+map[k][j];
                }
            }
        }
    }
    
    int answer = INF;
    for(int i=0; i < n; i++){ // 하나씩 다 돌 예정
        for(int j=0; j < n; j++){
            if(i == j) continue;
            if(map[i][j] != INF && map[j][i] != INF){
                answer = min(answer, map[i][j] + map[j][i]);
            }
        }
    }
    if(answer == INF) cout << -1 << "\n";
    else cout << answer;
    
    return 0;
}
