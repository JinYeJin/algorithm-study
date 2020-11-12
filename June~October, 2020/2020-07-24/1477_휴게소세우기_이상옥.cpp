#include <stdio.h>
#include <algorithm>

using namespace std;

int N,M,L,station[100];
bool check(int m){
    int p=0, s_cnt=0, M_cnt=0; //p현재 위치.,
    while(p<L){
        if(M<M_cnt) return false;
        if(s_cnt==N or (p+m)<station[s_cnt]){
            M_cnt++;
            p+=m; //p+m 지점에다가 휴게소를 설치.
        }
        else
            p=station[s_cnt++];
    }
    return true;
}

int main(){
    scanf("%d %d %d",&N, &M, &L);

    for(int i=0; i<N; i++)
        scanf("%d",station+i);
    sort(station,station+N);
    
    int l=0, h=L, m;

    while(l+1!=h){
        m=(l+h)/2;
        if(check(m))
            h=m;
        else
            l=m;
    }
    printf("%d\n",h);
    return 0;
}
