#include <stdio.h>

int main(){
    int T,x,y,i;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&x,&y);
        y-=x;
        long long sum=0;
        for(i=0;;i++){
            sum+=(i/2)+1;
            if(sum>=y) break;
        }
        printf("%d\n",i+1);
    }
    return 0;
}

