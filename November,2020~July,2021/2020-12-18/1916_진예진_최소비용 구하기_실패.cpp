/*
[백준 1916 최소비용 구하기] https://www.acmicpc.net/problem/1916
*/
#include <stdio.h>
#include <iostream> 
#include <string.h>
#include <algorithm>
#define INF 987654321

using namespace std;

int cost[1001][1001];
int dist[1001];
bool visited[1001];

int main(){
    FILE *stream =freopen("S2\\25\\input\\1916.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int M, N;
    int v1, v2, w;
    int start, end;

    memset(visited, false, sizeof(visited));

    cin >> N;
    cin >> M;

    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            cost[i][j] = INF;
        }
    }

    for(int i = 0; i <= N; i++){
        dist[i] = INF;
    }

    for(int i = 0; i < M; i++){
        cin >> v1 >> v2 >> w;
        cost[v1][v2] = min(cost[v1][v2], w);
    }

    cin >> start >> end;


    // start 부터 i까지의 거리로 초기화
    for(int i = 0; i <= N; i++){
        dist[i] = cost[start][i];
    }

    int min_v = start;
    visited[start] = true;

    for(int i = 0; i < N; i++){
        int min_weight = INF;
        
        // 최소비용을 가지는 weight와 간선 구하기
        for(int j =1; j <= N; j++){
            if(visited[j] == false){
                if(dist[j] < min_weight){
                    min_v = j;
                    min_weight = dist[j];
                }
            }
        }

        for(int j = 1; j <= N; j++){
            if(visited[j] == true) continue;
            if(cost[min_v][j] == INF) continue;
            
            int temp_min = dist[min_v] + cost[min_v][j];

            if(temp_min < dist[j]) dist[j] = temp_min;
        }

        visited[min_v] == true;
    }

    cout << dist[end];
    return 0;
}
