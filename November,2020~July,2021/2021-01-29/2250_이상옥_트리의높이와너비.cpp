#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct node{
    node* left;
    node* right;
};

node* Node[10001];
bool sub[10001]={0};
map<int, int> min_map,max_map;
int x=0,max_deep=0;
void in_order(node* n,int deep){
    if(n==NULL) return;
    in_order(n->left,deep+1);
    if(min_map.find(deep)==min_map.end()){
        min_map[deep]=x;
    }
    max_map[deep]=x++;
    max_deep=max(max_deep,deep);
    in_order(n->right,deep+1);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int N,n,l,r;
    cin>>N;
    for(int i=1;i<=N;i++){
        Node[i]=(node*)malloc(sizeof(node));
        Node[i]->left=NULL;
        Node[i]->right=NULL;
    }
    for(int i=0;i<N;i++){
        cin>>n>>l>>r;
        if(l!=-1){
            Node[n]->left=Node[l];
            sub[l]=1;
        }
        if(r!=-1){
            Node[n]->right=Node[r];
            sub[r]=1;
        }
    }
    for(int i=1;i<=N;i++){
        if(sub[i]==0){
            in_order(Node[i],1);
            break;
        }
    }
    int deep_answer=0,answer=0;
    for(int i=1;i<=max_deep;i++){
        if(answer<max_map[i]-min_map[i]+1){
            deep_answer=i;
            answer=max_map[i]-min_map[i]+1;
        }
    }
    cout<<deep_answer<<'\n'<<answer;
    return 0;
}
