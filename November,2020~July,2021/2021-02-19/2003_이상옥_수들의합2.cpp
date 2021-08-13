#include <iostream>
#include <algorithm>

using namespace std;

int N,M,arr[10000],answer=0;

int main(){
    ios::sync_with_stdio();cin.tie();
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    int s=0,e=1,sum=arr[0];
    while(s<N){
        if(sum>=M){
            if(sum==M) answer++;
            sum-=arr[s++];
        }
        else if(e<N){
            sum+=arr[e++];
        }
        else{
            break;
        }
    }
    cout<<answer;
    return 0;
}
