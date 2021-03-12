/*
17199 milk factory
*/
#include <stdio.h>
#include <iostream> 
#include <string.h>
#include <queue>

using namespace std;

int main(){
    FILE *stream =freopen("S2\\34\\input\\17199.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, a, b;
    bool conveyor[101][101];
    bool visited[101];
    int connected[101];

    memset(conveyor, false, sizeof(conveyor));
    memset(visited, false, sizeof(visited));
    memset(connected, 0, sizeof(connected));

    cin >> N;

    for(int n = 0; n < N; n++){
        cin >> a >> b; 
        conveyor[a][b] = true; // a -> b one way
    }

    queue<int> path;

    for(int n = 1; n <= N; n++){
        memset(visited, false, sizeof(visited));
        path.push(n);
        
        while(!path.empty()){
            int i = path.front();
            path.pop();

            for(int j = 1; j <= N; j++){
                if(conveyor[i][j] && !visited[j]){
                    path.push(j);
                    visited[j] = true;
                }
            }
        }

        for(int i = 1; i <= N; i++){
            connected[i] += visited[i];
        }
    }

    for(int n = 1; n <= N; n++){
        if(connected[n] == N-1){
            cout << n;
            return 0;
        }
    }

    cout << -1;

    return 0;
}
