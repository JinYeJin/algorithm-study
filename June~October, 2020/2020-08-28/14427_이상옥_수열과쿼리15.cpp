#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, arr[100000],q;
vector<pair<int, int>> heap;

int get_min(){
    int min_num = -heap.front().first, idx = -heap.front().second;
    if(min_num != arr[idx]){
        pop_heap(heap.begin(), heap.end());
        heap.pop_back();
        return get_min();
    }
    return idx;
}
void query1(){
    int i,v;
    scanf("%d%d",&i,&v);
    i--;
    arr[i]=v;
    heap.push_back({-v, -i});
    push_heap(heap.begin(), heap.end());
}
void query2(){
    printf("%d\n",get_min()+1);
}
int main(){
    scanf("%d",&N);

    for(int i=0; i<N; i++){
        scanf("%d",arr+i);
        heap.push_back({-arr[i], -i}); //value최소값 정렬, index.
    }
    make_heap(heap.begin(), heap.end());
    scanf("%d",&M);
    while(M--){
        scanf("%d", &q);
        if(q==1) query1();
        else query2();
    }
    return 0;
}

