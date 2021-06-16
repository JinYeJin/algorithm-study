#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int F,S,G,U,D,DP[1000001],answer=0;
    bool visited[1000001]={0};
    queue<int> Q;
    cin>>F>>S>>G>>U>>D;
    memset(DP,-1,sizeof(DP));
    
    //S->G
    Q.push(S);
    while(Q.size()){
        int size=Q.size();
        while(size--){
            int q=Q.front();Q.pop();
            if(visited[q]) continue;
            visited[q]=1;
            if(q==G){
                cout<<answer;
                return 0;
            }
            if(q+U<=F && !visited[q+U]) Q.push(q+U);
            if(q-D>0 && !visited[q-D]) Q.push(q-D);
            
        }
        answer++;
    }
    cout<<"use the stairs";
    return 0;
}


