// 1764. 듣보잡
// 500000개에 달하는 정보를 검색해야하므로 set을 사용하도록 하자.
// https://www.acmicpc.net/problem/1764

#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	set<string> s;
	priority_queue<string, vector<string>, greater<string>> answer;
	string t;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> t;
		s.insert(t);
	}

	for (int i = 0; i < M; i++) {
		cin >> t;
		if (s.count(t)) answer.push(t);
	}

	cout << answer.size() << '\n';

	while (!answer.empty()) {
		cout << answer.top() << '\n';
		answer.pop();
	}

	return 0;
}
