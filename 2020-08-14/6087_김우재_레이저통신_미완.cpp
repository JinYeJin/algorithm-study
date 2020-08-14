#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int n, m;
char map[101][101]; // 여기에 저장될 것은 꺽은 횟수
int d[101][101];
int dx[] = {0,1,0,-1}; // 이동 방향
int dy[] = {1,0,-1,0}; // 이동 방향

int main(void){
    cin >> n >> m; // 가로 , 세로
    vector<pair<int,int>> node;

    for(int i=0; i < m; i++){ // 세로
        for(int j=0; j < n; j++){ // 가로
            cin >> map[i][j];
            int temp = -1;
            if(map[i][j] == '*') temp = -2;
            else if(map[i][j] == 'C'){
                node.push_back(make_pair(i, j));
            }
            d[i][j] = temp;
        }
    }

    int start_x = node[1].first; // 시작 x
    int start_y = node[1].second;  // 시작 y
    int end_x = node[0].first; // 끝 x
    int end_y = node[0].second; // 끝 y
    
    for(int k=0; k < 4; k++){
        queue<tuple<int, int, int>> q;
        d[start_x][start_y] = 0;
        q.push(make_tuple(start_x, start_y, k));
        while(!q.empty()){
            int now_x = get<0>(q.front()); // x 빼기
            int now_y = get<1>(q.front()); // y 빼기
            int vec = get<2>(q.front()); // 방향 빼기        }
            q.pop(); // 큐값 빼기
            
            for(int i=0; i < 4; i++){ // 4방향을 위한 for 구문
                int next_x = now_x + dx[i]; // 다음 x
                int next_y = now_y + dy[i]; // 다음 y
                if(next_x >= 0 && next_x < m && next_y >=0 && next_y < n){ // 범위내에 있으면
                    if(map[next_x][next_y] == '*' || d[next_x][next_y] == -2) continue;
                    if(d[next_x][next_y] == -1 || d[next_x][next_y] > d[now_x][now_y] || vec == i){
                        d[next_x][next_y] = d[now_x][now_y];
                        if(vec != i) d[next_x][next_y]++;
                        q.push(make_tuple(next_x, next_y, i));
                    }
                }
            }
        }
    }
    cout << d[end_x][end_y] << "\n";
    return 0;
}
