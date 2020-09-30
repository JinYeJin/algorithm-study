#include <iostream>
#include <algorithm>

#define INF 987654321
#define tree_size (1<<17)

using namespace std;

int seg[tree_size*2],arr[tree_size],N,answer=0;

int get_min_idx(int idx1, int idx2){
    if(arr[idx1]>arr[idx2]) return idx2;
    return idx1;
}
int get_seg(int a,int b){
    int answer=a;
    a+=tree_size;
    b+=tree_size;
    for(;a<=b;a/=2,b/=2){
        if(a&1) answer=get_min_idx(answer,seg[a++]);
        if(~b&1) answer=get_min_idx(answer,seg[b--]);
    }
    return answer;
}
void DFS(int S, int E){
    int min_idx=get_seg(S,E);
    answer=max(answer,arr[min_idx]*(E-S+1));
    if(S<min_idx) DFS(S,min_idx-1);
    if(min_idx<E) DFS(min_idx+1,E);
}

int main(){
    cin.tie(NULL);ios::sync_with_stdio(false);
    cin>>N;

    for(int i=0;i<N;i++) cin>>arr[i];
    for(int i=N;i<tree_size;i++) arr[i]=INF;
    
    for(int i=tree_size;i<tree_size*2;i++) seg[i]=i-tree_size;
    for(int i=tree_size-1;i>0;i--) seg[i]=get_min_idx(seg[i*2],seg[i*2+1]);

    DFS(0,N-1);

    cout<<answer;
    return 0;
}
