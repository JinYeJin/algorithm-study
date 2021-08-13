#include <iostream>
#include <algorithm>

using namespace std;
int N,C,arr[200000];

int check(long dis){
    int now1=arr[0],cnt1=1;
    for(int j=1;j<N;j++){
        if(now1+dis<=arr[j]){
            now1=arr[j];
            cnt1++;
        }
    }
    return cnt1;
}
int main(){
    scanf("%d%d",&N,&C);
    for(int i=0;i<N;i++) scanf("%d",arr+i);
    sort(arr,arr+N);
    
    long l=0, h=1000000001, m;
    while(l+1<h){
        m=(l+h)/2;
        if(check(m)<C) h=m;
        else l=m;
    }
    printf("%ld",l);
    return 0;
}
