#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int d[101];
int main() {
    memset(d, -1, sizeof(d));
    int n; cin >> n; // 사람의 수 node
    int a, b; cin >> a >> b; // 촌수 계산 2사람 -> 1부터 시작
    int m; cin >> m; // 부모 자식들간의 관계.
    vector<int> list[n+1];
    
    // 부모 자식간의 관계를 가지는 형태.
    for(int i=0; i < m; i++){
        int parent, child;
        cin >> parent >> child;
        list[parent].push_back(child);
        list[child].push_back(parent);

    }
    
    d[a] = 0;
    queue<int> q;
    q.push(a);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for(int i=0; i < list[now].size(); i++){
            int next = list[now][i];
            if(d[next] == -1 || d[next] > d[now]+1){
                d[next] = d[now]+1;
                q.push(next);
            }
        }
    }
    
    cout << d[b] << "\n";

    
    return 0;
}
