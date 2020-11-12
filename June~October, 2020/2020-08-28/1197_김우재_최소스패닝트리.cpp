#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
 
using namespace std;
 
int node, line, answer;
int parent[10001];

vector<tuple<int,int, int>> list;

int find_parent(int x) { // 부모를 찾는것
    if (parent[x] == x) return x; // x의 부모가 x라면 x리턴
    else return parent[x] = find_parent(parent[x]); // 아니면 부모의 부모를 찾는다. -> 최상단 루트 노드를 찾는 것 같다.
}
 
void merge_node(int x, int y) {
    x = find_parent(x); // x의 부모
    y = find_parent(y); // y의 부모
 
    if (x != y) parent[y] = x; // 다르면 y의 부모를 x로 만든다. 즉, y의 부모로 x를 넣겠다는 말
}
 
bool isSameParent(int x, int y){ // 부모가 같은지를 검색한다.
    x = find_parent(x); // 노드 x의 부모를 찾기
    y = find_parent(y); // 노드 y의 부모를 찾기
    
    if (x == y) return true; // 같다면 트루
    else return false; // 다르면 펄스
}

int main(void)
{
    cin >> node >> line; // 정점의 개수, 간선의 개수
    for(int i = 0; i < line; i++) {
        int from, to, cost; // 출발 도착 가중치
        cin >> from >> to >> cost;
        list.push_back(make_tuple(cost, from, to)); // tuple로 입력
    }
    sort(list.begin(), list.end()); // 최소신장 트리이므로 비용이 작은것부터 실행
    
    for (int i = 1; i <= node; i++) {
        parent[i] = i; // 부모는 자기자신을 나타낸다.
    }
    
    for (int i = 0; i < line; i++) { // 간선 갯수만큼 실행
        int from, to, cost;
        cost = get<0>(list[i]); // 값하나씩 꺼내기
        from = get<1>(list[i]);
        to = get<2>(list[i]);
        if (isSameParent(from, to) == false) { // 부모가 같지 않다면
            merge_node(from, to); // 이둘을 합친다.
            answer = answer + cost; // 결과값에 가중치 추가
        }
    }
    cout << answer << "\n";
    return 0;
}
