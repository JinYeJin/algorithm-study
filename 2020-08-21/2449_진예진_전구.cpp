/*
참고 https://huiung.tistory.com/134
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#define INF 987654321

using namespace std;

int N, K, M;
int dp[220][220];
int arr[220];

int sol(int start, int end) {
	if (start == end) {
		return 0;
	}

	int &ret = dp[start][end];
	if (ret != -1) return ret;
	ret = INF;
	
	for (int i = start; i < end; i++) {
		int left = sol(start, i);
		int right = sol(i + 1, end);
		int temp;

		if (arr[start] == arr[i + 1]) temp = 0;
		else temp = 1;

		ret = min(ret, left + right + temp);
	}
	return ret;
}

int main(){
    FILE *stream =freopen("S2\\12\\input\\2449.txt", "r", stdin);
    if(!stream) perror("freopen");

    scanf("%d %d", &N, &K);


	memset(dp, -1, sizeof(dp));

	int ans = INF;
	int idx = 0;
	for (int i = 0; i < N; i++) {
		int x;
        scanf("%d", &x);
		if (i == 0)arr[idx++] = x;
		else if(x != arr[idx-1]) arr[idx++] = x;
	}

    printf("%d", sol(0, idx -1));

    return 0;
}
