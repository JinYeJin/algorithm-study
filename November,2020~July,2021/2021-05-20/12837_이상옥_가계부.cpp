#include "bits/stdc++.h"

using namespace std;

#define tree_size (1<<20)

long seg[tree_size*2]={0};


long get_seg(int p,int q){
    long answer=0;
    p+=tree_size,q+=tree_size;
    for(;p<=q;p/=2,q/=2){
        if(p&1) answer+=seg[p++];
        if(~q&1) answer+=seg[q--];
    }
    return answer;
}
void up_seg(int p,int v){
    p+=tree_size;
    for(;p;p/=2){
        seg[p]+=v;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N,Q,k,p,q;
    cin>>N>>Q;
    while(Q--){
        cin>>k>>p>>q;
        if(k==1){
            up_seg(p,q);
        }else{
            cout<<get_seg(p,q)<<'\n';
        }
    }
    
    return 0;
}


