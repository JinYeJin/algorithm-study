#include <iostream>
#include <algorithm>

using namespace std;

int N,arr[1001]={0},ma[1001]={0},answer=0;
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    cin>>N;
    for(int i=1;i<=N;i++) cin>>arr[i];

    for(int i=1;i<=N;i++){
        for(int j=0;j<i;j++)
            if(arr[j]<arr[i]) ma[i]=max(ma[i], ma[j]+arr[i]);
        answer=max(answer, ma[i]);
    }
    cout<<answer;
    return 0;
}
