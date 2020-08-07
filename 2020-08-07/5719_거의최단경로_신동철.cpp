#include <iostream>
#include <cstring>
#include <limits.h>
#include <vector>
using namespace std;
int N, M, S, D, U, V, P ;//���,�����Ǽ�, ����,������
int graph[500][500],answer[500],temp[501];//�ʱ갪 0,answer�� INT_MAX, temp�� -1 �ʱⰪ
bool check[500];//�ʱ갪 false ��Ž�������뵵
int new_and_min() {
	int min = INT_MAX , node=-1;
	for (int k = 0; k <= N - 1; k++) {
		if (check[k] == false && answer[k] < min) {
			node = k;
			min = answer[k];
		}
	}
	return node;
}
void changed_dijkstra() {
	for (int k = 0; k <= N - 1; k++)//answer �Ÿ� �ʱ�ȭ
		answer[k] = INT_MAX;
	answer[S] = 0;
	int node;
	while ( (node=new_and_min())!=-1) {//ó��Ž���ϴ°��߿� ������������ �ִ°�
		check[node] = true;
		for (int i = 0; i <= N - 1; i++) {
			if (graph[node][i] != 0 && check[i] == false && answer[i] > (graph[node][i] + answer[node])) {//���̷�Ʈ�� ���� �־���ϰ� ó��Ž���ϴ°� �̾�� �ϰ� ,  ���۴ٸ� ����
				answer[i] = (graph[node][i] + answer[node]);
				temp[i] = node;//�ش��忡 ���Ž�Ų ������������� ����.
			}
		}
	}

}
int reverse() {
	if (temp[D] == -1)//�ִܰŸ��� �������� �������
		return 1;
	else {
		int k = temp[D];
		int k_next = D;
		while (k!=-1) {
			graph[k][k_next] = 0;//��������
			k_next = k;
			k = temp[k];
		}
		return 0;
	}
}
int main()
{
	while (1) {
		memset(graph, 0, sizeof(graph));//�ʱ�ȭ
		memset(check, 0, sizeof(check));//�ʱ�ȭ
		memset(temp, -1, sizeof(temp));//�ʱ�ȭ

		cin >> N >> M;
		if (N == 0 && M ==0) break;
		cin >> S >> D;
		for (int count = 1; count <= M; count++) {
			cin >> U >> V >> P;
			graph[U][V] = P;
		}
		changed_dijkstra();
		int k=reverse();//������ �� �ش� ��������
		if (k == 1) {//�ִܰŸ����� �������
			cout << -1 <<'\n';
			continue;
		}
		memset(check, 0, sizeof(check));//�ʱ�ȭ
		changed_dijkstra();//����� �׷����� ���ͽ�Ʈ�� ����
		if (answer[D] == INT_MAX)//���
			cout << -1 << '\n';
		else
			cout << answer[D] << '\n';
	}
}