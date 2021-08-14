#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int T,N,answer;
    cin>>T;
    while(T--){
        answer=0;
        cin>>N;
        pair<int,int> members[100000];
        for(int i=0;i<N;i++){
            cin>>members[i].first>>members[i].second;
        }
        sort(members,members+N);
        int min_interview=100001;
        for(int i=0;i<N;i++){
            if(min_interview > members[i].second){ //모든순위가 낮은경우
                answer++;
                min_interview=members[i].second;
            }
        }
        
        cout<<answer<<'\n';
    }
    
    return 0;
}
