#include <stdio.h>

int dp[4001][4001];
 
int main()
{
    int max = 0;
    char a[4001];
    char b[4001];
 
    scanf("%s", a);
    scanf("%s", b);
 
    for (int i = 0; a[i] != 0; i++)
        for (int j = 0; b[j] != 0; j++)
        {
            if (a[i] == b[j]) {
                if (i == 0 || j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i - 1][j - 1] + 1;
 
                if (max<dp[i][j])
                    max = dp[i][j];
            }
        }
    printf("%d\n", max);
    return 0;
}
