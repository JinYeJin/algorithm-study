/*
���ϻ��� ����

���ϻ����� �ƴ� ����� ���� ���� ������ ������ ���ϻ����� ����� ���� ���� ������ ���� �������� ������ ���
*/
#include <iostream>
#include <queue>

using namespace std;

int N;
char ary1[100][100];
char ary2[100][100];
int dist[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
bool check1[100][100];
bool check2[100][100];
int cnt1 = 0;
int cnt2 = 0;
void In() {
	cin >> N;
	char a;
	for( int i=0; i<N ; i++ )
		for (int j = 0; j < N; j++)
		{
			cin >> a;
			ary1[i][j] = a;
			if (a == 'G')//G�� ���� R�� ����
				ary2[i][j] = 'R';
			else
				ary2[i][j] = a;
		}
}
bool isinside(int i, int j)
{
	if (i >= 0 && i < N && j >= 0 && j < N)
		return true;
	else
		return false;
}
void bfs(int i ,int j,char ary[][100],bool check[][100]) {
	queue<pair<int, int>> qu;
	qu.push(pair<int, int>(i, j));
	check[i][j] = true;//�湮 �������� ǥ��

	while (!qu.empty()) {
		int curi = qu.front().first;
		int curj = qu.front().second;
		qu.pop();
		for (int tp = 0; tp < 4; tp++) {
			int nexti = curi + dist[tp][0];
			int nextj = curj + dist[tp][1];

			//�����ȿ� �ִ°�, ó���湮�ϴ� ���ΰ� ,  (curi,curj)�� �����ִ� ���� ���� ���ΰ�
			if (isinside(nexti, nextj) && check[nexti][nextj] == false && ary[curi][curj] == ary[nexti][nextj]) {
				check[nexti][nextj] = true;//�̹� �湮 �������� ǥ��
				qu.push(pair<int,int>(nexti,nextj));
			}
			
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	In();
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {

			if (check1[i][j] == false) {
				bfs(i,j,ary1,check1);
				cnt1++;
			}

			if (check2[i][j] == false) {
				bfs(i, j,ary2,check2);
				cnt2++;
			}
		}

	cout << cnt1 << ' ' << cnt2;
}