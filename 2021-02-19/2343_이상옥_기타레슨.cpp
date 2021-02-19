#include <iostream>
#include <algorithm>

using namespace std;
int N,M,lesson[100000];
int bisearch(int s, int e){
    int m,k,blue,sum;
    while(s+1<e){
        m=s+e>>1;
        k=0;
        blue=0;
        while(blue++<M && k<N){
            sum=0;
            while(k<N){
                sum+=lesson[k];
                if(sum>m){
                    break;
                }
                k++;
            }
        }
        if(k<N){
            s=m;
        }else{
            e=m;
        }
    }
    return e;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>lesson[i];
    }
    cout<<bisearch(0,1000000001)<<'\n';
    return 0;
}
