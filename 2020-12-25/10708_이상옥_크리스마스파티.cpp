#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int N,M,score[101]={0},target[100],n;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>target[i];
    }
    for(int i=0;i<M;i++){
        int match=0;
        for(int j=1;j<=N;j++){
            cin>>n;
            if(n==target[i]){
                match++;
                score[j]++;
            }
        }
        score[target[i]]+=N-match;
    }
    for(int i=1;i<=N;i++) cout<<score[i]<<'\n';
    return 0;
}
