//��Ǯ� �������ּҿ��� ��Ʈ�� https://velog.io/@skyepodium/%EB%B0%B1%EC%A4%80-2617-%EA%B5%AC%EC%8A%AC-%EC%B0%BE%EA%B8%B0
/*
����ã��

//�ٽɰ���.  � ������ �������� ��, �� �������� ��������� ���� or �� �������� ���ſ� ���� ������   (N+1)/2 ���� ũ�� ,  �� ������ ���� �߰� ���԰� �ɼ� ����.

���԰� �߰��� ������ �� �� ���� ������ ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/
#include <iostream>
#include <vector>
using namespace std;
vector<int> vec[101];//�ε����� �������, �ε����� �ش��ϴ� ���� ���ſ��
vector<int> rvec[101];//�ε����� ���ſ��, �ε����� �ش��ϴ� ���� �������
bool check1[101];
bool check2[101];
int N, M;
int cnt, cnt2;
int answer=0;
int base;
void In() {
	cin >> N >> M;
	int a, b;
	for (int tp = 1; tp <= M; tp++) {
		cin >> a >> b;
		vec[b].push_back(a);
		rvec[a].push_back(b);
	}
}
void dfs(int node) {//node���� ���ſ� ���� ������ cnt�� ����
	//����
	for (int tp = 0; tp < vec[node].size(); tp++) {
		int next = vec[node][tp];
		if (check1[next] == true)
			continue;
		check1[next] = true;//�湮������ ǥ��
		cnt++;
		dfs(next);
	}
}
void rdfs(int node) {// node���� ������ ���� ������ cnt2�� ����
	//����
	for (int tp = 0; tp < rvec[node].size(); tp++) {
		int next = rvec[node][tp];
		if (check2[next] == true)
			continue;
		check2[next] = true;//�湮������ ǥ��
		cnt2++;
		rdfs(next);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	In();
	base = (N + 1) / 2; //�߰� ��ȣ
	for (int tp = 1; tp <= N; tp++) {
		//�ʱ�ȭ
		cnt = 0;
		cnt2 = 0;
		for (int tp2 = 1; tp2 <= N; tp2++) {
			check1[tp2] = false;
			check2[tp2] = false;
		}


		dfs(tp);
		if (cnt >= base) {
			answer++;
			continue;
		}
		rdfs(tp);
		if (cnt2 >= base) 
			answer++;		
	}

	cout << answer;
}