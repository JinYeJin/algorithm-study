/*
연구소 문제
벽을 정확히 3개 세우고 ,  안전영역크기의 최댓값을 구하라.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M; //세로 , 가로 크기
int ary[8][8];
vector<pair<int, int>> wall_vec;//벽을 세울경우 벽의 좌표
vector<pair<int, int>> virus_vec;
bool map[8][8];//이미 방문한 곳인지 판단하는 map .  초기화는 false    false 방문안한곳
int maxv = 0;
int dist[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int minv = 64; //BFS효율성을 올리기 위함
int wall_num = 0;
void In() {
	cin >> N >> M;
	int a;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> a;
			if (a == 2) 
				virus_vec.push_back(pair<int, int>(i, j));
			else if (a == 1) 
				wall_num++;

			ary[i][j] = a;

		}
}
bool isinside(int i, int j) {
	if (i >= 0 && i < N && j >= 0 && j < M)
		return true;
	else
		return false;
}
int bfs() {
	int cnt2 = 0;
	bool flag_buf = false;

	//ary를 임시로 변경
	vector<pair<int, int>>::iterator iter;
	for (iter = wall_vec.begin(); iter != wall_vec.end(); iter++)
		ary[(*iter).first][(*iter).second] = 1;

	//만든 벽 안에서 바이러스가 퍼지게하기	
	queue<pair<int, int>> qu;
	for (iter = virus_vec.begin(); iter != virus_vec.end(); iter++) {
		qu.push(pair<int, int>((*iter).first, (*iter).second));
		map[(*iter).first][(*iter).second] = true;
		cnt2++;
	}

	while (!qu.empty()) {
		int curi = qu.front().first;
		int curj = qu.front().second;
		qu.pop();

		//중간탈출문
		if (cnt2 >= minv) {
			flag_buf = true;
			break;
		}

		//4방향
		for (int tp = 0; tp < 4; tp++) {
			int nexti = curi + dist[tp][0];
			int nextj = curj + dist[tp][1];

			//범위 안에 있는지 ,갈려고하는곳이 0인지 , 방문한 적(map) 이 없는지
			if (isinside(nexti, nextj) && ary[nexti][nextj] == 0 && map[nexti][nextj] == false)
			{
				map[nexti][nextj] = true;//방문함으로 표시
				qu.push(pair<int, int>(nexti, nextj));
				cnt2++;
			}
		}
	}

	//bfs 중간탈출문을 위한 갱신명령어
	if (cnt2 < minv)
		minv = cnt2;

	int cnt = 0;
	if (flag_buf == false) 
		cnt = N * M - (cnt2 + wall_num + 3);//총영역갯수-  (퍼진바이러스수 + 기존에있던 벽의 수 + 3)
	
	//ary를 다시 복구시키고 ,   map을 false로 초기화시키기
	for (iter = wall_vec.begin(); iter != wall_vec.end(); iter++)
		ary[(*iter).first][(*iter).second] = 0;
	memset(map, 0, sizeof(map));

	return cnt;
}
void dfs() {  //벽3개를 만드는 모든경우 만들기
	//벽이 3개가 되면 만족. bfs 진행 .
	if ((int)wall_vec.size() == 3) {
		

		int buf = bfs();
		if (buf > maxv)
			maxv = buf;
		return;
	}


	int i = 0;
	int j = 0;
	bool flag = false;
	if (wall_vec.size() != 0) {
		if (wall_vec.back().second + 1 < M)//열이 범위 안에 있는가      
			j = wall_vec.back().second + 1;
		else//열이 범위 밖인가
		{
			j = 0;
			i = wall_vec.back().first + 1;
		}
		flag = true;
	}
	//진행 
	for (; i < N; i++) {
		if (flag == false) {
			j = 0;
		}
		else
		{
			flag = false;
		}
		for (; j < M; j++) {
			if (ary[i][j] == 0) {

				wall_vec.push_back(pair<int, int>(i, j));
				dfs();

				//복원
				wall_vec.pop_back();
			}
		}
	}


}
int main()
{
	ios_base::sync_with_stdio(false);

	In();
	dfs();
	cout << maxv;
}
