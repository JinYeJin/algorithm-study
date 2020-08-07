#include <stdio.h>
#include <vector>
#include <algorithm>

#define MAX_V 987654321

using namespace std;

vector<vector<int>> del_line;
vector<vector<pair<int,int>>> n2n;
vector<vector<int>> parent;

int N, M, S, E, line[500][3], a, b, c;

void del_route(int n){
    if(n==S) return;
	for(auto p_n : parent[n]){
    	for(auto i=n2n[p_n].begin(); i<n2n[p_n].end(); i++){
	    	if(i->second == n){
	    		n2n[p_n].erase(i);
	    		del_route(p_n);
	    		break;
	    	}
    	}
    }
}
int find_route(){
    vector<pair<int,int>> heap(1,{0,S});
    vector<int> visited(N,MAX_V);

    while(!heap.empty()){
    	pop_heap(heap.begin(), heap.end());
    	pair<int, int> min_time = heap.back();
    	heap.pop_back();
    	if(min_time.second == E)
    		return -min_time.first;
    		
    	for(pair<int,int> i: n2n[min_time.second]){
			if(visited[i.second]>i.first-min_time.first){
				parent[i.second].clear();
    			visited[i.second]=i.first-min_time.first;
    			heap.push_back({min_time.first - i.first, i.second});
    			push_heap(heap.begin(), heap.end());
    		}
    		if(visited[i.second]>=i.first-min_time.first){
    			parent[i.second].push_back(min_time.second);
    		}
    	}
    }
    return MAX_V;
}
int main(){
    while(scanf("%d%d", &N, &M)){
        if(N==0) break;
        
        n2n.clear();
        parent.clear();
        del_line.clear();
        n2n.resize(N);
        parent.resize(N);
        del_line.resize(N);
        
        scanf("%d%d",&S, &E);
        for(int i=0; i<M; i++){
            scanf("%d%d%d", &a, &b, &c);
        	n2n[a].push_back({c,b});
        }
        int min_dis = find_route();
		    if(min_dis==MAX_V){
			    printf("-1\n");
			    continue;
		    }
    	  del_route(E);
        int almost_min_dis = find_route();
        printf("%d\n",almost_min_dis==MAX_V?-1:almost_min_dis);
        
    }
    return 0;
}
