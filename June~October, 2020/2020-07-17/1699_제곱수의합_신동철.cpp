#include <iostream>
#include <limits.h>
#include <cmath>
using namespace std;
int dp[100001];
int num;//(1 ¡Â N ¡Â 100,000)
int main() {
	ios_base::sync_with_stdio(false);
	cin >> num;
	dp[0] = 0;
	for (int numb = 1; numb <= num; numb++) {
		int lm = (int)sqrt(numb);
		int loc_mn = INT_MAX;
		for (int one = 1; one <= lm; one++) 
			loc_mn = (dp[numb - one * one] < loc_mn) ? dp[numb - one * one] : loc_mn;
		dp[numb] = loc_mn + 1;
	}
	cout << dp[num];
}