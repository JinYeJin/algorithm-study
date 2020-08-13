#include <stdio.h>
#include <algorithm>

using namespace std;

bool visited[50][50];

int N, M, map[50][50], dn[]={1,-1,0,0}, dm[]={0,0,1,-1}, dp[50][50]={0,};

int get_score(int n, int m){
    if(map[n][m]=='H'-'0') return 0;
    int& temp = dp[n][m];
    if(temp != 0) return temp;
    temp++;
    for(int i=0; i<4;i++){
        int nn=n+ dn[i]*map[n][m], nm=m+dm[i]*map[n][m];
        if(0<=nn && nn<N && 0<=nm && nm<M){
            if(visited[nn][nm]){
                printf("-1");
                exit(0);
            }
            visited[nn][nm]=true;
            temp=max(temp, get_score(nn, nm)+1);
            visited[nn][nm]=false;
        }
    }
    return temp;
}
int main(){
    scanf("%d%d\n",&N,&M);
    char temp;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%c",&temp);
            map[i][j]=temp-'0';
        }scanf("%c",&temp);
    }
    visited[0][0]=true;
    printf("%d",get_score(0,0));
    return 0;
}
