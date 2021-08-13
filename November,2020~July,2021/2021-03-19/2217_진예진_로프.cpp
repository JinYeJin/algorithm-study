/*
2217 로프 
*/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    FILE *stream =freopen("S2\\35\\input\\2217.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, W;
    vector<int> rope;

    cin >> N;

    for(int n = 0; n < N; n++){
        cin >> W;
        rope.push_back(W);
    }

    sort(rope.begin(), rope.end());

    int max_wieght = 0;

    for(int i = 0; i < rope.size(); i++){
        int local_weight = rope[i] * (rope.size() - i);
        max_wieght = local_weight > max_wieght ? local_weight : max_wieght;
    }

    cout << max_wieght;

    return 0;
}
