#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<long long> a;
vector<long long> tree;

long long init(long long node, long long start, long long end) {
    if (start == end) {return tree[node] = a[start] % 1000000007;} // 1개면 그냥 리턴
    return tree[node] = (init(node*2, start, (start+end)/2) * init(node*2+1, (start+end)/2+1, end)) % 1000000007; // 곱셈 진행, 나머지
}

long long getMultipleValue(long long node, long long start, long long end, long long left, long long right) {
    if(right < start || left > end) return -1; // 말도 안되는 값이라면
    if(left <= start && right >= end) return tree[node]; // 찾는 범위를 둘다 나간다면 노드 리턴
    long long leftValue = getMultipleValue(node*2, start, (start+end)/2, left, right);
    long long rightValue = getMultipleValue(node*2+1, (start+end)/2+1, end, left, right);
    
    if(leftValue == -1) return rightValue;
    else if(rightValue == -1) return leftValue;
    else return (leftValue*rightValue) % 1000000007;
}

long long update(long long node, long long start, long long end, long long index){
    if(start == end) return tree[node] = a[start] % 1000000007; // a의 값은 이미 외부에서 바뀜
    if(index < start || index > end) return tree[node]; // 다른 방향
    return tree[node] = (update(node*2, start, (start+end)/2, index)*update(node*2+1, (start+end)/2+1, end, index))% 1000000007;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
        
    long long n, m, k; // 노드수
    cin >> n >> m >>k; // 입력
    
    // 5 2 2입력되었음
    
    a.resize(n+1); // 단말 노드를 나타내는 배열 만들기.
    int h = (int)ceil(log2(n+1)); // 노드에 맞는 깊이 만들기.
    long long tree_size = (1 << (h+1)); // 트리 배열 크기 구하기.
    tree.resize(tree_size); // 트리 배열 크기에 맞는 트리 구하기.
    
    a[0] = 0; // 곱셈
    for (int i=1; i <= n; i++) {
        cin >> a[i]; // 1부터 시작한 이유는 n-1 처리를 하지 않기 위해서입니다.
    }
    
    init(1, 1, n); // a 배열, tree, node, start, end
     
    while (m != 0 || k != 0) {
        int command,from, to; // 1,2 입력 받음
        cin >> command >> from >> to;
        if(command == 1){ // 1일 경우
            m--;
            a[from] = to;
            update(1, 1, n, from); // 값 변경
        }
        if(command == 2){ // 일 경우
            k--;
            cout << getMultipleValue(1, 1, n, from, to) % 1000000007 << "\n";
        }
    }
    
    return 0;
}

