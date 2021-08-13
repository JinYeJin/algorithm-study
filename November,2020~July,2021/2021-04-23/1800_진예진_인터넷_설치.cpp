/*
1800 인터넷 설치
참고!!
https://justicehui.github.io/usaco/2019/07/12/BOJ1800/
결론 이분탐색 + 다익스트라
*/
#include <stdio.h>
#include <iostream> 
#include <queue>
#include <string.h>
#define INF 987654321

using namespace std;


int N, P, K;
vector<pair<int, int>> graph[1001];
int dist[1001];
int max_cost = 0;

int dijkstra(int threshold){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for(int i = 0; i <= N; i++){
        dist[i] = INF;
    }
	// memset(dist, 0x3f, sizeof dist);

    int start = 1;
    pq.push(make_pair(0, start));
    dist[start] = 0;
    max_cost = 0;

    while (pq.empty() == 0){
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < graph[cur].size(); i++){
            int weight = graph[cur][i].first;
            int next = graph[cur][i].second;

            int next_cost = cost + (weight > threshold)
            if (dist[next] > next_cost){
                dist[next] = next_cost; // threshold 보다 큰 간선에 불이익을 줌(1)
                max_cost = max_cost < weight ? weight : max_cost;
                pq.push(make_pair(dist[next], next));
            }
        }
    }

    // dist가 의미하는 것은 threshold 보다 큰 간선이 몇개나 있는가
    return dist[N] <= K;
}


int main(){
    FILE *stream = freopen("S2\\39\\input\\1800.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> N >> P >> K;

    int max_right = -1;

    for(int p = 0; p < P; p++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
        max_right = max_right < w ? w : max_right;
    }

    int ans = -1;
	int l = 0, r = 1e7;
    int global_max_cost = 0;

	while (l < r){
		int mid = l + r >> 1;
		if(dijkstra(mid)){
			ans = mid;
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
        global_max_cost = global_max_cost < max_cost ? max_cost : global_max_cost;
	}

    // for (int i = 1; i <= N; i++)
    // {
    //     if (dist[i] == INF) cout << "INF" << endl;
    //     else cout << dist[i] << endl;
    // }
    // cout << dist[N] - global_max_cost << " ";
    cout << ans;

    return 0;
}
