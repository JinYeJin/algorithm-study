20 4
1771
1		2		3		4		5		6		7		8		9		10		11		12		13		14		15		16		17		18		19		20		21		
1		3		6		10		15		21		28		36		45		55		66		78		91		105		120		136		153		171		190		210		231		
1		4		10		20		35		56		84		120		165		220		286		364		455		560		680		816		969		1140		1330		1540		1771		
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
