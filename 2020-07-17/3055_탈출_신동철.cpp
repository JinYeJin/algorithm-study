//BFS로 해결
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
class coord{
public:
	int i, j;
	char wh;
	coord() :i(NULL), j(NULL), wh(NULL) {}//기본생성자
	coord(int i_,int j_,char wh_):i(i_),j(j_),wh(wh_) {}
};
int R, C;
char map[50][50];
int check[50][50];//지나온길,최소거리체크
coord gosum;//고슴도치
queue<coord> qu;
int dist[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
bool disturb(int i ,int j,bool flag) {//flag==false curi,curj가 물 일 경우 , true는 고슴도치 
		if (0 <= i && i < R && 0 <= j && j < C)//범위만족여부
		{
			if (flag == false) {//물
				if (map[i][j] != 'X' && map[i][j] != 'D')
					return false;
				else
					return true;
			}
			else {//고슴도치
				if (map[i][j] != '*' && map[i][j] != 'X')
					return false;
				else
					return true;
			}

		}
		else
			return true;
}
void bfs() {
	while (!qu.empty()) {
		int curi = qu.front().i;
		int curj = qu.front().j;
		char curwh = qu.front().wh;
		qu.pop();

		for (int tp = 0; tp < 4; tp++)//4방향
		{
			int nexti = curi + dist[tp][0];
			int nextj = curj + dist[tp][1];
			if (curwh== '*' && disturb(nexti,nextj,false) == false && map[nexti][nextj] != '*')//현재 위치가 물이고, 다음방향이 벽이나 바위,소굴이 아니고, 처음 오는 길이면; 범람
			{
				map[nexti][nextj] = '*';
				qu.push(coord(nexti,nextj,'*'));
			}
			else if(curwh=='S' && disturb(nexti,nextj,true) ==false && check[nexti][nextj]==-1)//현재 위치가 고슴도치이고 , 가려는 방향이 벽 , 물,바위가 아니고,처음가는곳이면 갈수있음      
			{
				check[nexti][nextj] = check[curi][curj] + 1;
				qu.push(coord(nexti, nextj, 'S'));
				if (map[nexti][nextj] == 'D')//비버의 굴을 만난 경우  (중간탈출문)
				{
					cout << check[nexti][nextj];
					return;
				}
			}
		}
	}
	cout << "KAKTUS";
}
int main() {
	//입력
	memset(check, -1, sizeof(check));
	cin >> R >> C;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> map[r][c];
			if (map[r][c] == '*')//물
				qu.push(coord(r, c, '*'));
			else if (map[r][c] == 'S')//고슴도치
			{
				gosum = coord(r, c, 'S');
				check[r][c] = 0;//고슴도치  출발점 check 0으로 설정
			}
		}
	}
	qu.push(gosum);//마지막에 고슴도치 첨가
	//계산
	bfs();

}