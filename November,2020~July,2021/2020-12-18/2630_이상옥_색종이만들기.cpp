#include <stdio.h>

using namespace std;

int N, map[128][128], answer0=0, answer1=0;

void div(int x, int y, int size){
    int sum=0;
    for(int i=y;i<y+size;i++)
        for(int j=x;j<x+size;j++)
            sum+=map[i][j];
    if(sum==0) answer0++;
    else if(sum==size*size) answer1++;
    else{
        div(x,y,size/2);
        div(x+size/2,y,size/2);
        div(x,y+size/2,size/2);
        div(x+size/2,y+size/2,size/2);
    }
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            scanf("%d",map[i]+j);
    div(0,0,N);
    printf("%d\n%d",answer0,answer1);
    return 0;
}

