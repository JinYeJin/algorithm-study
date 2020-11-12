#include <iostream>
#include <vector>
#include <queue>

# define MAX 501

using namespace std;


int n;
int inDegree[MAX]; // 각 노드의 현재 진입차수를 저장하는 배열
int timeArr[MAX];
int d[MAX];
vector<int> arr[MAX];

void topologySort(){
    int result[MAX];
    queue<pair<int, int>> q;

    // 진입 차수가 0인 노드를 큐에 삽입합니다.
    for(int i=1; i <= n; i++){
        if(inDegree[i] == 0){
            q.push(make_pair(i, timeArr[i]));
            d[i] = timeArr[i];
        }
    }

    // 위상 정렬이 완전히 수행되려면 정확히 N개의 노드를 방문합니다.
    for(int i=1; i <= n; i++){
        // n개를 방문하기 전에 큐가 빈다면 사이클이 발생한 것입니다.
        if(q.empty()){
            cout << "사이클이 발생했습니다.\n";
            return;
        }
        int x = q.front().first; // 하나씩 빼주기
        int v = q.front().second; // 누적값
        q.pop();

        result[i] = x; // 이동한 노드를 의미하므로 result 에도 입력
        for(int j=0; j < arr[x].size(); j++){ // 이동한 노드와 연결된 간선 만큼 순회 -> 이들을 처리해주려고
            int y = arr[x][j]; // 다음 이동 노드
            d[y] = max(d[y], timeArr[y] + v);
            if(--inDegree[y] == 0){ // 다음 이동 노드의 값을 1 빼준게 -1 이라면 0인 노드이므로 큐에 입력
                q.push(make_pair(y, d[y])); // 다음 이동 + 누적값
            }
        }
    }
    for(int i=1; i <= n; i++){
        cout << d[i] << "\n";
    }
    
}


int main(){
    cin >> n;
    for(int i=1; i <= n; i++){
        int time; cin >> time;
        timeArr[i] = time;
        while (true) {
            int no; cin >> no;
            if(no == -1) break;
            arr[no].push_back(i);
            inDegree[i]++;
        }
    }
    topologySort();

    return 0;
}
