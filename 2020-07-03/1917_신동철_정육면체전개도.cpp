//�޸��ʰ�  ����.
//�˰����� ������ �������� �ʾƼ� https://blog.naver.com/newprog/221863627726 ���⿡�� ��Ʈ�� ����
//� ���� ������ ���� �������� �ι� �������� ����  ���ֺ��� ���̴�. <- �̰��̿�
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

class coord {
public:
	int i, j;
	coord(int i_,int j_) :i(i_),j(j_) {}
};

int map1[6][6];
int map2[6][6];
int map3[6][6];
int dist[4][2] = { {0,1},{0,-1},{1,0},{-1,0} }; //�� , �� , �� , ��
bool check[6][6];//��
bool bcheck[6][6];//��
queue<coord> qu1,qu2,qu3;


void In() {
	for(int i=0; i<=5 ; i++)
		for (int j = 0; j <= 5; j++) {
			cin >> map1[i][j];
			if (map1[i][j] == 1)
				qu1.push(coord(i,j));
		}
		
	for (int i = 0; i <= 5; i++)
		for (int j = 0; j <= 5; j++) {
			cin >> map2[i][j];
			if (map2[i][j] == 1)
				qu2.push(coord(i, j));
		}

	for (int i = 0; i <= 5; i++)
		for (int j = 0; j <= 5; j++) {
			cin >> map3[i][j];
			if (map3[i][j] == 1)
				qu3.push(coord(i, j));
		}
}
bool isinside(int i, int j) {
	if (i >= 0 && i <= 5 && j >= 0 && j <= 5)
		return true;
	else
		return false;
}
int bfs(int i,int j,int map_[][6]) {

	int cnt = 0;

	//bcheck�˻�
	if (bcheck[i][j] == true)
		return 0;

	//ù�κ��� �湮������ ǥ��
	check[i][j] = true;//�̹� �湮������ ǥ��
	bcheck[i][j] = true;

	//bfs ������ ���� qu
	queue<coord> qu;

	//�����ϴ� ���� ������ ����˻� �� �ʱ�ȭ
	int way[4] = {0,};

	for (int tp = 0; tp < 4; tp++) {  //�����ϴ� �鿡�� ������ ���� �˾Ƴ���
		int nexti = i + dist[tp][0];
		int nextj = j + dist[tp][1];

		//���� ���ִ°� , ���� �ִ°�
		if (isinside(nexti,nextj) &&map_[nexti][nextj] == 1) {
			way[tp]++; //������ ������ 1���� ó����.
			qu.push(coord(nexti, nextj));
			check[nexti][nextj] = true;
		}
	}

	
	//bfs�� ������, way[?] ���� 0�� ���� ť�� ���, wav[?]���� 1�ΰ�� �� �� �������� �������� �װ� �������°���.
	while (!qu.empty()) {
		int curi = qu.front().i;
		int curj = qu.front().j;
		qu.pop();

		for (int tp = 0; tp < 4; tp++) {
			int nexti = curi + dist[tp][0];
			int nextj = curj + dist[tp][1];


			//���� ���ΰ�, ó�� �湮�ϴ� ���ΰ�, ���� �ִ°�
			if (isinside(nexti, nextj) && check[nexti][nextj] == false && map_[nexti][nextj] == 1)
			{
				//tp ���⿡�� way[tp]����1 �ΰ�� 
				if (way[tp] == 1) {
					cnt++;
					check[nexti][nextj] = true;//�湮������ ǥ��
					//way[tp]�� 1 ��  nexti,nextj ���� bcheck���� ó���湮 �ϴ� ���̶��
					if (bcheck[nexti][nextj]==false) {
						bcheck[nexti][nextj] = true;
					}
					//���� ���� ���� �����.
					else if (bcheck[nexti][nextj] == true) {
						cout << "no" << '\n';
						return 1;//������ü�� �ƴҶ� 1���
					}
					
					qu.push(coord(nexti, nextj)); 
				}
				else
					//else ��� , �ܼ��� ť÷���� �湮����ǥ��
				{
					qu.push(coord(nexti, nextj));
					check[nexti][nextj] = true;
				}
			}
		}

	}
	if (cnt != 1) {
		cout << "no" << '\n';
		return 1;//������ü�� �ƴҶ� 1���
	}
	else
		return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	In();
	int i;
	int j;
	while (!qu1.empty()) {
		int a=bfs(qu1.front().i, qu1.front().j, map1);
		qu1.pop();

		if (a == 1)
			break;
		if (qu1.size() == 0)
			cout << "yes"<<'\n';
	}
	memset(bcheck, 0, sizeof(bcheck));//check�ʱ�ȭ


	while (!qu2.empty()) {
		memset(check, 0, sizeof(check));//check�ʱ�ȭ
		int a = bfs(qu2.front().i, qu2.front().j, map2);
		qu2.pop();

		if (a == 1)
			break;
		if (qu2.size() == 0)
			cout << "yes" << '\n';
	}
	memset(bcheck, 0, sizeof(bcheck));//check�ʱ�ȭ

	while (!qu3.empty()) {
		memset(check, 0, sizeof(check));//check�ʱ�ȭ
		int a = bfs(qu3.front().i, qu3.front().j, map3);
		qu3.pop();

		if (a == 1)
			break;
		if (qu3.size() == 0)
			cout << "yes" << '\n';
	}
}

