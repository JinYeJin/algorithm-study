    #include <iostream>
    #include <cmath>
    #include <vector>
    using namespace std;

    long long init(vector<long long> &a, vector<long long> &tree, long long node, long long start, long long end) {
        if (start == end) { // 좌우가 같다면 단말 노드라는 의미로 단말 노드 값을 넣어줍니다.
            return tree[node] = a[start]; // 트리는 왼쪽부터 채워지므로 왼쪽 값을 넣어주는 형식으로 작성하는게 좋습니다.
        } else {
            return tree[node] = min(init(a, tree, node*2, start, (start+end)/2),init(a, tree, node*2+1, (start+end)/2+1, end));
        } // 하위가 있을 경우, 왼쪽값과 오른쪽 값중 작은 값을 가져옵니다.
        // 즉 트리에는 작은 값이 들어 있습니다.
        // 만약 합일 경우에는 양값을 합한 값을 넣어주면 되고
        // 최대값일 때는 최대 값을 가지게 하면되고.
        // 최소 최대일 경우에는 클래스를 만들어 최소 최대 배열을 저장하게끔 하면 됩니다.
    }

    long long getMinValue(vector<long long> &a, vector<long long> &tree, long long node, long long start, long long end, long long left, long long right) {
        if(right < start || left > end) return -1; // 만약 오른쪽(종료 범위)가 시작보다 작거나, 왼쪽(시작 범위)가 종료보다 크면 -1
        if(left <= start && right >= end) return tree[node]; // 왼쪽(시작 범위)가 시작보다 작거나 오른쪽 (종료 범위)가 종료보다 크면 해당 노드 리턴
        // 이는 해당 지점에 도착한후 다음 과정으로 넘어갔다는 의미로 해당 노드의 값을 가져온다는 뜻이된다,
        long long val1 = getMinValue(a, tree, node*2, start, (start+end)/2, left, right); // 값 리턴 받아 온다.
        long long val2 = getMinValue(a, tree, node*2+1, (start+end)/2+1, end, left, right); // 값 리턴 받아 온다.
        if(val1 == -1) return val2; // -1 리턴 했다면 -> 범위가 아니였다면 val2리턴
        else if(val2 == -1) return val1; // -1 리턴 했다면 -> 범위가 아니였다면 val1리턴
        else return min(val1, val2); // 작은 값 리턴
    }

    int main() {

        long long n, m; // 노드수, 찾을 수
        cin >> n >> m; // 입력
        vector<long long> a(n+1); // 단말 노드를 나타내는 배열 만들기.
        long long h = (int)ceil(log2(n+1)); // 노드에 맞는 깊이 만들기.
        long long tree_size = (1 << (h+1)); // 트리 배열 크기 구하기.
        vector<long long> tree(tree_size); // 트리 배열 크기에 맞는 트리 구하기.

        for (int i=1; i <= n; i++) {
            cin >> a[i]; // 1부터 시작한 이유는 n-1 처리를 하지 않기 위해서입니다.
        }
        
        init(a, tree, 1, 1, n); // a 배열, tree, node, start, end
        // 0번은 0이므로 시작을 1로 주어야 합니다.
        // 만약 a배열을 0부터 초기화 하면 0을 넣어주어야 합니다.
        
        for(int i=0; i < m; i++){
            long long left, right; // 값 시작 범위 ~ 값 종료 범위
            cin >> left >> right; // 입력
            cout << getMinValue(a, tree, 1 , 1, n, left, right) << "\n"; // 검색 시작
        }
        
        return 0;
    }
