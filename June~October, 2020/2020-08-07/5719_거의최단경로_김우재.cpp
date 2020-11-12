#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int d[501];
void dijkstra(int start, vector<pair<int, int>> list[501] , vector<int> from[501]){
    priority_queue<pair<int, int>> pq;
    d[start] = 0;
    pq.push(make_pair(start, 0));
    
    while(!pq.empty()){
        int now = pq.top().first;
        int val = pq.top().second;
        pq.pop();
        for(int i=0; i < list[now].size(); i++){
            int next = list[now][i].first;
            int cost = list[now][i].second;
            if(cost == -1) continue;
            if(d[next] == -1 || d[next] >= val + cost){
                from[next].push_back(now);
                d[next] = val + cost;
                pq.push(make_pair(next, val+cost));
            }
        }
    }
}

void bfs(int end, vector<pair<int, int>> list[501], vector<int> from[501]) {
    queue<int> q; // 최단경로에 있는 노드들을 담을 큐
    q.push(end);
    while (!q.empty()) {
        int now = q.front(); q.pop(); // 마지막
        for(int i=0; i < from[now].size(); i++){ // 역추적 이동할 곳 찾음.
            int next = from[now][i];
            for(int j=0; j < list[next].size(); j++){
                if(list[next][j].second == -1) continue;
                if(d[now] == d[next] + list[next][j].second){
                    if(list[next][j].first != now) continue;
                    q.push(next);
                    list[next][j].second = -1;
                }
            }
        }
    }
}

int main(){
    while(true){
        memset(d, -1, sizeof(d));
        int n, r;
        cin >> n >> r;
        if(n == 0 && r == 0) break;
        
        int start, end;
        cin >> start >> end;
        
        vector<pair<int, int>> list[501];
        
        
        for(int i = 0; i < r; i++){
            int go, to, val;
            cin >> go >> to >> val;
            list[go].push_back(make_pair(to, val));
        }
         
        vector<int> from[501];
        /*
        cout << "\n bfs before \n";
        for(int i=0; i < n; i++){
            for(int j=0; j < list[i].size(); j++){
                cout << "go : " << i;
                cout << " to ";
                cout << " ";
                cout << list[i][j].first << " : ";
                cout << list[i][j].second << "\n";
            }
        }
        */
        dijkstra(start, list, from);
        bfs(end, list, from);
        memset(d, -1, sizeof(d));
        /*
        cout << "\n bfs after \n";
        for(int i=0; i < n; i++){
            for(int j=0; j < list[i].size(); j++){
                cout << "go : " << i;
                cout << " to ";
                cout << " ";
                cout << list[i][j].first << " : ";
                cout << list[i][j].second << "\n";
            }
        }
        */
        dijkstra(start, list, from);
        cout << d[end] << "\n";
    }
    return 0;
}
