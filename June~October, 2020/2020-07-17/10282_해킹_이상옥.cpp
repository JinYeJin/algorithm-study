#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N,n,d,c,a,b,s,cnt=0,s_cnt;
    pair<int,int> h;
    cin>>N;
    while(N--!=0){
        cin>>n>>d>>c;
        vector<bool> visited(n+1,false);
        vector<pair<int,int>> heap(1,{0,c});
        vector<vector<pair<int,int>>> PC(n+1);

        while(d--!=0){
            cin>>a>>b>>s;
            PC[b].push_back({-s,a});
        }
        
        cnt=0;

        while(!heap.empty()){
            h=heap.front();
            pop_heap(heap.begin(),heap.end());
            heap.pop_back();
            
            s=h.first;
            a=h.second;
            if(visited[a]) continue;

            cnt++;
            s_cnt=-s;
            visited[a]=true;

            for(auto PC_a : PC[a]){ //b->a 감염
                heap.push_back({s+PC_a.first, PC_a.second});
                push_heap(heap.begin(),heap.end());
            }
        }
        cout<<cnt<<" "<<s_cnt<<endl;
    }
    return 0;
}
