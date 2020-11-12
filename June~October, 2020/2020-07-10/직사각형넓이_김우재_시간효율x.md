```c++
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector<vector<int>> canvas;
queue<pair<int,int>> q;

int dx[] = {0,1};
int dy[] = {1,0};
void bfs(int start_x, int start_y, int end_x, int end_y){
    canvas[start_x][start_y]++;
    q.push(make_pair(start_x, start_y));
    while(!q.empty()){ // 큐를 다 비울때까지
        int x = q.front().first;  // 하나씩 꺼내기
        int y = q.front().second; // 하나씩 꺼내기
        q.pop(); // 완전 꺼내기
        for(int i=0; i<2; i++){ // 2방향 -> 오른쪽, 위쪽 이동 가능하다는 뜻이다.
            int nx = x +dx[i];
            int ny = y +dy[i];
            if(0 <= nx && nx < end_x && 0 <= ny && ny < end_y){ // 범위내에 있으면
                canvas[nx][ny]++; // d는 dp의 distance라고 생각해야하나
                q.push(make_pair(nx,ny)); // 큐에 값 넣기
            }
        }
    }
}


long long solution(vector<vector<int>> &rectangles){
    int max_x = -1;
    int max_y = -1;
    for(int i=0; i < rectangles.size(); i++){
        max_x = rectangles[i][2] > max_x ? rectangles[i][2] : max_x;
        max_y = rectangles[i][3] > max_y ? rectangles[i][3] : max_y;
    }
    
    canvas.resize(max_x);
    for(int i=0; i < canvas.size(); i++){
        canvas[i].resize(max_y);
    }
    
    for(vector<int> rectangle : rectangles){
        int start_x = rectangle[0];
        int start_y = rectangle[1];
        int end_x = rectangle[2];
        int end_y = rectangle[3];
        bfs(start_x, start_y, end_x, end_y);
    }
    
    int answer = 0;
    for(int i=0; i < canvas.size(); i++){
        for(int j = 0; j < canvas[i].size(); j++){
            if(canvas[i][j] > 0){
                answer += 1;
            }
        }
    }
    cout << answer << "\n";
    return 0;
}

int main(){
    vector<vector<int>> rectangles =
    {{1, 1, 6, 5}, {2, 0, 4, 2}, {2, 4, 5, 7}, {4, 3, 8, 6}, {7, 5, 9, 7}};
    
    solution(rectangles);
}
```
고칠점 : 컨버스 배열을 -1로 값을 셋팅한 다음에 이미 갔으면 그대로 종료시키는 걸루... -> 종료시키면 큐에 데이터 안들어가므로 다음이 힘들지 않을까 하는 모순점이있습니다.
