/*
1941 소문난 칠공주
*/
#include <stdio.h>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef struct Coord{
    Coord(int y, int x): y(y), x(x) {};
    int x, y;
}Coord;

bool cmp(const Coord &a, const Coord &b){
    if(a.x < b.x){
        return true;
    }else if(a.x == b.x){
        return a.y < b.y;
    }else return false;
}

int seat[7][7];
bool visited[7][7];
int answer;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
set<vector<Coord>> kinds;
vector<Coord> temp;

void select(Coord c, int num, int numY){
    if(numY >= 4) return;
    if(num >= 7){
        // kinds.insert(temp);
        answer++;
        return;
    }

    for(int d = 0; d < 4; d++){
        int nx = c.x + dx[d];
        int ny = c.y + dy[d];
        Coord n = {ny, nx};

        if(seat[ny][nx] != -1) continue;
        
        visited[ny][nx] = true;
        temp.push_back(n);
        
        // 현재 선택한 학생이 임도연파인 경우
        if(seat[ny][nx] == 1) select(n, num + 1, numY + 1);
        else select(n, num + 1, numY);

        visited[ny][nx] = false;
        temp.pop_back();
    }
}

int main(){
    FILE *stream =freopen("S2\\37\\input\\1941.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int r = 0; r <= 6; r++){
        for(int c = 0; c <= 6; c++){
            if(r == 0 || c == 0 || r == 6 || c == 6){
                seat[r][c] = -1;
            }
            char temp;
            cin >> temp;
            if(temp == 'S') seat[r][c] = 0;
            else seat[r][c] = 1;
        }
    }


    for(int r = 1; r <= 5; r++){
        for(int c = 1; c <= 5; c++){
            Coord temp_c = {r, c};
            select(temp_c, 0, 0);
        }
    }


    cout << kinds.size();

    return 0;
}
