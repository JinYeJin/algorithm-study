#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int pnt[2000];
int get_pnt(int a){
    return (pnt[a]==-1 ? a:pnt[a]=get_pnt(pnt[a]));
}
bool up_pnt(int a, int b){
    int pa=get_pnt(a), pb=get_pnt(b);
    if(pa==pb) return false;
    pnt[pb]=pa;
    return true;
}

int Euclidean(pair<int,int> A, pair<int,int> B){
    return (A.first-B.first)*(A.first-B.first) + (A.second-B.second)*(A.second-B.second);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int N,C;
    pair<int,int> irrigation[2000];
    cin>>N>>C;
    for(int i=0;i<N;i++){
        cin>>irrigation[i].first>>irrigation[i].second;
    }
    
    priority_queue<pair<int,pair<int,int>>> H;
    memset(pnt,-1,sizeof(pnt));

    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            int c=Euclidean(irrigation[i],irrigation[j]);
            if(c<C) continue;
            H.push({-c,{i,j}});
        }
    }
    int answer=0;
    while(H.size()){
        auto h=H.top();H.pop();
        int c=h.first, a=h.second.first, b=h.second.second;
        if(up_pnt(a,b)){
            answer-=c;
        }
    }
    for(int i=1;i<N;i++){
        if(get_pnt(i)!=get_pnt(0)){
            cout<<-1;
            return 0;
        }
    }
    cout<<answer;
    return 0;
}
