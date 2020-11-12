#include <stdio.h>
#include <string.h>

#define max3(a,b,c) (a>b?a>c?a:c:b>c?b:c)

using namespace std;

int dp[1000][1000];
char a[1001], b[1001];

int DFS(int i, int j){
    if(a[i]=='\0' or b[j]=='\0') return 0;
    int& def=dp[i][j];
    if(def!=-1) return def;
    return def=max3(a[i]==b[j]?DFS(i+1,j+1)+1:0,DFS(i,j+1),DFS(i+1,j));
}
int main(){
    scanf("%s%s",a,b);
    memset(dp,-1,sizeof(dp));
    printf("%d",DFS(0,0));
    return 0;
}

//-----------------------------------------------

#include <stdio.h>

#define max3(a,b,c) (a>b?a>c?a:c:b>c?b:c)

using namespace std;

int dp[1001][1001]={0,};
char a[1001],b[1001];

int main(){
    scanf("%s%s",a,b);
    int i,j;

    for(i=0;a[i]!='\0';i++)
        for(j=0;b[j]!='\0';j++)
            dp[i+1][j+1]=max3((a[i]==b[j])+dp[i][j],dp[i+1][j],dp[i][j+1]);
    
    printf("%d",dp[i][j]);
    return 0;
}

