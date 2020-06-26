// 10816. 숫자 카드 2
// 받는 자료가 엄청 많으니 unordered_map 사용
// https://www.acmicpc.net/problem/10816

#include<bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, M, x;
	unordered_map<int, int> um;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		um[x]++;
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> x;
		cout << um[x] << ' ';
	}

	return 0;
}
