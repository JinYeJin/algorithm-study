//시간초과나서 정답확인...
#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    vector<long long> M(8000001,0);
    int N,S,num;
    
    
    cin>>N>>S;
    for(int i=0;i<N;i++){
        cin>>num;
        vector<pair<int,long long>> V;
        for(int i=0;i<8000001;i++){
            if(M[i]>0) V.push_back({i,M[i]});
        }
        for(auto v:V) M[v.first+num]+=v.second;
        M[num+4000000]++;
    }
    cout<<M[S+4000000];
    
    return 0;
}



#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    vector<long long> M(8000001,0);
    int N,S,num;
    
    
    cin>>N>>S;
    for(int i=0;i<N;i++){
        cin>>num;

        if(num<0){
            for(int i=-num;i<8000001;i++){
                M[i+num]+=M[i];
            }
            M[num+4000000]++;
            continue;
        }

        for(int i=8000000-num;i>=0;i--){
            M[i+num]+=M[i];
        }
        M[num+4000000]++;
    }
    cout<<M[S+4000000];
    
    return 0;
}
