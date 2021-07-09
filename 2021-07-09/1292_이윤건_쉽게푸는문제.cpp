#include "bits/stdc++.h"

using namespace std;

int seg[1<<11]={0},k=1,i=0,s,e;

int get_seg(int a,int b){
    int answer=0;
    a+=(1<<10); b+=(1<<10);
    for(;a<=b;a/=2,b/=2){
        if(a&1) answer+=seg[a++];
        if(~b&1) answer+=seg[b--];
    }
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    
    while(1){
        for(int j=0;j<k;j++){
            seg[(1<<10) + i] = k;
            if(++i==1000) break;
        }
        if(i==1000) break;
        k++;
    }
    for(int i=(1<<10)-1;i>0;i--){
        seg[i]=seg[i*2]+seg[i*2+1];
    }
    cin>>s>>e;
    cout<<get_seg(s-1,e-1);
    return 0;
}


