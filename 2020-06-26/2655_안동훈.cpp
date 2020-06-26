// 2655. 가장 높은 탑 쌓기
// https://www.acmicpc.net/problem/2655
// 경로 출력 못풀어서 참고: https://m.blog.naver.com/PostView.nhn?blogId=kimmy5000&logNo=220793168857&proxyReferer=https:%2F%2Fwww.google.com%2F
// 참고했는데도 못품

#include<bits/stdc++.h>

using namespace std;
int N;
int dp[101]; //DP[i] i번째 블록이 가장 아래 있을 때, 가장 높게 쌓았을 때의 높이
int answer;

class block {
public:
	int idx;
	int s;
	int h;
	int m;
};

bool cmp(block a, block b) {
	return a.s < b.s;
}

vector<block> blocks;
vector<int> p;

void print(int idx) {
	if (idx <= 0) {
		cout << answer << '\n';
		return;
	}

	answer++;
	print(p[idx]);
	cout << blocks[idx].idx << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	//블록 요소(S: 넓이, H: 높이, M: 무게) 벡터에 입력
	for (int i = 0; i < N; i++) {
		block b;
		cin >> b.s >> b.h >> b.m;
		b.idx = i + 1;

		blocks.push_back(b);
	}

	//넓이 기준 오름차순으로 정렬
	sort(blocks.begin(), blocks.end(), cmp);

	//dp 구하기
	//DP[0] = 5
	//DP[1] = 9 = max(4, 4+dp[0])
	//DP[2] = 7 = max(2, 2+dp[1], 2+dp[0])
	//DP[3] = 9  = max(2, 2+dp[2], 2+dp[1], 2+dp[0])
	//DP[4] = 10 = max(3, 3+dp[3], 3+dp[2], 3+dp[1], 3+dp[0])

	dp[0] = blocks[0].h;
	int max = 0;
	int li = 0;

	for (int i = 1; i < N; i++) {
		int max_h = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (blocks[j].m < blocks[i].m) {
				if (dp[j] >= max_h) {
					max_h = dp[j];
					p[i] = j;
				}
			}
		}
		dp[i] = max_h + blocks[i].h;

		if (dp[i] > max) {
			max = dp[i];
			li = i;
		}
	}

	print(li);

	system("pause");

	return 0;
}
