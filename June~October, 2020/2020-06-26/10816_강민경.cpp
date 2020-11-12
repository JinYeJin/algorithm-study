// https://www.acmicpc.net/problem/10816
// 숫자카드2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> arrN, arrM, answer;

int cmp(int a, int b) {
	if (a >= b) return a;
	else return b;
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		arrN.push_back(data);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int data;
		cin >> data;

		arrM.push_back(data);
	}


	sort(arrN.begin(), arrN.end());

	for (int i = 0; i < m; i++) {
		int cnt = upper_bound(arrN.begin(), arrN.end(), arrM[i]) - lower_bound(arrN.begin(), arrN.end(), arrM[i]);
		answer.push_back(cnt);
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}

	return 0;
}
