/*
백준 2250 트리의 높이와 너비
https://blog.naver.com/4717010/60209908735
풀면서 반ㄹㅖ https://www.acmicpc.net/board/view/18354
#dfs #중위순회 #inorder 
*/
#include <stdio.h>
#include <iostream> 
#include <vector>
#include <set>

using namespace std;

typedef struct Node{
    Node(int left, int right): left(left), right(right) {}
    int left, right;
}Node;

int max_depth;
int min_left[10001]; // level 의 제일 좌측
int max_right[10001];
vector<Node> tree(10001, Node(-1, -1));
vector<int> column; // 각 숫자의 열
vector<int> depth(10001); // 각 숫자의 level

int count_node(int index, int level){
    int sum_node = 0;
    int next = tree[index].left;

    if(next != -1) {
        sum_node += count_node(next, level+1);
        sum_node++;
    }

    max_depth = max_depth < level ? level : max_depth;
    column.push_back(index);
    depth[index] = level;
    next = tree[index].right;


    if(next != -1){
        sum_node += count_node(next, level+1);
        sum_node++;
    }

    return sum_node;
}


int main(){
    FILE *stream =freopen("S2\\30\\input\\2250.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, parent, left, right, root;
    set<int> is_parent;

    cin >> N;

    for(int n = 1; n <= N; n ++){
        is_parent.insert(n);
        min_left[n] = 987654321;
    }


    for(int n = 0; n < N; n++){
        cin >> parent >> left >> right;
        tree[parent].left = left;
        tree[parent].right = right;
        is_parent.erase(left);
        is_parent.erase(right);
    }

    root = *is_parent.begin();
    column.push_back(0);

    count_node(root, 1);

    for(int i = 1; i <= N; i++){
        int node_num = column[i];
        int depth_pos = depth[node_num];
        min_left[depth_pos] = min_left[depth_pos] > i ? i : min_left[depth_pos];
        max_right[depth_pos] = max_right[depth_pos] < i ? i : max_right[depth_pos];
    }

    int answer_level;
    int max_width = -1;

    for(int i = 1; i <= max_depth; i++){
        int width = 0;
        // 둘 중 하나라도 0 이면 ㄴ너비가 없다는 소
        if((max_right[i] != 0) && (min_left[i] != 0))
            width = max_right[i] - min_left[i] + 1;
        if(max_width < width){
            max_width = width;
            answer_level = i;
        }
    }

    if(max_width == 0) max_width = 2;
    cout << answer_level << " " << max_width;

    return 0;
}
