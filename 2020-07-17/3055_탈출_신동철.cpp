//BFS�� �ذ�
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
class coord{
public:
	int i, j;
	char wh;
	coord() :i(NULL), j(NULL), wh(NULL) {}//�⺻������
	coord(int i_,int j_,char wh_):i(i_),j(j_),wh(wh_) {}
};
int R, C;
char map[50][50];
int check[50][50];//�����±�,�ּҰŸ�üũ
coord gosum;//����ġ
queue<coord> qu;
int dist[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
bool disturb(int i ,int j,bool flag) {//flag==false curi,curj�� �� �� ��� , true�� ����ġ 
		if (0 <= i && i < R && 0 <= j && j < C)//������������
		{
			if (flag == false) {//��
				if (map[i][j] != 'X' && map[i][j] != 'D')
					return false;
				else
					return true;
			}
			else {//����ġ
				if (map[i][j] != '*' && map[i][j] != 'X')
					return false;
				else
					return true;
			}

		}
		else
			return true;
}
void bfs() {
	while (!qu.empty()) {
		int curi = qu.front().i;
		int curj = qu.front().j;
		char curwh = qu.front().wh;
		qu.pop();

		for (int tp = 0; tp < 4; tp++)//4����
		{
			int nexti = curi + dist[tp][0];
			int nextj = curj + dist[tp][1];
			if (curwh== '*' && disturb(nexti,nextj,false) == false && map[nexti][nextj] != '*')//���� ��ġ�� ���̰�, ���������� ���̳� ����,�ұ��� �ƴϰ�, ó�� ���� ���̸�; ����
			{
				map[nexti][nextj] = '*';
				qu.push(coord(nexti,nextj,'*'));
			}
			else if(curwh=='S' && disturb(nexti,nextj,true) ==false && check[nexti][nextj]==-1)//���� ��ġ�� ����ġ�̰� , ������ ������ �� , ��,������ �ƴϰ�,ó�����°��̸� ��������      
			{
				check[nexti][nextj] = check[curi][curj] + 1;
				qu.push(coord(nexti, nextj, 'S'));
				if (map[nexti][nextj] == 'D')//����� ���� ���� ���  (�߰�Ż�⹮)
				{
					cout << check[nexti][nextj];
					return;
				}
			}
		}
	}
	cout << "KAKTUS";
}
int main() {
	//�Է�
	memset(check, -1, sizeof(check));
	cin >> R >> C;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> map[r][c];
			if (map[r][c] == '*')//��
				qu.push(coord(r, c, '*'));
			else if (map[r][c] == 'S')//����ġ
			{
				gosum = coord(r, c, 'S');
				check[r][c] = 0;//����ġ  ����� check 0���� ����
			}
		}
	}
	qu.push(gosum);//�������� ����ġ ÷��
	//���
	bfs();

}