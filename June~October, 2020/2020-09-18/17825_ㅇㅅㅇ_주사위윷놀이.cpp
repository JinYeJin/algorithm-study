#include <stdio.h>
#include <algorithm>
using namespace std;
//D:주사위, C:말, CS:말상태(0:빨간줄따라,1:10에서 파란색,2:20에서 파란색,3:30에서 파란색방향, NS:다음상태
int M[]={0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,10,13,16,19,20,22,24,30,28,27,26,25,30,35,40,0};
int D[10], jump[]={20,24,27,31},C[5]={0,0,0,0,35},CS[4]={0,0,0,0},NS;
int move(int i, int d, int S){
    NS=S;
    if(S==0){
        if(i+d>19)return move(34, d+i-20,3);
        else if((i+d)%5==0){
            NS=(i+d)/5;
            return jump[NS-1];
        }
    }
    else if(S==1){
        if(i+d>23)return move(31, d+i-24,3);
    }
    else if(S==2){
        if(i+d>26)return move(31, d+i-27,3);
    }
    else if(i+d>35)return 35;
    return i+d;
}

int F(int i){
    if(i==10) return 0;
    int A=0,temp,tempS,next;
    for(int m=0;m<min(4,i+1);m++){
        temp=C[m];
        tempS=CS[m];
        next=move(C[m],D[i],CS[m]);
        CS[m]=NS;
        if(*find(C,C+4,next)==35){
            C[m]=next;
            A=max(A, M[C[m]]+F(i+1));
        }
        CS[m]=tempS;
        C[m]=temp;
    }
    return A;
}
int main(){
    for(int i=0;i<10;i++)scanf("%d",D+i);
    printf("%d", F(0));
    return 0;
}

