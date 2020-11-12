#include <iostream>

using namespace std;


class treeNode {
public:
	friend class tree;

	treeNode *left;
	treeNode *right;
	int value;

	treeNode(int val) :value(val) {}
};
class tree {
public:
	treeNode *root;
	
	void insert_node(treeNode *& node,int val) {
		if (node == NULL)
			node = new treeNode(val);
		else if (val < node->value)
			insert_node(node->left, val);
		else
			insert_node(node->right, val);

	}
	void postorder_print(treeNode *& node) {
		if (node != NULL) {
			postorder_print(node->left);
			postorder_print(node->right);
			cout << node->value <<'\n';
		}
	}

	tree(): root(NULL) {}
};
int main()
{
	ios_base::sync_with_stdio(false);// 200 -> 196ms
	tree * binary_tree = new tree();
	int a;
	while (  cin>> a  )//  ~scanf("%d", &a) 이것도 가능
		binary_tree->insert_node(binary_tree->root,a);
	

	binary_tree->postorder_print(binary_tree->root);

}