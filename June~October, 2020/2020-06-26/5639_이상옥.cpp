#include <iostream>

using namespace std;

struct Node{
    Node* left;
    Node* right;
    int value;
};
void postorder(Node* node){
    if(node->left!=NULL) postorder(node->left);
    if(node->right!=NULL) postorder(node->right);
    cout<<node->value<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int input;
    cin>>input;
    Node* root = (Node*)malloc(sizeof(Node));
    root->value = input;
    root->left = NULL;
    root->right = NULL;

    Node* parent;
    while(cin>>input){
        Node* node = (Node*)malloc(sizeof(Node));
        node->value = input;
        node->left = NULL;
        node->right = NULL;
        
        parent = root;
        while(true){
            if(parent->value > input){
                if(parent->left == NULL){
                    parent->left = node;
                    break;
                }
                parent = parent->left;
            }
            else{
                if(parent->right == NULL){
                    parent->right = node;
                    break;
                }
                parent = parent->right;
            }
        }
        parent = node;
    }
    postorder(root);
    return 0;
}

