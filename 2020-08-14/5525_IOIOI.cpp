#include <stdio.h>

using namespace std;

int N, S,answer=0, cnt=0;
char s;

int main(){
    scanf("%d",&N);
    scanf("%d",&S);
    while(S--!=0){
        scanf("%c",&s);
        cnt++;
        if(cnt%2){ //I인경우
            if(s=='O')
                cnt=0;
            else if(cnt>=2*N+1)
                answer++;
        }
        else //O인 경우
            if(s=='I')
                cnt=1;
        
    }
    printf("%d",answer);
    return 0;
}
