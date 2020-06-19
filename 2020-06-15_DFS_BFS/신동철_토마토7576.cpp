//BFS�� ǰ
/*
�丶�� ����
���� 1�� ���� �丶��, ���� 0�� ���� ���� �丶��, ���� -1�� �丶�䰡 ������� ���� ĭ�� ��Ÿ����.
��ĥ�� ������ �丶����� ��� �ʹ���, �� �ּ� �ϼ��� ���ϴ� ���α׷��� �ۼ�.


 ����, ����� ������ ��� �丶�䰡 �;��ִ� �����̸� 0�� ����ؾ� �ϰ�,
 �丶�䰡 ��� ������ ���ϴ� ��Ȳ�̸� -1�� ����ؾ� �Ѵ�.
*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int M, N;  // ����ĭ�Ǽ� , ����ĭ�Ǽ�
int tomato_box[1000][1000];
int tomato_map[1000][1000];//�̹� �����丶��� ����ִ� ��ġ�� 0���� ǥ����.   -1�� ������ �丶��ν� Ž�������Ѱ��̰� , �׿��� ���� �̹� Ž���� ������ ħ 
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

			//���� �ȿ� �ִ°�, ������ �丶���ΰ�, 
			if (isinside(nexti, nextj) && tomato_map[nexti][nextj] == -1) {
				tomato_map[nexti][nextj] = tomato_map[curi][curj] + 1;
				qu.push(pair<int,int>(nexti, nextj));
			}
		}

	}
}//-> bfs�� ����� ������ tomato_map���� ���� ū����   ���� �ʹµ� �ɸ��� �ּ� �ϼ���
int main()
{
	ios_base::sync_with_stdio(false);// 240ms-> 92ms �� ����
	memset(tomato_map, -1, sizeof(tomato_map));
	In();
	bfs();
	
	//�丶�䰡 ��� ������ ���ϴ� ��Ȳ�̸� - 1�� ���	                        ->     tomato_map ���� -1(�������丶��) �� ������ ,  -1 ���
	//����, ����� ������ ��� �丶�䰡 �;��ִ� �����̸� 0�� ���              ->     tomato_map ���� ���� 0 �̸� , 0���
	//�⺻) tomato_map ���� ����ū �� ���  (����丶�䰡 �ʹµ� �ɸ��� �ּ�����)
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