//BFS로 품
//이전 토마토 문제랑 거의 유사.
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int M, N, H;  // 가로칸의수 , 세로칸의수 , 상자높이수 
int tomato_box[100][100][100];//3차원배열     각 인덱스는  (상자높이,행,열)을 의미 
int tomato_map[100][100][100];//이미 익은토마토와 비어있는 위치는 0으로 표시함.   -1은 덜익은 토마토로써 탐색가능한곳이고 , 그외의 값은 이미 탐색한 곳으로 침 
int dist[6][3] = { {0,1,0},{0,-1,0},{0,0,1},{0,0,-1},{1,0,0},{-1,0,0} };

class cord {
public:
	int h;
	int i;
	int j;
	
	cord(int h_,int i_, int j_) : h(h_),i(i_),j(j_)   {}
};
queue<cord> qu;//이미익은 토마토 좌표가 선두로 들어감.

void In() {
	cin >> M >> N >> H;
	int a;
	for(int h = 0; h < H ; h++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
			{
				cin >> a;

				if (a == 1) {
					qu.push(cord(h,i,j));
					tomato_map[h][i][j] = 0;
				}
				else if (a == -1) {
					tomato_map[h][i][j] = 0;
				}
				tomato_box[h][i][j] = a;
			}
}

bool isinside(int h,int i, int j) {
	if (h>=0 && h<H && i >= 0 && i < N && j >= 0 && j < M)
		return true;
	else
		return false;
}

void bfs() {

	while (!qu.empty())
	{
		int curh = qu.front().h;
		int curi = qu.front().i;
		int curj = qu.front().j;
		qu.pop();

		for (int tp = 0; tp < 6; tp++)
		{
			int nexth = curh + dist[tp][0];
			int nexti = curi + dist[tp][1];
			int nextj = curj + dist[tp][2];

			//범위 안에 있는가, 처음가보는 곳인가 , 
			if ( isinside( nexth , nexti, nextj) && tomato_map[nexth][nexti][nextj] == -1 ) {
				tomato_map[nexth][nexti][nextj] = tomato_map[curh][curi][curj] + 1;
				qu.push(cord(nexth,nexti,nextj));
			}
		}

	}
}
int main()
{
	ios_base::sync_with_stdio(false);// 240ms-> 92ms 로 감소
	memset(tomato_map, -1, sizeof(tomato_map));
	In();
	bfs();

	//tomato_map 에서 -1 이 있으면 ,  -1 출력
	//tomato_map 에서 전부 0 이면 , 0출력
	//기본) tomato_map 에서 가장큰 값 출력
	bool flag = false;
	int maxv = 0;
	for (int h = 0; h < H; h++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) {
				if (tomato_map[h][i][j] == -1) {
					cout << -1;
					return 0;
				}
				else
				{
					if (tomato_map[h][i][j] > maxv)
						maxv = tomato_map[h][i][j];
				}

			}

	cout << maxv;
	return 0;
}
