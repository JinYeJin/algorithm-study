#include <stdio.h>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

typedef struct Node{
    Node(int dst, int weight): dst(dst), weight(weight) {}
    int dst, weight;
}Node;

bool visited[10001] = { false, };
vector<vector<Node>> graph(10001);

int main(){
    FILE *stream =freopen("S2\\13\\input\\1197.txt", "r", stdin);
    if(!stream) perror("freopen");

    int num_node, num_edge;
    int a, b, w;
    int min_w;
    long long total_weight = 0;

    scanf("%d %d", &num_node, &num_edge);


    for(int i = 0; i < num_edge; i++){
        scanf("%d %d %d", &a, &b, &w);
        // 양방향 연결
        graph[a].push_back(Node(b, w));
        graph[b].push_back(Node(a, w));
    }

    int index = 1;
    int b_index, next_index;
    int current_w;
    int node_cnt = 0;

    while(node_cnt < num_node){
        if(visited[index] == true){
            index = (index + 1) % num_node;
        }
        else{
            visited[index] = true;
            min_w = INT_MAX;
            for(int j = 0; j < graph[index].size(); j++){
                current_w = graph[index][j].weight;
                b_index = graph[index][j].dst;

                if(!visited[b_index] && current_w < min_w){
                    min_w = current_w;
                    next_index = b_index;
                }
            }
            // 찾은 노드의 가중치를 더해주고 다음 탐색 노드를 업데이트 해줌, 찾은 노드개수 증가
            if(min_w != INT_MAX) total_weight += min_w;
            index = next_index;
            node_cnt++;
        }
    }

    printf("%d", total_weight);

    return 0;
}
