/*
�������� ����

�������� ������ ����ϴ� ����
*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int N, M;
vector<int> vec[1001];//�ǻ�� �ε����� 1~N
bool check[1001];//�ǻ�� �ε����� 1~N
bool check_buf[1001];//�ǻ�� �ε����� 1~N
int cnt = 0;
void In() {
	cin >> N >> M;
	int a,b;
	for (int tp = 1; tp <= M; tp++) {
		cin >> a >> b;
		vec[a].push_back(b);
	}
}
void dfs(int node) {
	//����
	for (int tp = 0; tp < vec[node].size(); tp++) {
		int next = vec[node][tp];
		if (check_buf[next] == true)//����Ŭ����
			continue;
		check_buf[next] = true;
		dfs(next);
	}
}
int main() {
	ios_base::sync_with_stdio(false);//284ms->88ms
	In();

	//���ܰ��
	if (M == 0) { 
		cout << N;
		return 0;
	}

	for (int tp = 1; tp <= N; tp++) {
		vector<int> buf;

		if (check[tp] == false) {
			check_buf[tp] = true;//�湮�������� ǥ��
			dfs(tp);  //check_buf����  tp�� �����ִ� �����Ҹ� ���� true�� �ٲ���
			
			bool flag = false;
			for (int tp2 = 1; tp2 <= N; tp2++) {
				if (check_buf[tp2] == true && check[tp2] == true) 
					flag = true;
				else if(check_buf[tp2] == true)
					buf.push_back(tp2);
			}
			
			if (flag == false)  //��ġ�°� ������쿡
				cnt++;

		
			vector<int>::iterator iter;
			for (iter = buf.begin(); iter != buf.end(); iter++) //check ���� renewal��
				check[(*iter)] = true;
			

			//�ʱ�ȭ
			memset(check_buf, 0, sizeof(check_buf));
		}
		
	}

	cout << cnt;

	return 0;
}