#include <stdio.h>
#include <algorithm>
#include <vector>

#define size (2<<19)
using namespace std;

pair<int,int> nanjang[300000];
int C,N,M,A,B,c,seg[size*2]={0,},r=0;

int cmp_seg(int A, int area, int c1, int c2){
    if(area/2<(int)((upper_bound(nanjang,nanjang+N,make_pair(c1,A+area))-lower_bound(nanjang,nanjang+N,make_pair(c1,A+1)))))
        return c1;
    if(area/2<(int)((upper_bound(nanjang,nanjang+N,make_pair(c2,A+area))-lower_bound(nanjang,nanjang+N,make_pair(c2,A+1)))))
        return c2;
    return 0;
}
int get_seg(int a, int b){
    int A=a,area=b-a+1;
    a+=size;
    b+=size;
    for(;a<=b;a/=2,b/=2){
        if(a&1){
            int temp=cmp_seg(A,area,seg[a++],0);
            if(temp) return temp;
        }
        if(~b&1){
            int temp=cmp_seg(A,area,seg[b--],0);
            if(temp) return temp;
        }
    }
    return 0;
}

int main(){
    scanf("%d%d",&N,&C);
    for(int i=0;i<N;i++){
        scanf("%d",seg+i+size);
        nanjang[i]={seg[i+size],i+1};
    }
    sort(nanjang,nanjang+N);
    for(int i=size-1;i>0;i--){
        int A=i,area=1;
        for(;A<size;A*=2) area*=2;
        A-=size;
        seg[i]=cmp_seg(A,area,seg[i*2],seg[i*2+1]);
    }
    for(scanf("%d",&M);M--;){
        scanf("%d%d",&A,&B);
        c = get_seg(A-1,B-1);
        if(c) printf("yes %d\n",c);
        else puts("no");
    }
    return 0;
}
