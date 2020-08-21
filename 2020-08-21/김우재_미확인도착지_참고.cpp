/*
 참고 사이트 : https://yabmoons.tistory.com/390
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

void dijkstra(int start, int map[2001], vector<pair<int, int>> list[2001]){
    queue<pair<int, int>> q;
    map[start] = 0;
    q.push(make_pair(start, 0));
    
    while(!q.empty()){
        int now = q.front().first;
        int value = q.front().second;
        q.pop();
        for(int i=0; i < list[now].size(); i++){
            int next = list[now][i].first;
            int next_value = list[now][i].second + value;
            if(map[next] == -1 || map[next] > next_value){
                map[next] = next_value;
                q.push(make_pair(next, next_value));
            }
        }
    }
}

int main(void){
    int T;
    cin >> T;
    while(T--){
        int n , m, t; // 노드, 도로, 후보
        cin >> n >> m >> t;
        int s , g, h;
        cin >> s >> g >> h;
        
        vector<pair<int, int>> list[2001];
        for(int i=0; i < m; i++){
            int a,b,d;
            cin >> a >> b >> d;
            list[a].push_back(make_pair(b, d));
            list[b].push_back(make_pair(a, d));
        }
        
        vector<int> pred;
        for(int i=0; i < t; i++){
            int x; cin >> x;
            pred.push_back(x);
        }
        sort(pred.begin(), pred.end());
        
        int map[2001]; memset(map, -1, sizeof(map));
        int mapg[2001]; memset(mapg, -1, sizeof(mapg));
        int maph[2001]; memset(maph, -1, sizeof(maph));
        
        dijkstra(s, map, list);
        dijkstra(g, mapg, list);
        dijkstra(h, maph, list);
        
        /*
        for(int i=1; i <= n; i++){
            cout << maph[i] << " ";
        }
        */
        
        for (int i = 0; i < pred.size(); i++)
        {
            int predict = pred[i];
            if (map[predict] == map[g] + mapg[h] + maph[predict]) cout << predict << " ";
            else if (map[predict] == map[h] + maph[g] + mapg[predict]) cout << predict << " ";
        }

    }
    return 0;
}
