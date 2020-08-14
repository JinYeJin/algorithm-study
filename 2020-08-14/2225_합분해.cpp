#include <stdio.h>

using namespace std;

int main(){
    int N, K, dp[201][201] = {0,};
    scanf("%d%d",&N,&K);
    for(int i=0; i<=N; i++)
        dp[0][i] = 1;
    for(int i=1; i<K; i++)
        for(int j=0; j<=N; j++)
            for(int k=0; k<=N; k++)
                if(j+k<=N)
                    dp[i][j+k]=(dp[i][j+k]+dp[i-1][j])%1000000000;
    printf("%d",dp[K-1][N]);
    return 0;
}
