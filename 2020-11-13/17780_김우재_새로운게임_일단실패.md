#include <iostream>
#include <string>
#include <queue>
#include <deque>
#include <tuple>

using namespace std;

// 시작 시간 7:38
// 8:31 실패


// 하나의 말 위에 다른 말 올릴 수 있음
// 칸은 흰 빨 파
// 말 k놓고 시작
// 이동방향은 4방향
// 1턴당 1말부터 k말 까지 이동
// 말이 이동할 때 같은 같에 있는 말들도 같이 움직임
    // 단, 가장 아랫말만 이동 가능
// 말이 4개 쌓이면 종료

// **이동하려는 칸**
// 흰색일 경우 그대로 이동
// 말 있으면 올리기

// 빨간색 모든 말에 쌓여있는 순서 바꿈

// 파란색 이동방향 반대로 하고 한칸 이동
// 파란 -> 파란이면 이동하지 않고 방향만 바꿈
// 체스판을 벗어나는 경우에는 파란색과 같은 경우

class Hores{
public:
    int x;
    int y;
    int dir;
    
public:
    Hores(int xx, int yy, int dirdir){
        x = xx;
        y = yy;
        dir = dirdir;
    }
};

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

vector<Hores> horeses;
vector<bool> move_able_hores;
vector<vector<int>> map;
vector<vector<deque<Hores>>> horesMap;
int main(void) {
    int n, k; cin >> n >> k; // 체스판 크기 n , 말의 갯수 k
    map.resize(n+2, vector<int>(n+2, 2));
    horeses.resize(k);
    horesMap.resize(n, vector<deque<Hores>>(n));
    move_able_hores.resize(k, true);
    for(int i=1; i <= n; i++){
        for(int j=1; j <= n; j++){
            cin >> map[i][j]; // 0은 흰, 1는 빨, 2는 파
        }
    }
    // k개의 줄에 말 정보 입력됨 1번 말부터
    // 1 -> // 2 <- // 3 |^ // 4 |
    for(int i=0; i < k; i++){
        int row, col, dir;
        cin >> row >> col >> dir;
        row -=1; col -=1; dir -=1;
        horeses.push_back(Hores(row, col, dir));
        horesMap[row][col].push_back(Hores(row, col, dir));
    }
    
    // 1000 이상이거나 종료 되지 않으면 -1 출력
    // 종료되지 않으면이므로 루프 확인
    int turn = 0;
    bool flag = false;
    while (true) {
        if(flag == true) break;
        if(turn >= 1000) break;
        for(int i=0; i < k; i++){
            if(move_able_hores[i] == false) continue;
            int nx = horeses[i].x+dx[horeses[i].dir];
            int ny = horeses[i].y+dy[horeses[i].dir];
            if(map[nx][ny] == 0){
                if(horesMap[nx][ny].size() >= 1){
                    move_able_hores[i] = false;
                }
                while (!horesMap[horeses[i].x][horeses[i].y].empty()) {
                    horesMap[nx][ny].push_back(horesMap[horeses[i].x][horeses[i].y].front());
                    horesMap[horeses[i].x][horeses[i].y].pop_front();
                }
                if(horesMap[nx][ny].size() >= k) flag = true;
            }
            if(map[nx][ny] == 1){ // 빨
                if(horesMap[nx][ny].size() >= 1){
                    move_able_hores[i] = false;
                }
                while (!horesMap[horeses[i].x][horeses[i].y].empty()) {
                    horesMap[nx][ny].push_front(horesMap[horeses[i].x][horeses[i].y].back());
                    horesMap[horeses[i].x][horeses[i].y].pop_back();
                }
                if(horesMap[nx][ny].size() >= k) flag = true;
            }
            if(map[nx][ny] == 2){ // 파
                horesMap[horeses[i].x][horeses[i].y][0].dir+=1;
                if(horesMap[horeses[i].x][horeses[i].y][0].dir == 2){
                    horesMap[horeses[i].x][horeses[i].y][0].dir = 0;
                }
                if(horesMap[horeses[i].x][horeses[i].y][0].dir == 4){
                    horesMap[horeses[i].x][horeses[i].y][0].dir = 2;
                }
                nx = nx+dx[horesMap[horeses[i].x][horeses[i].y][0].dir];
                ny = ny+dy[horesMap[horeses[i].x][horeses[i].y][0].dir];
                if(map[nx][ny] == 2){
                    continue;
                }
                if(horesMap[nx][ny].size() >= 1){
                    move_able_hores[i] = false;
                }
                while (!horesMap[horeses[i].x][horeses[i].y].empty()) {
                    horesMap[nx][ny].push_back(horesMap[horeses[i].x][horeses[i].y].front());
                    horesMap[horeses[i].x][horeses[i].y].pop_front();
                }
                if(horesMap[nx][ny].size() >= k) flag = true;
            }
        }
        turn++;
    }
    cout << turn << "\n";
    return 0;
}
