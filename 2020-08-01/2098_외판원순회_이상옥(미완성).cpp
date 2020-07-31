#include <stdio.h>
#include <algorithm>
#include <vector>

#define MAX_V 20000000
using namespace std;

int W[16][16], N,city, answer=MAX_V;

void go_trip(vector<int> remain, int now, int sum){
    if(sum>=answer) return;
    if(remain.empty()){
        if(W[now][city]==0) return;
        answer = min(answer,W[now][city]+sum);
    }
    for(int i : remain){
        if(W[now][i]==0) continue;
        vector<int> new_remain;
        for(int j:remain)
            if(i!=j) new_remain.push_back(j);
        go_trip(new_remain,i, sum+W[now][i]);
    }
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            scanf("%d",W[i]+j);
    vector<int> remain(N-1);
    for(int i=0; i<N-1; i++)
        remain[i]=i;
    city=N-1;
    go_trip(remain, N-1,0);
    printf("%d\n",answer);
    return 0;
}
