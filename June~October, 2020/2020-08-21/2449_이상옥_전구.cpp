#include <stdio.h>
#include <algorithm>
#include <vector>

#define INF 987654321
using namespace std;

int N, K, input,pre_input=0;
vector<vector<int>> dp;
vector<int> arr;

int DFS(int s, int e){
    if(s==e) return 1;

    int& def=dp[s][e];
    if(def!=INF) return def;
    int next_s, next_e, cnt=0;
    bool flag=true;
    for(int i=s; i<=e; i++){
        next_s = i;
        for(int j=e; j>=s; j--)
            if(arr[j] == arr[i]){
                next_e = j;
                if(i == j){
                    cnt++;
                    break;
                }
                flag=false;
                if(next_s==s and next_e==e)
                    def=min(def, DFS(next_s+1,next_e-1))+1;
                else if(next_s==s)
                    def=min(def, DFS(next_s,next_e)+DFS(next_e,e)-1);
                else if(next_e==e)
                    def=min(def, DFS(s, next_s) + DFS(next_s,next_e)-1);
                else
                    def=min(def, DFS(s,next_s-1)+DFS(next_s,next_e)+DFS(next_e+1,e));
            }
    }
    if(flag) def=cnt;
    return def;
}
int main(){
    scanf("%d%d",&N, &K);
    for(int i=0; i<N; i++){
        scanf("%d", &input);
        if(input!=pre_input) arr.push_back(input);
        pre_input=input;
    }
    dp.resize(arr.size(), vector<int>(arr.size(),INF));
    printf("%d\n", DFS(0,(int) arr.size()-1) - 1);
    return 0;
}

