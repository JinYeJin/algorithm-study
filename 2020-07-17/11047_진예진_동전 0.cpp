/*
2020-07-15 진예진
[백준 11047 동전 0] https://www.acmicpc.net/problem/11047
*/
#include <stdio.h>

using namespace std;

int main(){
    FILE *stream = freopen("S2\\7\\input\\11047_input.txt", "r", stdin);
    if(!stream) perror("freopen");

    int N, K, num_coins;
    int coins[10];

    scanf("%d %d",&N, &K);

    for(int i = 0; i < N; i++){
        scanf("%d", &coins[i]);
    }

    num_coins = 0;

    for(int i = N - 1; i >= 0; i--){
        num_coins += K / coins[i];
        K %= coins[i];
    }
    printf("%d", num_coins);
    return 0;
}
