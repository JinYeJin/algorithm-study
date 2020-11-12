// https://www.acmicpc.net/problem/2617
// 2617 구슬찾기


#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
const int MAX = 101;

int n, m;
vector<int> big[MAX];
vector<int> small[MAX];

bool visit[2][MAX]; // 0 : big , 1: small
bool check[MAX]; // 정답체크, true이면 중간값이 되지 않는 구슬

int dfs(int idx, vector<int> arr[MAX], int row) {
	int lank = 1;

	for (int i = 0; i < arr[idx].size(); i++) {
		if (!visit[row][arr[idx][i]]) {
			visit[row][arr[idx][i]] = true;

			lank += dfs(arr[idx][i], arr, row);
		}
	}

	return lank;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		big[a].push_back(b);
		small[b].push_back(a);
	}
	
	for (int i = 1; i <= n; i++) {
		memset(visit, false, sizeof(visit));
		visit[0][i] = true;
		visit[1][i] = true;

		// i번째 구슬보다 큰 구슬의 갯수
		int bigLank = dfs(i, big, 0);

		// i번째 구슬보다 작은 구슬의 갯수
		int smallLank = dfs(i, small, 1);

		if (bigLank > (n + 1) / 2 || smallLank > (n + 1) / 2)
			check[i] = true;
	}

	int cnt = 0;

	for (int i = 0; i <= n; i++) {
		if (check[i])
			cnt++;
	}

	cout << cnt;
	return 0;
}
