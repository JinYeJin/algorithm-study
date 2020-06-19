//BFS�� ǰ
//���� �丶�� ������ ���� ����.
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int M, N, H;  // ����ĭ�Ǽ� , ����ĭ�Ǽ� , ���ڳ��̼� 
int tomato_box[100][100][100];//3�����迭     �� �ε�����  (���ڳ���,��,��)�� �ǹ� 
int tomato_map[100][100][100];//�̹� �����丶��� ����ִ� ��ġ�� 0���� ǥ����.   -1�� ������ �丶��ν� Ž�������Ѱ��̰� , �׿��� ���� �̹� Ž���� ������ ħ 
int dist[6][3] = { {0,1,0},{0,-1,0},{0,0,1},{0,0,-1},{1,0,0},{-1,0,0} };

class cord {
public:
	int h;
	int i;
	int j;
	
	cord(int h_,int i_, int j_) : h(h_),i(i_),j(j_)   {}
};
queue<cord> qu;//�̹����� �丶�� ��ǥ�� ���η� ��.

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

			//���� �ȿ� �ִ°�, ó�������� ���ΰ� , 
			if ( isinside( nexth , nexti, nextj) && tomato_map[nexth][nexti][nextj] == -1 ) {
				tomato_map[nexth][nexti][nextj] = tomato_map[curh][curi][curj] + 1;
				qu.push(cord(nexth,nexti,nextj));
			}
		}

	}
}
int main()
{
	ios_base::sync_with_stdio(false);// 240ms-> 92ms �� ����
	memset(tomato_map, -1, sizeof(tomato_map));
	In();
	bfs();

	//tomato_map ���� -1 �� ������ ,  -1 ���
	//tomato_map ���� ���� 0 �̸� , 0���
	//�⺻) tomato_map ���� ����ū �� ���
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