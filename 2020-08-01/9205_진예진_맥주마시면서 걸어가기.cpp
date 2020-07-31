/*
[백준 9205 맥주 마시면서 걸어가기] https://www.acmicpc.net/problem/9205
*/
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <limits.h>
#define MAX_DIS 1000000

using namespace std;

typedef struct Coord{
    Coord(): x(0),y(0) {}
    Coord(int x, int y): x(x), y(y) {}
    int x, y;
}Coord;

int main(){
    FILE *stream =freopen("S2\\9\\input\\9205_input.txt", "r", stdin);
    if(!stream) perror("freopen");

    int T, N;
    int distance[102][102];
    vector<Coord> routes(100, Coord());

    scanf("%d", &T);


    for(int t = 0; t < T; t++){
        routes.clear();
        scanf("%d", &N);
        N += 2;

        // Coord home = Coord();
        // scanf("%d %d", &home.x, & home.y);

        // 가중치 배열 초기화
        // i == 0 은 상근이네, N + 1 은 페스티벌
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                // 10000 은 최대 가중치보다 큰 값
                distance[i][j] = (i == j) ? 0 : MAX_DIS;
            }
        }

        Coord temp = Coord();

        for(int i = 0; i < N; i++){
            scanf("%d %d", &temp.x, &temp.y);
            routes.push_back(temp);
        }

        // 가중치 배열 값 입력
        for(int i = 0; i < N; i++){
            for(int j = i; j < N; j++){
                int cur_distance = abs(routes[i].x - routes[j].x) + abs(routes[i].y - routes[j].y);
                // 한 번에 최대로 갈 수 있는 거리면
                if(cur_distance <= 1000){
                    // 양방향으로 연결?
                    distance[i][j] = cur_distance;
                    distance[j][i] = cur_distance;
                }
            }
        }

        // for(int i = 0; i < N; i++){
        //     for(int j = 0; j < N; j++){
        //         printf("%d ", distance[i][j]);
        //     }
        //     printf("\n");
        // }

        // printf("\n");
        

        // 플루이드 와샬

        // 편의점
        for(int k = 0; k < N; k++){
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    // 정점을 거치는 게 더 짧으면 거리가중치 변경
                    if(distance[i][j] > distance[i][k] + distance[k][j]) distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }

        // for(int i = 0; i < N; i++){
        //     for(int j = 0; j < N; j++){
        //         printf("%d ", distance[i][j]);
        //     }
        //     printf("\n");
        // }

        // 정점이 한 번이라도 갱신된 적이 있으면
        if(distance[0][N-1] != MAX_DIS){
            // printf("%d", distance[0][N+2]);
            printf("happy");
        }
        else printf("sad");

        printf("\n");
    }
    return 0;
}
