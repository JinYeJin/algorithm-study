//BFS로 품
/*
토마토 문제
정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다.
며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성.


 만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고,
 토마토가 모두 익지는 못하는 상황이면 -1을 출력해야 한다.
*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int M, N;  // 가로칸의수 , 세로칸의수
int tomato_box[1000][1000];
int tomato_map[1000][1000];//이미 익은토마토와 비어있는 위치는 0으로 표시함.   -1은 덜익은 토마토로써 탐색가능한곳이고 , 그외의 값은 이미 탐색한 곳으로 침 
int dist[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
queue<pair<int, int>> qu;
void In() {
	cin >> M >> N;
	int a;
	for(int i=0; i< N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> a;
			
			if (a == 1) {
				qu.push(pair<int, int>(i, j));
				tomato_map[i][j] = 0;
			}
			else if(a == -1) {
				tomato_map[i][j] = 0;
			}

			tomato_box[i][j] = a;
		}
}
bool isinside(int i, int j) {
	if (i >= 0 && i < N && j >= 0 && j < M)
		return true;
	else
		return false;
}
void bfs() {
	
	while(!qu.empty())
	{
		int curi = qu.front().first;
		int curj = qu.front().second;
		qu.pop();
		
		for (int tp = 0; tp < 4; tp++)
		{
			int nexti = curi + dist[tp][0];
			int nextj = curj + dist[tp][1];

			//범위 안에 있는가, 덜익은 토마토인가, 
			if (isinside(nexti, nextj) && tomato_map[nexti][nextj] == -1) {
				tomato_map[nexti][nextj] = tomato_map[curi][curj] + 1;
				qu.push(pair<int,int>(nexti, nextj));
			}
		}

	}
}//-> bfs의 결과로 나오는 tomato_map에서 가장 큰값이   전부 익는데 걸리는 최소 일수임
int main()
{
	ios_base::sync_with_stdio(false);// 240ms-> 92ms 로 감소
	memset(tomato_map, -1, sizeof(tomato_map));
	In();
	bfs();
	
	//토마토가 모두 익지는 못하는 상황이면 - 1을 출력	                        ->     tomato_map 에서 -1(덜익은토마토) 이 있으면 ,  -1 출력
	//만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력              ->     tomato_map 에서 전부 0 이면 , 0출력
	//기본) tomato_map 에서 가장큰 값 출력  (모든토마토가 익는데 걸리는 최소일자)
	bool flag = false;
	int maxv = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (tomato_map[i][j] == -1) {
				cout << -1;
				return 0;
			}
			else
			{
				if (tomato_map[i][j] > maxv)
					maxv = tomato_map[i][j];
			}
				
		}
	
	cout << maxv;
	return 0;
}
