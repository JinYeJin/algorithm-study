/*
[백준 1197 최소스패닝트리] https://www.acmicpc.net/problem/1197
https://huiung.tistory.com/76
*/
#include <iostream>
#include <vector>
#include <queue>
#define P pair<int, int>

using namespace std;

int visited[10001];
vector<P> edge[10001];
/* 프링 알고리즘
   우선순위 큐를 이용하여 방문할 수 있는 정점중 가중치가 가장 낮은 정점으로 이동 
   프림은 ElogV 의 시간복잡도 
*/ 
int prim() {
	long long ans = 0;
	priority_queue<P, vector<P> , greater<P>>pq; // first는 가중치 second 는 정점 minheap 
	pq.push(P(0, 1)); //1번 정점부터 시작       // 가중치가 가장작은것이 top으로 가게된다! 
	
	while(!pq.empty()) {
		P cur = pq.top();
		pq.pop();
		
		if(visited[cur.second]) //방문 정점 표시 
			continue;
		visited[cur.second] = 1; 
		
		ans += cur.first;
		
		for (int i = 0; i < edge[cur.second].size(); i++) { //현재 정점에서 이동 할 수 있는 방문하지 않은 정점 푸쉬 
			if (!visited[edge[cur.second][i].second]) {
				pq.push(edge[cur.second][i]);
			}
		}
	}
 	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int V, E;
	cin >> V >> E;
	
	for(int i = 0; i < E; i++) {
		int A,B,C;
		cin >> A >> B >> C;
		edge[A].push_back(P(C, B));
		edge[B].push_back(P(C, A));
	}
	
	long long result = prim();
	cout<< result;
	return 0;
}
