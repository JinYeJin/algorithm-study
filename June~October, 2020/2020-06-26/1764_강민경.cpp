// https://www.acmicpc.net/problem/1764
// 듣보잡 1764

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	vector<string> a;
	vector<string> ans;

	int n, m;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		a.push_back(temp);
	}

	sort(a.begin(), a.end());

	for (int i = 0; i < m; i++) {
		string temp;
		cin >> temp;

		if (binary_search(a.begin(), a.end(), temp)) {
			ans.push_back(temp);
		}
	}

    sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}

	return 0;
}
