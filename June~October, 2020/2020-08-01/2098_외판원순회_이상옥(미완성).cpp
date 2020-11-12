#include <stdio.h>
#include <algorithm>

#define MAX_V 20000000
using namespace std;

int W[16][16], N,city;

int go_trip(int remain, int now){
    if(remain==0){
        if(W[now][city]==0) return MAX_V;
        return W[now][city];
    }
    int answer=MAX_V;
    for(int i=0;i<N;i++)
        if(((remain>>i)%2==1)){
            if(W[now][i]==0) continue;
            answer=min(answer,W[now][i] + go_trip(remain-(1<<i),i));
        }
    return answer;
}
int main(){
    int answer=MAX_V;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            scanf("%d",W[i]+j);
    int remain=(1<<N)-1;
    for(city=0;city<N;city++)
        answer = min(answer, go_trip(remain-(1<<city), city)); //도시를 순회, 출발도시.
    printf("%d\n",answer);
    return 0;
}

//-------------------------------------
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
