/*
[백준 1956 운동] https://www.acmicpc.net/problem/1956
*/

#include <stdio.h>
#define INF 987654321

using namespace std;
 
int road[401][401]; 
int V, E;
int a, b, c;
int min_value = INF;

int main(){
    FILE *stream =freopen("S2\\16\\input\\1956.txt", "r", stdin);
    if(!stream) perror("freopen");

    scanf("%d %d", &V, &E);

	// 배열 초기화

	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (i == j) road[i][j] = 0;
			else road[i][j] = INF;
		}
	}
 
	for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &a, &b, &c);
		road[a][b] = c;
	}
 
	// 플루이드 와샬
 
	for (int k = 1; k <= V; k++){ 
		for (int i = 1; i <= V; i++){
			for (int j = 1; j <= V; j++){
				if (road[i][k] + road[k][j] < road[i][j]){
					road[i][j] = road[i][k] + road[k][j];
				}
			}
		}
	}
 
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (i == j) {
				continue;
			}
			else {
				if (road[i][j] + road[j][i] < min_value) {
					min_value = road[i][j] + road[j][i];
				}
			}
		}
	}

	if (min_value == INF) printf("-1");
	else printf("%d", min_value);

    return 0;
}
