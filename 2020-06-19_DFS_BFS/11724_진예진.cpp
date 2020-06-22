/*
2020-06-18 진예진
[백준 11724 연결 요소의 개수] https://www.acmicpc.net/problem/11724
참고 https://penglog.tistory.com/51
*/

#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

int N, M;
vector<int> nodes[1001];
bool visited[1001];
int start_node, end_node; // 시작점, 끝점
int num_of_component;
stack<int> index_to_search;

int main(){
    FILE *stream = freopen("S2\\3\\11724_input.txt", "r", stdin);
    if(!stream) perror("freopen");

    // N: 노드의 개수, M: 엣지의 개수
    scanf("%d %d", &N, &M);

    // 방향이 없기 때문에 양 방향을 모두 벡터에 추가해 줌
    // 노드의 개수만큼 입력받음
    for(int i = 0; i < M; i++){
        scanf("%d %d", &start_node, &end_node);
        nodes[start_node].push_back(end_node);
        nodes[end_node].push_back(start_node);
    }

    // 정답으로 출력해야하는 컴포넌트의 개수
    num_of_component = 0;

    // 방문하지 않은 시작점 수 == 노드 개수
    // 노드가 1부터 주어지기 떄무넹 1부터 시작
    for(int i = 1; i <= N; i++) {
        // 방문한 적이 없으면
        if(!visited[i]) {
            // 방문체크
            visited[i] = true;
            // 순회해야할 index를 넣어줌
            index_to_search.push(i);
            // component가 시작되는 순간에 component 개수 하나 증가
            num_of_component++;
        }
        // 현재 컴포넌트가 어디까지 이어져 있는지 확인
        while (!index_to_search.empty()) {
            int index = index_to_search.top();
            index_to_search.pop();

            // 한 노드에서 연결된 노드를 모두 타고 따라 들어감
            // j 가 순회할 배열은 push_back으로 원소를 넣었기 때문에 0부터 순회
            for(int j = 0; j < nodes[index].size(); j++){
                // 가면서 방문한 적이 없으면 또 노드에 넣음 
                if(!visited[nodes[index][j]]){
                    index_to_search.push(nodes[index][j]);
                    // 방문체크
                    visited[nodes[index][j]] = true;
                }
            }
 
        }
    }
    printf("%d", num_of_component);
    return 0;
}
