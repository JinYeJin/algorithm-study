//�ִܰŸ� Ž���������� BFS�� �ذ�.
#include <iostream>
#include <queue>
#include <deque>
#include <cstring>
using namespace std;
int N;
int map[20][20];
int fish = 0;
queue<pair<int, int>> qu;
deque<pair<int, int>> fish_dq;
int dist[4][2] = { {-1,0},{0,-1},{0,1},{1,0} };//�� , �� , ��, ��    �̰ɷ� ������ ������������.  ��Ȥ
int check[20][20];
int cnt_sum = 0;
void In() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 9) {
				fish++;
				fish_dq.push_back(pair<int, int>(i, j));
			}
			if (map[i][j] == 9) {
				map[i][j] = 0;// ���⼭ ���Ʋ����. 
				qu.push(pair<int, int>(i, j));
			}
		}
}
bool isinside(int i, int j) {
	if (i >= 0 && i < N && j >= 0 && j < N)
		return true;
	else
		return false;
}
void bfs() {
	int shark_i = qu.front().first;
	int shark_j = qu.front().second;
	int shark_size = 2;
	int cnt = 2;
	int min_dist = 400;
	check[shark_i][shark_j] = 0;


	do {
		min_dist = 400;

		//����ó��) ���� �������� 0�϶� ����
		if (fish == 0)
			return;

		while (!qu.empty()) {
			int curi = qu.front().first;
			int curj = qu.front().second;
			qu.pop();

			for (int tp = 0; tp < 4; tp++) {
				int nexti = curi + dist[tp][0];
				int nextj = curj + dist[tp][1];

				//���� �ȿ� �ִ���, ó���湮 �ϴ°����� , �Ʊ����� ũ�Ⱑ ������̻��� ���
				if (isinside(nexti, nextj) && check[nexti][nextj] == -1 && shark_size >= map[nexti][nextj]) {
					//����⸦ ���� ���� �ִ� ���
					if ((map[nexti][nextj] != 0) && (shark_size > map[nexti][nextj])) {

						check[nexti][nextj] = check[curi][curj] + 1;
						qu.push(pair<int, int>(nexti, nextj));
						if (min_dist > check[nexti][nextj])//�ּҰ� ����
							min_dist = check[nexti][nextj];
					}

					//����⸦ �ȸ��� ��� , ��ĭ�� ���
					else {
						check[nexti][nextj] = check[curi][curj] + 1;
						qu.push(pair<int, int>(nexti, nextj));
					}
				}
			}
		}
		//�Ÿ��� ���尡���� ���� �Ұ�츦 ó���ϱ����ؼ� ������� ���������� �˻��Ѵ�.
		deque<pair<int, int>>::iterator iter;
		for (iter = fish_dq.begin(); iter != fish_dq.end(); iter++) {
			int i = (*iter).first;
			int j = (*iter).second;
			if (min_dist == check[i][j] && map[i][j] < shark_size) {
				cnt--;
				fish--;
				cnt_sum += min_dist;
				if (cnt == 0) {
					shark_size++;
					cnt = shark_size;
				}

				map[i][j] = 0;
				memset(check, -1, sizeof(check));
				check[i][j] = 0;
				qu.push(pair<int, int>(i, j));
				fish_dq.erase(iter);//, fish_dq�� �ش���ǥ�����

				break;

			}
		}

	} while (min_dist != 400);

}
int main()
{
	ios_base::sync_with_stdio(false);
	In();
	//�ʱ�ȭ
	memset(check, -1, sizeof(check));
	bfs();
	cout << cnt_sum;
}