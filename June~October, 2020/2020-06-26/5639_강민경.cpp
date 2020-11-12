// https://www.acmicpc.net/problem/5639 이진검색트리
// 런타임
#include<iostream>
#include<cstdio>
using namespace std;

struct Tree {
	int left = 0;
	int right = 0;
};

Tree tree[100002];

void postOrder(int node) {
	if (tree[node].left != 0) {
		postOrder(tree[node].left);
	}
	if (tree[node].right != 0) {
		postOrder(tree[node].right);
	}
	cout << node << endl;


}

int main() {
	int root;
	int value;
	cin >> root;
	while (cin >> value) {
		int node = root;
		while (true) {
			if (node < value) {
				if (tree[node].right != 0) {
					node = tree[node].right;
				}
				else {
					tree[node].right = value;
					break;
				}
			}
			else {
				if (tree[node].left != 0) {
					node = tree[node].left;
				}
				else {
					tree[node].left = value;
					break;
				}
			}
		}
	}
	postOrder(root);
	return 0;
}