/*
42��
//�˰����� ������ �������� �ʾƼ� https://blog.naver.com/newprog/221863627726 ���⿡�� ��Ʈ�� ����
//� ���� ������ ���� �������� �ι� �������� ����  ���ֺ��� ���̴�. <- �̰��̿�
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

class coord {
public:
	int i, j;
	coord(int i_,int j_) :i(i_),j(j_) {}
};

int map1[6][6];
int map2[6][6];
int map3[6][6];
int dist[4][2] = { {0,1},{0,-1},{1,0},{-1,0} }; //�� , �� , �� , ��
int check[6][6];//��
bool bcheck[6][6];//��
queue<coord> qu1,qu2,qu3;

/*
class square_side {
public:
	int top, bottom, left, right;
	bool used;
	square_side(int top_, int bottom_, int left_, int right_): top(top_), bottom(bottom_), left(left_), right(right_),used(false){}
};
void create_side() {
	//top

	//bottom
	//left-side
	//right-side
	//top-side
	//bottom-side
}

void In() {
	for (int i = 0; i <= 5; i++)
		for (int j = 0; j <= 5; j++) {
			cin >> map1[i][j];
			if (map1[i][j] == 1)
				qu1.push(coord(i, j));
		}

	for (int i = 0; i <= 5; i++)
		for (int j = 0; j <= 5; j++) {
			cin >> map2[i][j];
			if (map2[i][j] == 1)
				qu2.push(coord(i, j));
		}

	for (int i = 0; i <= 5; i++)
		for (int j = 0; j <= 5; j++) {
			cin >> map3[i][j];
			if (map3[i][j] == 1)
				qu3.push(coord(i, j));
		}
}
bool isinside(int i, int j) {
	if (i >= 0 && i <= 5 && j >= 0 && j <= 5)
		return true;
	else
		return false;
}
int bfs(int i, int j, int map_[][6]) {

	//bcheck�˻�
	if (bcheck[i][j] == true)
		return 0;

	//bfs ������ ���� qu
	queue<coord> qu;
	qu.push(coord(i, j));
	check[i][j] = 2;//�̹� �湮������ ǥ��
	bcheck[i][j] = true;

	//�����ϴ� ���� ������ ����˻�
	int way[4];
	memset(way, -1, sizeof(way));
	for (int tp = 0; tp < 4; tp++) {  //�����ϴ� �鿡�� ������ ���� �˾Ƴ���
		int nexti = i + dist[tp][0];
		int nextj = j + dist[tp][1];

		if (map_[nexti][nextj] == 1)
			way[tp]++; //������ ������ 0���� ó����.
	}

	bool flag = false;

	//bfs�� ������, way[?] ���� -1�� ���� �����ϰ�, �����°��� ������ ���� �ϳ��� �����Ͽ� , ���ʷ� 2�� �Ǵ� ���� ������ ����.
	while (!qu.empty()) {
		int curi = qu.front().i;
		int curj = qu.front().j;
		qu.pop();

		for (int tp = 0; tp < 4; tp++) {
			int nexti = curi + dist[tp][0];
			int nextj = curj + dist[tp][1];


			//���� ���ΰ�, ó�� �湮�ϴ� ���ΰ�, ���� �ִ°�
			if (isinside(nexti, nextj) && check[nexti][nextj] == 0 && map_[nexti][nextj] == 1)
			{
				//way[tp]���� -1�� �ƴѰ� -> way���� �� ť÷��
				if (way[tp] != -1) {
					way[tp]++;
					check[nexti][nextj] = 1;
					//way�˻�  flag���� bcheck����
					if (way[tp] == 2 && flag == false && bcheck[nexti][nextj] == false) {
						check[nexti][nextj] = 2;
						flag = true;
						bcheck[nexti][nextj] = true;
					}
					else if (way[tp] == 2 && flag == false && bcheck[nexti][nextj] == true) {
						cout << "no" << '\n';
						return 1;//������ü�� �ƴҶ� 1���
					}
					else if (way[tp] == 2 && flag == true) {
						cout << "no" << '\n';
						return 1;//������ü�� �ƴҶ� 1���
					}
					qu.push(coord(nexti, nextj));
				}
				else
					//else ��� , �ܼ��� ť÷���� �湮����ǥ��
				{
					qu.push(coord(nexti, nextj));
					check[nexti][nextj] = 1;
				}
			}
		}

	}
	return 0;//�������϶��� 0���
}
int main()
{
	ios_base::sync_with_stdio(false);
	In();
	int i;
	int j;
	while (!qu1.empty()) {

		int a = bfs(qu1.front().i, qu1.front().j, map1);
		qu1.pop();

		if (a == 1)
			break;
		memset(check, 0, sizeof(check));//check�ʱ�ȭ
		if (qu1.size() == 0)
			cout << "yes" << '\n';
	}
	memset(bcheck, 0, sizeof(bcheck));//check�ʱ�ȭ


	while (!qu2.empty()) {
		int a = bfs(qu2.front().i, qu2.front().j, map2);
		qu2.pop();

		if (a == 1)
			break;
		memset(check, 0, sizeof(check));//check�ʱ�ȭ
		if (qu2.size() == 0)
			cout << "yes" << '\n';
	}
	memset(bcheck, 0, sizeof(bcheck));//check�ʱ�ȭ

	while (!qu3.empty()) {
		int a = bfs(qu3.front().i, qu3.front().j, map3);
		qu3.pop();

		if (a == 1)
			break;
		memset(check, 0, sizeof(check));//check�ʱ�ȭ
		if (qu3.size() == 0)
			cout << "yes" << '\n';
	}
}
*/