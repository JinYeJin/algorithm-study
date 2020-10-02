/*
[1068] https://www.acmicpc.net/problem/1068
*/
#include <stdio.h>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int erase, num_leaf = 0;
vector<vector<int>> tree(52);

void count_leaf(int idx){
    if(tree[idx].size() == 0){
        num_leaf++;
        return;
    }
    else if(tree[idx].size() == 1 && tree[idx][1] == erase){
        num_leaf++;
        return;
    }

    for(int i = 0; i < tree[idx].size(); i++){
        count_leaf(tree[idx][i]);
    }
}

int main(){
    // FILE *stream =freopen("S2\\17\\input\\1068.txt", "r", stdin);
    FILE *stream =freopen("S2/17/input/1068.txt", "r", stdin);
    if(!stream) perror("freopen");

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, temp, root;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> temp;
        if(temp == -1) root = i;
        else tree[temp].push_back(i);
    }

    cin >> erase;

    tree.erase(tree.begin() + erase);
    
    count_leaf(root);

    cout << num_leaf;
    return 0;
}
