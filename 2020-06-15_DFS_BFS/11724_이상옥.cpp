#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> node2node;
vector<bool> visited_node;
void connected_node(int);

int main(int argc, const char * argv[]){
    int node, line, answer = 0;
    int n1, n2;

    cin>>node>>line;
    node2node.resize(node+1);
    visited_node.resize(node+1,false);
    for(int i = 0; i<line; i++){
        cin>>n1>>n2;
        node2node[n1].push_back(n2);
        node2node[n2].push_back(n1);
    }
    
    for(int i=1; i<node+1; i++){
        if(!visited_node[i]){ //방문하지 않았을경우
            visited_node[i] = true;
            answer++;
            connected_node(i);
        }
    }
    cout<<answer<<endl;
    return 0;
}
void connected_node(int node){
    for( int next : node2node[node] ){
        if(!visited_node[next]){
            visited_node[next] = true;
            connected_node(next);
        }
    }
}
