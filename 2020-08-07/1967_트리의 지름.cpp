/*
[1967 트리의 지름]
https://lmcoa15.tistory.com/56
*/

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

typedef struct Node{
    Node(int node, int length): node(node), length(length) {}
    int node, length;
}Node;
 
int n;
int ans = 0;
int end_point = 0;
int visited[10002];
vector<Node> node[10002];
 
void dfs(int point,int length){
    
    if(visited[point])
        return;
    
    visited[point] = 1;
    if(ans < length){
        ans = length;
        end_point = point;
    }
    
    for(int i = 0; i < node[point].size(); i++){
        dfs(node[point][i].node, length+node[point][i].length);
    }
}
 
int main(){
    FILE *stream =freopen("S2/10/input/1967.txt", "r", stdin);
    if(!stream) perror("freopen");
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    
    int parent, child, length;

    for(int i=0;i<n-1;i++){
        scanf("%d %d %d", &parent, &child, &length);
        node[parent].push_back(Node(child, length));
        node[child].push_back(Node(parent, length));
    } 
    
    //가장 멀리 있는 정점(end_point) 구하기
    dfs(1,0);
 
    ans = 0;
    memset(visited, 0, sizeof(visited));
    
    //end_point와 가장 멀리 있는 정점과의 거리 구하기
    dfs(end_point, 0);
    cout<< ans << endl;
    
 
    return 0;
}
