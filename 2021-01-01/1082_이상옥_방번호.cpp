#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int cost[10],N,money;
string DP[51];
string DFS(int change){
    if(DP[change]==""){
        for(int i=N-1;i>=0;i--){
            if(change-cost[i]>=0){
                string answer=(char)('0'+i)+DFS(change-cost[i]);
                if(DP[change].size()<answer.size()){
                    DP[change]=answer;
                }
            }
        }
    }
    return DP[change];
}
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    for(int i=0;i<51;i++){
        DP[i]="";
    }
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>cost[i];
    }
    cin>>money;
    string answer="";
    for(int i=N-1;i>0;i--){
        if(money-cost[i]>=0){
            string result=(char)('0'+i)+DFS(money-cost[i]);
            if(answer.size()<result.size()){
                answer=result;
            }
        }
    }
    cout<<(answer==""?"0":answer);
    return 0;
}
