#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    
    int N,M,X,out_X[1001],in_X[1001];
    pair<pair<int,int>,int> Ms[10000];
    for(int i=0;i<1001;i++){
        out_X[i]=1e9;
        in_X[i]=1e9;
    }
    cin>>N>>M>>X;

    for(int i=0;i<M;i++){
        cin>>Ms[i].first.first>>Ms[i].first.second>>Ms[i].second;
    }
    
    out_X[X]=0;
    in_X[X]=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int s=Ms[j].first.first,e=Ms[j].first.second,c=Ms[j].second;
            out_X[e] = min(out_X[e], out_X[s]+c);
            in_X[s] = min(in_X[s], in_X[e]+c);
        }
    }
    int answer=0;
    for(int i=1;i<=N;i++){
        answer=max(answer,out_X[i]+in_X[i]);
    }
    cout<<answer;
    return 0;
}
