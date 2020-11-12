#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int N, M, arr[100000];
struct Node{
    int min_num;
    int s;
    int e;
    Node* left;
    Node* right;
};
void make_segtree(Node* node, int a, int b){
    node->s=a;
    node->e=b;
    if(a==b){
        node->min_num=arr[a];
        return;
    }
    int m=(a+b)/2;
    Node* left_node = new Node;
    Node* right_node = new Node;
    node->left=left_node;
    node->right=right_node;
    make_segtree(left_node,a, m);
    make_segtree(right_node, m+1, b);
    node->min_num = min(left_node->min_num, right_node->min_num);
}
int get_segtree(Node* node, int a, int b){
    if(node->s == a and node->e == b) return node->min_num;
    int m= (node->s+node->e)/2;
    if(m<a)
        return get_segtree(node->right, a, b);
    if(b<=m)
        return get_segtree(node->left, a, b);
    return min(get_segtree(node->left, a, m), get_segtree(node->right, m+1, b));
}
int main(){
    scanf("%d%d",&N, &M);
    for(int i=0; i<N; i++){
        scanf("%d", arr+i);
    }
    Node* root = new Node;
    make_segtree(root,0,N-1);
    while(M--){
        int a, b;
        scanf("%d%d",&a, &b);
        printf("%d\n", get_segtree(root, a-1, b-1));
    }
    return 0;
}

