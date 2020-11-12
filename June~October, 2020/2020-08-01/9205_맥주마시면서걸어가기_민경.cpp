// https://www.acmicpc.net/problem/9205
// 맨해튼 거리 주의

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> 

using namespace std;
const int MAX = 100 + 2; //출발점, 도착점 포함


int N;
vector<int> graph[MAX];
bool visited[MAX];


//맨해튼 거리
int distance(pair<int, int> p1, pair<int, int> p2){
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

void DFS(int node){

        visited[node] = true;

        for (int i = 0; i < graph[node].size(); i++){
            int next = graph[node][i];
            
            if (visited[next] == false)
                DFS(next);
        }
}

 
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test_case;
    cin >> test_case;
    
    for (int i = 0; i < test_case; i++){
        for (int j = 0; j < MAX; j++)
            graph[j].clear();
        
        memset(visited, false, sizeof(visited));
        cin >> N;
        vector<pair<int, int>> CU;
        
        //출발점(0), 도착점(N + 1) 포함
        for (int j = 0; j < N + 2; j++){
            int y, x;
            cin >> y >> x;
            CU.push_back(make_pair(y, x));
        }
        
        //맥주 20병으로 갈 수 있는 거리 내에 있으면 그래프에 추가
        for(int j=0; j<N+2; j++)
            for(int k=j+1; k<N+2; k++)
                if (distance(CU[j], CU[k]) <= 50 * 20){
                    //양방향 그래프
                    graph[j].push_back(k);
                    graph[k].push_back(j);
                }
        DFS(0);
        //0이 출발점, N+1이 도착점이므로
        if (visited[N + 1])
            cout << "happy\n";
        else
            cout << "sad\n";
    }
    return 0;

}



