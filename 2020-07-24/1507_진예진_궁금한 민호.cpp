/*
[백준 1507 궁금한 민호] https://www.acmicpc.net/problem/1507
*/

#include <stdio.h>
#include <string.h>

using namespace std;


int main(){
    FILE *stream =freopen("S2\\8\\input\\1507_input.txt", "r", stdin);
    if(!stream) perror("freopen");

    int N, sum_of_weights = 0;
    int weights[20][20];
    int remove_check[20][20];

    memset(remove_check, false, sizeof(remove_check));

    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &weights[i][j]);
            // printf("%d ", weights[i][j]);
        }
        // printf("\n");
    }
    // printf("\n");
    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                // 출발점 도착점이 동일하거나 거처가는 점, 도착점이 동일한 경우에는 계산을 무시해줘야 답이나온다
                if(i == j || k == j || i == k) continue;
                //printf("%d %d ", weights[i][k] + weights[k][j], weights[i][j]);
                if(weights[i][k] + weights[k][j] == weights[i][j]){
                    //printf("t");
                    remove_check[i][j] = true;
                }
                // 원래 플로이드 와샬의 역을 생각, 거쳐가는 비용이 더 작으면 오류
                else if(weights[i][k] + weights[k][j] < weights[i][j]){
                    printf("-1");
                    return 0;
                }
                //printf("\n");
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            // printf("- ");
            if(!remove_check[i][j]){
                sum_of_weights += weights[i][j];
            // printf("%d ", weights[i][j]);
            }
        }
        // printf("\n");
    }

    printf("%d", sum_of_weights / 2);

    return 0;
}
