#include <iostream>
#include <cstring>
#include <vector>

#define def DP[crew][visit]

using namespace std;

int DP[300001][2];
vector<int> n2n[300001],g_sales;
int DFS(int crew,bool visit){
    if(def==-1){
        if(visit){//참석을 함.
            def=g_sales[crew];
            for(int sub: n2n[crew]){
                def+=min(DFS(sub,0),DFS(sub,1));
            }
        }else{//참석을 안함.
            if(n2n[crew].empty()) return 0;
            def=0;
            int min_dp=10001;
            bool flag=1;
            for(int sub: n2n[crew]){
                int not_visit_dp = DFS(sub,0);
                int visit_dp = DFS(sub,1);
                if(not_visit_dp<visit_dp){
                    def+=not_visit_dp;
                    min_dp=min(min_dp,visit_dp-not_visit_dp);
                }
                else{
                    def+=visit_dp;
                    flag=0;
                }
            }
            if(flag){
                def+=min_dp;
            }
        }
    }
    return def;
}
int solution(vector<int> sales, vector<vector<int>> links) {
    int answer = 0;
    memset(DP,-1,sizeof(DP));
    g_sales.push_back(0);
    g_sales.insert(g_sales.end(),sales.begin(),sales.end());
    for(auto link: links){
        n2n[link[0]].push_back(link[1]);
    }
    return min(DFS(1,1),DFS(1,0));
}
