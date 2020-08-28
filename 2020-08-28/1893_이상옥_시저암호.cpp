#include <stdio.h>
#include <map>
#include <vector>
#include <string.h>

using namespace std;

char A[63], W[50000], S[500000];
int N,W_l,S_l;
int KMP(int s, int tail){
    if(S_l-s < W_l) return 0;
    if(S[s+tail]!=W[tail]) return KMP(s+tail+1,0);
    int i=tail+1;
    for(; i<W_l; i++){
        if(S[s+i] != W[i]) break;
        if(W[i]==W[tail]) tail++;
        else tail=0;
    }
    return KMP(s+i-tail,tail)+(i==W_l);
}
void check(){
    scanf("%s%s%s",A,W,S);
    map<char, int> CI;
    int A_l=0;
    for(;A[A_l]!='\0';A_l++)
        CI[A[A_l]]=A_l;
    W_l=strlen(W);
    S_l=strlen(S);
    vector<int> shifts;
    for(int shift=0; shift<A_l; shift++){
        if(KMP(0,0)==1) shifts.push_back(shift);
        for(int i=0; i<W_l; i++)
            W[i]=A[(CI[W[i]]+1)%A_l];
    }
    if(shifts.empty())
        printf("no solution");
    else{
        printf(shifts.size()==1?"unique:":"ambiguous:");
        for(int r: shifts)
            printf(" %d",r);
    }
    printf("\n");
}
int main(){
    scanf("%d",&N);
    while(N--)
        check();
    return 0;
}
