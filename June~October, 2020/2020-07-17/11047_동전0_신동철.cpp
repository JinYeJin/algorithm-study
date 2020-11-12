//그리디로 풀기
#include <iostream>
using namespace std;
int N, K,realN;
int number[10];
int main() {
	cin >> N >> K;
	realN = N;
	for (int n = 0; n < N; n++) {
		cin >> number[n];
		if (number[n] > K) realN--;
	}
	int spare = K,answer=0;
	for (int idx = realN - 1; idx >= 0; idx--) {
		answer += spare / number[idx];
		spare = spare % number[idx];
		if (spare == 0) break;
	}
	cout << answer;
}