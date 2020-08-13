#include <stdio.h>
#include <vector>

#define MAX_VALUE 987654321

int min(int a, int b){
    return a<b?a:b;
}
using namespace std;
int main(){
    int N, M, A, B, C;
    scanf("%d %d",&N, &M);

    vector<vector<int>> n2n(N+1,vector<int>(N+1,MAX_VALUE));
    for(int i=1; i<=N; i++) n2n[i][i]=0;

    while(M--!=0){
        scanf("%d %d %d",&A,&B,&C);
        n2n[A][B] = min(n2n[A][B], C);
    }
    for(int i=1; i<=N; i++) //경유지
        for(int j=1; j<=N; j++) //출발지
            for(int k=1; k<=N; k++) //도착지
                if(n2n[j][i]!=MAX_VALUE and n2n[i][k]!=MAX_VALUE)
                    n2n[j][k] = min(n2n[j][k], n2n[j][i] + n2n[i][k]);
    
    for(int i=1; i<=N; i++)
        if(n2n[1][i]!=MAX_VALUE and n2n[i][i]<0)
        {
            printf("-1\n");
            return 0;
        }
    for(int i=2; i<=N; i++)
        printf("%d\n", n2n[1][i]==MAX_VALUE?-1:n2n[1][i]);

    return 0;
}

