/*
[백준 9370 미확인 도착지] https://www.acmicpc.net/problem/9370
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <limits.h>
#define INF 1002
#define MAX_SIZE 2002

using namespace std;

int testcase, N, M, T, S, G, H;
int city[MAX_SIZE][MAX_SIZE]; // weight
int distance_arr[MAX_SIZE];
int min_S[MAX_SIZE], min_G[MAX_SIZE], min_H[MAX_SIZE];
int dest_candidate[101];
bool visited[MAX_SIZE];
vector<int> answer;

void input_values(){
    // 교차로, 도록, 목적지 각각 후보개수
    scanf("%d %d %d", &N, &M, &T);
    // 시작점, 지나간 간선의 노드 G, H
    scanf("%d %d %d", &S, &G, &H);

    int a, b, d;

    // 최대 비용은 1000
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(i == j) city[i][j] = 0;
            city[i][j] = INF;
        }
    }

    for(int i = 0; i < M; i++){
        scanf("%d %d %d", &a, &b, &d);
        city[a][b] = d;
        city[b][a] = d;
    }

    for(int i = 0; i < T; i++){
        scanf("%d", &dest_candidate[i]);
    }
}

void init_values(int start){
    for(int i = 1; i <= N; i++){
        distance_arr[i] = city[start][i];
        visited[i] = false;
    }
}

int get_least_weight(int n){
    int min_value, min_index;
    min_value = INT_MAX;
    min_index = -1;

    for(int i = 1; i <= n; i++){
        if(visited[i] == false)
            min_value = min(distance_arr[i], min_value);
        min_index = i;
    }
    return min_index;
}

void dijkstra(int start){
    visited[start] = true;
    distance_arr[start] = 0;

    int u; // 새로 찾을 최소비용 정점

    // 시작노드는 빼고 N-1 번 돌아야 함
    for(int i = 0; i < N-1; i++){
        // 최소비용 경로
        u = get_least_weight(i);

        visited[u] = true;

        for(int w = 1; w <= N; w++){
            if(visited[w] == false){
                if((u == G && w == H) || (u == H && w == G)) distance_arr[w] = distance_arr[u] + city[u][w];
                else distance_arr[w] = min(distance_arr[w], distance_arr[u] + city[u][w]);
            }
        }
    }
}

int main(){
    FILE *stream =freopen("S2\\12\\input\\9370.txt", "r", stdin);
    if(!stream) perror("freopen");
    
 
    scanf("%d", &testcase);

    for(int t = 0; t < testcase; t++){

        input_values();

        init_values(S);
        dijkstra(S);
        copy(distance_arr, distance_arr + MAX_SIZE, min_S);

        init_values(G);
        dijkstra(G);
        copy(distance_arr, distance_arr + MAX_SIZE, min_G);

        init_values(H);
        dijkstra(H);
        copy(distance_arr, distance_arr + MAX_SIZE, min_H);

        answer.clear();

        for(int i = 0; i < T; i++){
            int dest_index = dest_candidate[i];
            int route_a = min_S[G] + min_G[H] + min_H[dest_index];
            int route_b = min_S[H] + min_H[G] + min_G[dest_index];
            // printf("%d\n", dest_index);
            // printf("%d\n", min_S[dest_index]);
            // printf("%d %d\n", route_a, route_b);
            if(min_S[dest_index] == route_a || min_S[dest_index] == route_b)
                answer.push_back(dest_candidate[i]);
        }
        
        // for(int i = 1; i <= N; i++){
        //     printf("%d ", min_S[i]);
        // }
        // printf("\n");
        // for(int i = 1; i <= N; i++){
        //     printf("%d ", min_G[i]);
        // }
        // printf("\n");
        // for(int i = 1; i <= N; i++){
        //     printf("%d ", min_H[i]);
        // }
        // printf("\n");

        for(auto i : answer){
            printf("%d ", i);
        }
        printf("\n");
    }

    return 0;
}
