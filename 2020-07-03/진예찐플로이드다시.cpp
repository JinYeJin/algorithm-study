/*
2020-06-30 진예진
[백준 11404 플로이드] https://www.acmicpc.net/problem/11404
참고 https://m.blog.naver.com/PostView.nhn?blogId=ndb796&logNo=221234427842&proxyReferer=https:%2F%2Fwww.google.com%2F
*/
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>
#define MAX_COST 10000000 // 100,000 * 100 

using namespace std;

int costs[101][101];
int dp[101][101];

int main(){
    // FILE *stream = freopen("S2\\5\\input\\11404_input.txt", "r", stdin);
    FILE *stream = freopen("S2/5/input/11404_input.txt", "r", stdin);
    if(!stream) perror("freopen");

    // a: 출발도시, b: 도착도시, c: 비용
    int N, M, a, b, c;


    // N:도시의 개수, M:버스의 개수 
    scanf("%d\n%d", &N, &M);

    // cost 값 max 로 초기화
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            // i == j 일 땐 자기 자신이므로 항상 cost가 0
            if(i == j) costs[i][j] = 0;
            else costs[i][j] = MAX_COST;
        }
    }


    for(int i = 0; i < M; i++){
        scanf("%d %d %d", &a, &b, &c);
        if(costs[a][b] > c) costs[a][b] = c;
    }

    // k: 중간 경로
    for(int k = 1; k <= N; k++){
        // j: 출발
        for(int i = 1; i <= N; i++){
            // k: 도착
            for(int j = 1; j <= N; j++){
                if(costs[i][k] + costs[k][j] < costs[i][j])
                    costs[i][j] = costs[i][k] + costs[k][j];
            }
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(costs[i][j] == MAX_COST) printf("0 ");
            else printf("%d", costs[i][j]);
        }
        printf("\n");
    }

    return 0;
}
