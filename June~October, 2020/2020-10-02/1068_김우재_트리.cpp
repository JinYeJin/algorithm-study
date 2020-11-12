#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n;
vector<int> list[51];
bool ok[51];

int main(){
    cin >> n;
    memset(ok, true, sizeof(ok));
    int answer = 0;
    int startNode = 0;
    
    for(int i=0; i < n; i++){
        int parent; cin >> parent;
        if(parent == -1) {
            startNode = i;
            continue;
        }
        list[i].push_back(parent);
        list[parent].push_back(i);
    }
    
    int deleteNode; cin >> deleteNode;
    ok[deleteNode] = false;
    if(deleteNode == startNode) {cout << 0 << "\n"; return 0;}
        
    queue<int> q;
    q.push(startNode);
    ok[startNode] = false;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        int child = 0;
        for(int i=0; i < list[now].size(); i++){
            int next = list[now][i];
            if(ok[next]){
                child++;
                ok[next] = false;
                q.push(next);
            }
        }
        if(child == 0){
            answer++;
        }
    }
    cout << answer << "\n";

    return 0;
}
