#include <stdio.h>
#include <algorithm>
#include <cmath>
#define MAX_V 987654321

using namespace std;

int N;
float dp[16][65536], map[16][16]={0,};

float go_trip(int now, int visited){
    float& temp=dp[now][visited];
    if(temp != 0) return temp;
    temp = MAX_V;
    for(int i=1; i<N; i++)
        if((visited>>i)%2)
            temp = min(temp, map[now][i] + go_trip(i, visited-(1<<i) ) );
    return temp;
}
int main(){
    scanf("%d", &N);
    int node[16][2];

    for(int i=0; i<N; i++)
        scanf("%d%d", node[i], node[i]+1);
    
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            map[i][j] = sqrt(pow(node[i][0]-node[j][0],2) + pow(node[i][1]-node[j][1],2));
            map[j][i] = map[i][j];
        }
        dp[i][0]=map[i][0];}
    printf("%f", go_trip(0, (1<<N)-2));
    return 0;
}
