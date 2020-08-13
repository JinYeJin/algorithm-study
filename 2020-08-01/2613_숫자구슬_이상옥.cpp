#include <stdio.h>

using namespace std;
int N, M, ball[300];

bool check(int m){
    int M_cnt=1,sum=0;
    for(int i=0; i<N; i++){
        if(ball[i]+sum>m){
            M_cnt++;
            sum=0;
        }
        if(ball[i]>m) return false;
        sum+=ball[i];
    }
    if(M<M_cnt) return false;
    return true;
}
int main(){
    int l=0, m, h=3e4;
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++)
        scanf("%d",ball+i);
    
    while(l+1!=h){
        m=(l+h)/2;
        if(check(m))
            h=m;
        else
            l=m;
    }
    printf("%d\n",h);
    int cnt=0,sum=0;
    for(int i=0; i<N; i++){
        if(ball[i]+sum>h){
            printf("%d ",cnt);
            M--;
            cnt=0;
            sum=0;
        }
        if(N-i<M){
            for(int i=0; i<M; i++)
                printf("1 ");
            printf("\n");
            return 0;
        }
        sum+=ball[i];
        cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
