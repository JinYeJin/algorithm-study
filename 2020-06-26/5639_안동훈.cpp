// 5639. 이진 검색 트리
// https://www.acmicpc.net/problem/5639
// 그냥 이거 보고 함 https://penglog.tistory.com/96

#include<bits/stdc++.h>

using namespace std;

vector<int> node;

void calculate(int l, int r) {
	int ans = l;
	int sub = l++;

	while (1) {
		if (node[++sub] >= node[ans]) break;
	}

	if (l <= sub - 1) {
		calculate(l, sub - 1);
	}

	if (sub <= r) {
		calculate(sub, r);
	}

	cout << node[ans] << '\n';

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int x;

	while (cin >> x) {
		node.push_back(x);
	}

	node.push_back(10000000);

	calculate(0, node.size() - 2);

	return 0;
}
