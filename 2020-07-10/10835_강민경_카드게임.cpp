// 10835 카드게임 https://www.acmicpc.net/problem/10835
// 시간초과나서 참고했음
// 출처) https://fenslett.tistory.com/entry/%EB%B0%B1%EC%A4%80-10835-%EC%B9%B4%EB%93%9C-%EA%B2%8C%EC%9E%84?category=301370

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int A[2001], B[2001], N, dp[2001][2001];

int step(int a, int b) {
	if (a == N || b == N)
		return 0;
		
	// 이미 방문한 상태
	if (dp[a][b] != -1)
		return dp[a][b];

	// 왼쪽을 버리거나 둘 다 버리거나. 추가 점수는 없음
	dp[a][b] = max(step(a + 1, b), step(a + 1, b + 1));

	// 오른쪽을 버릴 수 있는 경우도 확인한다.
	if (A[a] > B[b]) {
		dp[a][b] = max(dp[a][b], step(a, b + 1) + B[b]);
	}

	return dp[a][b];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	memset(dp, -1, sizeof dp);
	cin >> N;

	for (int n = 0; n < N; n++) cin >> A[n];
	for (int n = 0; n < N; n++) cin >> B[n];
	
	int ret = step(0, 0);
	cout << ret;
}
