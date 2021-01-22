#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pnt;
vector<vector<int>> lines;

int get_pnt(int a){
    return pnt[a]==-1?a:pnt[a]=get_pnt(pnt[a]);
}
bool up_pnt(int a, int b){
    int p_a=get_pnt(a), p_b=get_pnt(b);
    if(p_a!=p_b){
        pnt[p_b]=p_a;
        return 1;
    }
    return 0;
}

int main(){
    int V,E,A,B,C,sum=0;

    scanf("%d%d",&V,&E);
    pnt.resize(V+1,-1);
    lines.resize(E);
    for(int i=0; i<E; i++){
        scanf("%d%d%d",&A,&B,&C);
        lines[i]={C,A,B};
    }
    sort(lines.begin(), lines.end());

    for(auto line:lines)
        if(up_pnt(line[1],line[2]))
            sum+=line[0];

    printf("%d",sum);
    return 0;
}
///////////////////
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int,int>>> n2n;
int V, E, a, b, c, e;

int spening(){
    int cnt=0, sum=0;
    vector<bool> visited(V+1,false);
    vector<pair<int,int>> heap;
    heap.push_back({0,1});
    while(!heap.empty()){
        int cost=-heap.front().first, p= heap.front().second;
        pop_heap(heap.begin(), heap.end());
        heap.pop_back();
        if(visited[p]) continue;
        visited[p]=true;
        sum+=cost;
        if(++cnt == V) return sum;
        for(auto next : n2n[p]){
            heap.push_back({-next.first, next.second});
            push_heap(heap.begin(), heap.end());
        }
    }
    return sum;
}
int main(){
    scanf("%d%d",&V, &E);
    n2n.resize(V+1);
    while(E--){
        scanf("%d%d%d",&a,&b,&c);
        n2n[a].push_back({c,b});
        n2n[b].push_back({c,a});
    }
    printf("%d", spening());
    
    return 0;
}
