#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int getMinIndex(vector<long long> &a, int x, int y){
    if(a[x] == a[y]){
        if(x > y) return y;
        else return x;
    } else if( a[x] < a[y]) return x;
    else return y;
}

int init(vector<long long> &a, vector<long long> &tree, int node, int start, int end){
    if(start == end) return tree[node] = start;
    return tree[node] = getMinIndex(a, init(a, tree, node*2, start, (start+end)/2), init(a, tree, (node*2)+1, (start+end)/2+1, end));
}

int update(vector<long long> &a, vector<long long> &tree, int node, int start, int end, int index){
    if(start == end) return tree[node] = start;
    if(index < start || index > end) return tree[node];
    return tree[node] = getMinIndex(a, update(a, tree, node*2, start, (start+end)/2, index),
                                    update(a, tree, node*2+1, (start+end)/2+1, end, index));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
        
    int n; // 노드수
    cin >> n; // 입력
    
    vector<long long> a(n+1); // 단말 노드를 나타내는 배열 만들기.
    int h = (int)ceil(log2(n+1)); // 노드에 맞는 깊이 만들기.
    long long tree_size = (1 << (h+1)); // 트리 배열 크기 구하기.
    vector<long long> tree(tree_size); // 트리 배열 크기에 맞는 트리 구하기.
    
    a[0] = 0;
    for (int i=1; i <= n; i++) {
        cin >> a[i]; // 1부터 시작한 이유는 n-1 처리를 하지 않기 위해서입니다.
    }
    
    init(a, tree, 1, 1, n); // a 배열, tree, node, start, end
    // 0번은 0이므로 시작을 1로 주어야 합니다.
    // 만약 a배열을 0부터 초기화 하면 0을 넣어주어야 합니다.
    
    // tree[1] 에는 최솟값이 들어 있다.
    int m;
    cin >> m;
    for(int i=0; i < m; i++){
        int command;
        cin >> command;
        if(command == 1){
            int changedNode, changedValue;
            cin >> changedNode >> changedValue;
            a[changedNode] = changedValue;
            update(a, tree, 1, 1, n, changedNode);
        }
        if(command == 2){
            cout << tree[1] << "\n";
        }
    }
        
    return 0;
}
