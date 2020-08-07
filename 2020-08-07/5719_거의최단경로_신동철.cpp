#include <iostream>
#include <cstring>
#include <limits.h>
#include <vector>
using namespace std;
int N, M, S, D, U, V, P ;//장소,도로의수, 시작,도착점
int graph[500][500],answer[500],temp[501];//초깃값 0,answer는 INT_MAX, temp는 -1 초기값
bool check[500];//초깃값 false 재탐색방지용도
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
	for (int k = 0; k <= N - 1; k++)//answer 거리 초기화
		answer[k] = INT_MAX;
	answer[S] = 0;
	int node;
	while ( (node=new_and_min())!=-1) {//처음탐색하는곳중에 가장작은값이 있는가
		check[node] = true;
		for (int i = 0; i <= N - 1; i++) {
			if (graph[node][i] != 0 && check[i] == false && answer[i] > (graph[node][i] + answer[node])) {//다이렉트로 값이 있어야하고 처음탐색하는곳 이어야 하고 ,  더작다면 갱신
				answer[i] = (graph[node][i] + answer[node]);
				temp[i] = node;//해당노드에 갱신시킨 이전노드정보를 저장.
			}
		}
	}

}
int reverse() {
	if (temp[D] == -1)//최단거리가 존재하지 않을경우
		return 1;
	else {
		int k = temp[D];
		int k_next = D;
		while (k!=-1) {
			graph[k][k_next] = 0;//간선제거
			k_next = k;
			k = temp[k];
		}
		return 0;
	}
}
int main()
{
	while (1) {
		memset(graph, 0, sizeof(graph));//초기화
		memset(check, 0, sizeof(check));//초기화
		memset(temp, -1, sizeof(temp));//초기화

		cin >> N >> M;
		if (N == 0 && M ==0) break;
		cin >> S >> D;
		for (int count = 1; count <= M; count++) {
			cin >> U >> V >> P;
			graph[U][V] = P;
		}
		changed_dijkstra();
		int k=reverse();//역추적 및 해당 간선제거
		if (k == 1) {//최단거리조차 없을경우
			cout << -1 <<'\n';
			continue;
		}
		memset(check, 0, sizeof(check));//초기화
		changed_dijkstra();//변경된 그래프로 다익스트라 수행
		if (answer[D] == INT_MAX)//출력
			cout << -1 << '\n';
		else
			cout << answer[D] << '\n';
	}
}