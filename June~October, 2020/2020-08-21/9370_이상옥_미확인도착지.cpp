#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>

#define INF 543214321
using namespace std;
vector<vector<pair<float, int>>> p2p;
vector<pair<float, int>> heap;
vector<float> min_cost;

int n,m,t, s,g,h, a,b,d, destination;

void BFS(int p){
    heap.clear();
    min_cost.clear();
    min_cost.resize(n+1, INF);
    min_cost[p]=0;
    heap.push_back({0,p});
    float cost;
    while(!heap.empty()){
        cost=heap.front().first;
        p=heap.front().second;
        pop_heap(heap.begin(), heap.end());
        heap.pop_back();

        if(p == destination) return;

        for(auto next: p2p[p]){
            int next_p = next.second;
            float next_cost = next.first;

            if(min_cost[next_p] <= next_cost-cost) continue;

            min_cost[next_p]=next_cost-cost;
            heap.push_back({cost-next_cost, next_p});
            push_heap(heap.begin(), heap.end());
        }
    }
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d", &n, &m, &t);
        scanf("%d%d%d", &s, &g, &h);
        p2p.clear();
        p2p.resize(n+1);
        for(int i=0; i<m; i++){
            scanf("%d%d%d",&a, &b, &d);
            if((a==g and b==h) or (a==h and b==g)){
                p2p[a].push_back({d-0.1,b});
                p2p[b].push_back({d-0.1,a});
            }
            else{
                p2p[a].push_back({d,b});
                p2p[b].push_back({d,a});
            }
        }
        int des[100];
        for(int i=0; i<t; i++)
            scanf("%d",des+i);
        sort(des, des+t);

        for(int i=0; i<t; i++){
            destination=des[i];
            BFS(s);
            if(min_cost[destination] != (int)min_cost[destination])
                printf("%d ", des[i]);
        }
        printf("\n");
    }
    return 0;
}

