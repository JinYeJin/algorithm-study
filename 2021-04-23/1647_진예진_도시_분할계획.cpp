/*
1647 도시 분할 계획
*/
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

int visited[100001];
// int graph[100001][100001];
vector<pair<int, int>> graph[100001];

int main(void) {
    FILE *stream = freopen("S2\\39\\input\\1647.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	int answer = 0;
	int max_weight = 0;
    int N, M;

    cin >> N >> M; // 집의 개수, 길의 개수

	// vector<vector<int>> graph(N+1, vector<int>(N+1));
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(c, b));
		graph[a].push_back({c, b});
		// graph[a][b] = c;
		// graph[b][a] = c;
	}

	pq.push(make_pair(0, 1));

	while(!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		
		if(visited[cur.second]) // 방문한 노드면 패스
			continue;
		visited[cur.second] = true; 
		
		answer += cur.first;
		max_weight = max_weight < cur.first ? cur.first : max_weight;
		
		for (int i = 0; i < graph[cur.second].size(); i++) { 
			if (!visited[graph[cur.second][i].second]) {
				pq.push(graph[cur.second][i]);
			}
		}
	}


	// vector<int> visited;
	// vector<int> unvisited;

	// visited.push_back(1);

	// for (int i = 2; i <= N; i++)
	// 	unvisited.push_back(i);

	// for (int i = 1; i < N; i++){
	// 	int min = 987654321;
	// 	int min_index = 0;

	// 	for (int j = 0; j < i; j++){
	// 		for (int k = 0; k < N - i; k++){
	// 			if (graph[visited[j]][unvisited[k]] > 0
    //                 && min > graph[visited[j]][unvisited[k]]){
	// 				min = graph[visited[j]][unvisited[k]];
	// 				min_index = k;
	// 			}
	// 		}
	// 	}

	// 	visited.push_back(unvisited[min_index]);
	// 	unvisited.erase(unvisited.begin() + min_index);
	// 	max_weight = max_weight < min ? min : max_weight;
	// 	answer += min;
	// }
    
    // for(int i = 0; i < visited.size(); i++){
    //     cout << visited[i] << " ";
    // }

	cout << answer - max_weight;

	return 0;
}
