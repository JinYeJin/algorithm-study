// https://www.acmicpc.net/problem/11724
// 11724 연결요소의개수

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1001;

int n, m;

vector<int> arr[MAX];
bool visit[MAX];

void dfs(int node) {
	visit[node] = true;

	for (int i = 0; i < arr[node].size(); i++) {
		int next = arr[node][i];
		if (visit[next] == false)
			dfs(next);
	}
}
int main() {

	int answer = 0;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;

		cin >> a >> b;

		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (visit[i] == false) {
			dfs(i);
			answer++;
		}
	
	}

	cout << answer;

	return 0;
}
