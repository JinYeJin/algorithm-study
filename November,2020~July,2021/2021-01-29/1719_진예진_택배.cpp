/*
1719 택배
*/

#include <stdio.h>
#include <iostream>
#define MAX 987654321

using namespace std;

int main(){
    FILE *stream = freopen("S2\\30\\input\\1719.txt", "r", stdin);
    if(!stream) perror("freopen");

    int N, M;
    int V, E, C;
    int container[201][201];
    int route[201][201];

    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            container[i][j] = MAX;
        }
    }

    for(int i = 0; i < M; i++){
        cin >> V >> E >> C;

        container[V][E] = C;
        container[E][V] = C;
        route[V][E] = E;
        route[E][V] = V;
    }

    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(container[i][j] >  container[i][k] + container[k][j]){
                    container[i][j] = container[i][k] + container[k][j];
                    route[i][j] = route[i][k];
                }
            }
        }
    }
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(i == j) cout << "- ";
            else cout << route[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
