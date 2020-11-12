#include <iostream>
#include <queue>

using namespace std;

class coord {
public:
	int i, j;
	int ori;
	coord(int i_, int j_, int ori_) : i(i_), j(j_), ori(ori_) {}
};
int N, M;
int map[50][50];
int dist[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };//북 동  남 서  반시계방향            0 1 2 3               
bool check[50][50];
int cnt;//청소된 구역수
queue<coord> robot_qu;
void In() {
	int roboti, robotj, ori;
	cin >> N >> M;
	cin >> roboti >> robotj >> ori;

	//로봇위치
	robot_qu.push(coord(roboti,robotj,ori));
	cnt++;//청소된 구역수
	check[roboti][robotj] = true;//로봇 위치 청소.

	for(int i=0; i<N ; i++)
		for (int j = 0; j < M; j++) 
			cin >> map[i][j];
		
}

bool cleaned_wall(int curi, int curj) {
	int tp;
	for (tp = 0; tp < 4; tp++) {
		int nexti = curi + dist[tp][0];
		int nextj = curj + dist[tp][1];
		if (check[nexti][nextj] == true || map[nexti][nextj] == 1)
			continue;
		else
			break;
	}
	//네 방향 모두 청소가 이미 되어있거나 벽인 경우에는  tp가 4 나옴
	if (tp == 4)
		return true;//네 방향 모두 청소가 이미 되어있거나 벽인 경우
	else
		return false;

}
void bfs() {
	while (!robot_qu.empty()) {
		int curi = robot_qu.front().i;
		int curj = robot_qu.front().j;
		int curori = robot_qu.front().ori;
		robot_qu.pop();

		while (1) {
		//방향
		int nextori = (curori - 1) >= 0 ? (curori - 1) : 3;//왼쪽방향 탐색  
		int nexti;
		int nextj;
		int back = (curori - 2) >= 0 ? curori - 2 : curori + 2;//후진방향

			
			//네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
			if (cleaned_wall(curi, curj) && map[curi + dist[back][0]][curj + dist[back][1]] == 1)
			return;
			//네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
			else if (cleaned_wall(curi, curj))
			{
				curi = curi + dist[back][0];
				curj = curj + dist[back][1];
				continue;
			}
			//왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
			//nextori 가 빈칸이고 , check값이 false이면 
			else if (map[curi + dist[nextori][0]][curj + dist[nextori][1]] == 0 && check[curi + dist[nextori][0]][curj + dist[nextori][1]] == false) {
				nexti = curi + dist[nextori][0];
				nextj = curj + dist[nextori][1];
				robot_qu.push(coord(nexti, nextj, nextori));
				check[nexti][nextj] = true;//위치 청소
				cnt++;
				break;
			}
			//왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
			//check가 true or map이 벽이면 
			else if (check[curi + dist[nextori][0]][curj + dist[nextori][1]]==true || map[curi + dist[nextori][0]][curj + dist[nextori][1]]==1) {
				curori = nextori;
				continue;
			}
			
		}
	}
	
}
int main() {
	In();

	bfs();


	cout << cnt;
}