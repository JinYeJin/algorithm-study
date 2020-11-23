#include <iostream>
#include <algorithm>

using namespace std;

int N, a[1000],b[1000]={0,},c[1000]={0,},m=0;

int main(){
    cin>>N;
    for(int i=0;i<N;i++) cin>>a[i];
    for(int i=0;i<N;i++)
        for(int j=0;j<i;j++){
            if(a[i]>a[j]) b[i]=max(b[i],b[j]+1);
            if(a[i]<a[j]) c[i]=max(c[i],max(b[j]+1,c[j]+1));
        }
    for(int i=0;i<N;i++) m=max(m,max(b[i],c[i]));
    cout<<m+1;
    return 0;
}
