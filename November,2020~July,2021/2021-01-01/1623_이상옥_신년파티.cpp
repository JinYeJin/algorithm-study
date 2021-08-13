#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector<int> subs[200001],answer;
int vibe[200001];
int DP[2][200001];
int N,boss;

int DFS(bool visit, int n){
    int& def=DP[visit][n];
    if(def==-1){
        if(visit){
            def=vibe[n];
            for(int sub:subs[n]){
                def+=DFS(false,sub);
            }
        }
        else{
            def=0;
            for(int sub:subs[n]){
                def+=max(DFS(true,sub),DFS(false,sub));
            }
        }
    }
    return def;
}
void make_answer(bool visit, int n){
    if(visit){
        answer.push_back(n);
        for(int sub:subs[n]){
            make_answer(false, sub);
        }
    }else{
        for(int sub:subs[n]){
            if(DP[0][sub]<DP[1][sub]){
                make_answer(true, sub);
            }else{
                make_answer(false, sub);
            }
        }
    }
}
void print_answer(){
    sort(answer.begin(),answer.end());
    for(int ans:answer){
        cout<<ans<<' ';
    }cout<<"-1\n";
    answer.clear();
}
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>vibe[i];
    }
    for(int i=2;i<=N;i++){
        cin>>boss;
        subs[boss].push_back(i);
    }
    subs[0].push_back(1);
    memset(DP,-1,sizeof(DP));
    DFS(0,0);
    cout<<DP[1][1]<<' '<<DP[0][1]<<'\n';
    make_answer(true,1);
    print_answer();
    make_answer(false,1);
    print_answer();
    return 0;
}
