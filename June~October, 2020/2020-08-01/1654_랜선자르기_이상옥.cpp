#include <stdio.h>

using namespace std;

int N, K, line[10000];

bool check(int m){
    int num=0;
    for(int i=0; i<K; i++)
        num+=line[i]/m;
    return num<N;
}
int main(){
    scanf("%d %d", &K, &N);
    unsigned int l=1,m,h=1<<31;
    
    for(int i=0; i<K; i++)
        scanf("%d",line+i);

    while(l+1!=h){
        m=(h+l)/2;
        if(check(m))
            h=m;
        else
            l=m;
    }
    printf("%d\n", l);
    
    return 0;
}
