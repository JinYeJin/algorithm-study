#include <iostream>
#include <queue>

using namespace std;

class coord {
public:
	int i, j;
	int ori;
	coord(int i_, int j_, int ori_) : i(i_), j(j_), ori(ori_) {}
};
int N, M;
int map[50][50];
int dist[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };//�� ��  �� ��  �ݽð����            0 1 2 3               
bool check[50][50];
int cnt;//û�ҵ� ������
queue<coord> robot_qu;
void In() {
	int roboti, robotj, ori;
	cin >> N >> M;
	cin >> roboti >> robotj >> ori;

	//�κ���ġ
	robot_qu.push(coord(roboti,robotj,ori));
	cnt++;//û�ҵ� ������
	check[roboti][robotj] = true;//�κ� ��ġ û��.

	for(int i=0; i<N ; i++)
		for (int j = 0; j < M; j++) 
			cin >> map[i][j];
		
}

bool cleaned_wall(int curi, int curj) {
	int tp;
	for (tp = 0; tp < 4; tp++) {
		int nexti = curi + dist[tp][0];
		int nextj = curj + dist[tp][1];
		if (check[nexti][nextj] == true || map[nexti][nextj] == 1)
			continue;
		else
			break;
	}
	//�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ��쿡��  tp�� 4 ����
	if (tp == 4)
		return true;//�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ���
	else
		return false;

}
void bfs() {
	while (!robot_qu.empty()) {
		int curi = robot_qu.front().i;
		int curj = robot_qu.front().j;
		int curori = robot_qu.front().ori;
		robot_qu.pop();

		while (1) {
		//����
		int nextori = (curori - 1) >= 0 ? (curori - 1) : 3;//���ʹ��� Ž��  
		int nexti;
		int nextj;
		int back = (curori - 2) >= 0 ? curori - 2 : curori + 2;//��������

			
			//�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���̸鼭, ���� ������ ���̶� ������ �� �� ���� ��쿡�� �۵��� �����.
			if (cleaned_wall(curi, curj) && map[curi + dist[back][0]][curj + dist[back][1]] == 1)
			return;
			//�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ��쿡��, �ٶ󺸴� ������ ������ ä�� �� ĭ ������ �ϰ� 2������ ���ư���.
			else if (cleaned_wall(curi, curj))
			{
				curi = curi + dist[back][0];
				curj = curj + dist[back][1];
				continue;
			}
			//���� ���⿡ ���� û������ ���� ������ �����Ѵٸ�, �� �������� ȸ���� ���� �� ĭ�� �����ϰ� 1������ �����Ѵ�.
			//nextori �� ��ĭ�̰� , check���� false�̸� 
			else if (map[curi + dist[nextori][0]][curj + dist[nextori][1]] == 0 && check[curi + dist[nextori][0]][curj + dist[nextori][1]] == false) {
				nexti = curi + dist[nextori][0];
				nextj = curj + dist[nextori][1];
				robot_qu.push(coord(nexti, nextj, nextori));
				check[nexti][nextj] = true;//��ġ û��
				cnt++;
				break;
			}
			//���� ���⿡ û���� ������ ���ٸ�, �� �������� ȸ���ϰ� 2������ ���ư���.
			//check�� true or map�� ���̸� 
			else if (check[curi + dist[nextori][0]][curj + dist[nextori][1]]==true || map[curi + dist[nextori][0]][curj + dist[nextori][1]]==1) {
				curori = nextori;
				continue;
			}
			
		}
	}
	
}
int main() {
	In();

	bfs();


	cout << cnt;
}