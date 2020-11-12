// 2156 포도주시식
// https://www.acmicpc.net/2156

#include <cstdio>
#include <vector>
using namespace std;

int max(int a, int b, int c) {
    return a > b ? (a > c) ? a : c : (b > c) ? b : c;
}

int main()
{
    int n, m;
    scanf("%d", &n);
    vector<int> wine(n+1, 0);
    vector<int> dp(n+1, 0);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &wine[i]);
    }

    /*
        dp(N) = 0         (n==0)
            wine(1)         (n==1)
            wine(1) + wine(2)     (n==2)
            max(dp(n-1), dp(n-2)+ wine(N)   ,  dp(n-3)+wine(N-1)+wine(N) (n==3)
    */
    
    dp[1] = wine[1];
    if (n > 1) {
        dp[2] = wine[1] + wine[2];
    }
    if (n > 2) {
        for (int i = 3; i <= n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + wine[i], dp[i - 3] + wine[i - 1] + wine[i]);
        }
    }
    
    printf("%d\n", dp[n]);

    return 0;
}
