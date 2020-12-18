/*
[백준 2630 색종이]
*/
#include <stdio.h>
#include <iostream>

using namespace std;

int n;
int paper[128][128];
int num_blue, num_white;


void dfs(int x, int y, int size){
    int current_color = paper[y][x];
    for (int r = y; r < y + size; r++){
        for (int c = x; c < x + size; c++){
            if (paper[r][c] != current_color){
                dfs(x, y, size / 2);
                dfs(x, y + size / 2, size / 2);
                dfs(x + size / 2, y, size / 2);
                dfs(x + size / 2, y + size / 2, size / 2);
                return;
            }
        }
    }
    if (current_color == 0) num_white++;
    else num_blue++;
}
int main(){
    FILE *stream =freopen("S2\\25\\input\\2630.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> paper[i][j];
        }
    }

    dfs(0, 0, n);
    cout << num_white << '\n';
    cout << num_blue << '\n';
    return 0;
}
