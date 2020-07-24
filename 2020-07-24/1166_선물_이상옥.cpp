#include <stdio.h>

using namespace std;

int N, L, W, H;
long long box_num(int a, double b){
    return (long long)(((double) a)/b);
}
int min(int a, int b, int c){
    return a<b?(a<c?a:c):(b<c?b:c);
}
double binary(){
    double l=0, h,m;
    h=(double) min(L,W,H);
    for(int i=0; i<60; i++){
        m = (l+h)/2.0;
        if(N>box_num(L,m)*box_num(W,m)*box_num(H,m))
            h=m;
        else
            l=m;
    }
    return l;
}
int main(){
    scanf("%d %d %d %d",&N, &L, &W, &H);
    printf("%.9lf\n",binary());
    return 0;
}
