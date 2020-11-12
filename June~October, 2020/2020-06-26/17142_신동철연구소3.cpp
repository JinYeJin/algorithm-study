//dfs, bfs�� �ذ�
// dfs ��¥�� �Ѵٴ� ���� �ѹ��� ����.
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int map[50][50];
int wall_num;
vector<pair<int, int>> pos_virus_vec;
vector<pair<int, int>> selected_virus;
int dist[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int check[50][50];
int min_day = 2500;

//�׽�Ʈ��
int cntx = 0;
//
void In() {
	cin >> N >> M;

	for(int i=0; i<N ; i++)
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				pos_virus_vec.push_back(pair<int,int>(i,j));
			else if (map[i][j] == 1)
				wall_num++;
		}
}
bool isinside(int i, int j) {
	if (i >= 0 && i < N && j >= 0 && j < N)
		return true;
	else
		return false;
}
int bfs() {
	int accumulated_virus = 0;
	int maxv = 0;
	queue<pair<int, int>> qu;
	vector<pair<int, int>>::iterator iter;
	for (iter = selected_virus.begin(); iter != selected_virus.end(); iter++) {
		qu.push(pair<int, int>((*iter).first, (*iter).second));
		check[(*iter).first][(*iter).second] = 0;//���õ� ���̷����� 0 �� ����       ���þȵȹ��̷����� �״�� -1 ��.       map������ �Ѵ� 2��.
	}
	
	while (!qu.empty()) {
		int curi = qu.front().first;
		int curj = qu.front().second;
		qu.pop();

		//�߰�Ż�⹮  �ð�����
		if (min_day < maxv)
			return 0;

		for (int tp = 0; tp < 4; tp++) {
			int nexti = curi + dist[tp][0];
			int nextj = curj + dist[tp][1];

			//���� �ȿ� �ִ°� , ó�� �湮�ϴ� ���ΰ� , ���̾ƴѰ�
			if (isinside(nexti, nextj) && check[nexti][nextj] == -1 && map[nexti][nextj] != 1) {
				
				//��ĭ or ��Ȱ��ȭ�� ���̷��� �ϰ��
				check[nexti][nextj] = check[curi][curj] + 1;

				if (map[nexti][nextj] == 0)
				{
					accumulated_virus++; //��ĭ�� ���� ���̷��� ����
					if (maxv < check[nexti][nextj]) //���̷��� ������ ��¥ ����    ��Ȱ�����̷����� ���ſ��� ������.
						maxv = check[nexti][nextj];
				}
				qu.push(pair<int, int>(nexti,nextj ));
			
			}

		}
	}

	int b = N * N - (wall_num + (int)pos_virus_vec.size() + accumulated_virus);
	if (b != 0)//���̷����� �����µ��� �ұ��ϰ� ��ĭ�� �����Ѵٴ� ����
		return -1;
	else
		return maxv;
}
void dfs(int index) {
	//�˻�
	if ((int)selected_virus.size() == M)
	{
		int value;
		value= bfs();
		//����������     value==0 �� ���� �ǹ̴� �߰�Ż�⹮�� ���ؼ� Ż��� ����
		if (value != 0 && value != -1) {
			if (min_day > value)
				min_day = value;
		}

		//�ʱ�ȭ  check
		memset(check, -1, sizeof(check));
		return;
	}

	//����
	for (int tp = 0 + index; tp < (int)pos_virus_vec.size(); tp++) {
		selected_virus.push_back(pos_virus_vec[tp]);
		dfs(tp+1);   // ���� dfs ó��������  ��ó���ؾ���. �̰� ������ �ѹ� Ʋ�Ⱦ���.
		//����
		selected_virus.pop_back();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);// 12ms
	cin.tie(NULL);
	cout.tie(NULL);

	memset(check, -1, sizeof(check));
	In();
	//����ó��
	if ((N * N - (wall_num + (int)pos_virus_vec.size())) == 0) {
		cout << '0';
		return 0;
	}
	dfs(0);

	if (min_day == 2500)
		cout << -1;
	else
		cout << min_day;
}