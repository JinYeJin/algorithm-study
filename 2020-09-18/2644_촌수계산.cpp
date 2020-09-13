#include <stdio.h>
#include <vector>

#define INF 987654321
using namespace std;

int N,M,a,b,s,e;

int main(){
    scanf("%d\n%d%d\n%d",&N,&s,&e,&M);
    vector<pair<int,int>> line(M);
    for(int i=0;i<M;i++){
        scanf("%d%d",&a,&b);
        line[i]={a,b};
    }
    vector<int> cost(N+1,INF);
    cost[s]=0;
    for(int i=0;i<N;i++)
        for(auto l:line){
            cost[l.first]=min(cost[l.first],cost[l.second]+1);
            cost[l.second]=min(cost[l.second],cost[l.first]+1);
        }
    printf("%d",cost[e]==INF?-1:cost[e]);
    
    return 0;
}
