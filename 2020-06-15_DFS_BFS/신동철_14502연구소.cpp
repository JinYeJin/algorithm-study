/*
������ ����
���� ��Ȯ�� 3�� ����� ,  ��������ũ���� �ִ��� ���϶�.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M; //���� , ���� ũ��
int ary[8][8];
vector<pair<int, int>> wall_vec;//���� ������ ���� ��ǥ
vector<pair<int, int>> virus_vec;
bool map[8][8];//�̹� �湮�� ������ �Ǵ��ϴ� map .  �ʱ�ȭ�� false    false �湮���Ѱ�
int maxv = 0;
int dist[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int minv = 64; //BFSȿ������ �ø��� ����
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

	//ary�� �ӽ÷� ����
	vector<pair<int, int>>::iterator iter;
	for (iter = wall_vec.begin(); iter != wall_vec.end(); iter++)
		ary[(*iter).first][(*iter).second] = 1;

	//���� �� �ȿ��� ���̷����� �������ϱ�	
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

		//�߰�Ż�⹮
		if (cnt2 >= minv) {
			flag_buf = true;
			break;
		}

		//4����
		for (int tp = 0; tp < 4; tp++) {
			int nexti = curi + dist[tp][0];
			int nextj = curj + dist[tp][1];

			//���� �ȿ� �ִ��� ,�������ϴ°��� 0���� , �湮�� ��(map) �� ������
			if (isinside(nexti, nextj) && ary[nexti][nextj] == 0 && map[nexti][nextj] == false)
			{
				map[nexti][nextj] = true;//�湮������ ǥ��
				qu.push(pair<int, int>(nexti, nextj));
				cnt2++;
			}
		}
	}

	//bfs �߰�Ż�⹮�� ���� ���Ÿ�ɾ�
	if (cnt2 < minv)
		minv = cnt2;

	int cnt = 0;
	if (flag_buf == false) 
		cnt = N * M - (cnt2 + wall_num + 3);//�ѿ�������-  (�������̷����� + �������ִ� ���� �� + 3)
	
	//ary�� �ٽ� ������Ű�� ,   map�� false�� �ʱ�ȭ��Ű��
	for (iter = wall_vec.begin(); iter != wall_vec.end(); iter++)
		ary[(*iter).first][(*iter).second] = 0;
	memset(map, 0, sizeof(map));

	return cnt;
}
void dfs() {  //��3���� ����� ����� �����
	//���� 3���� �Ǹ� ����. bfs ���� .
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
		if (wall_vec.back().second + 1 < M)//���� ���� �ȿ� �ִ°�      
			j = wall_vec.back().second + 1;
		else//���� ���� ���ΰ�
		{
			j = 0;
			i = wall_vec.back().first + 1;
		}
		flag = true;
	}
	//���� 
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

				//����
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