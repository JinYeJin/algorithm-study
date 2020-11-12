/*
[백준 1654 랜선 자르기] https://www.acmicpc.net/problem/1654
*/
#include <stdio.h>
#include <limits.h>
#include <algorithm>

using namespace std;

int cables[10000];

int main(){
    FILE *stream =freopen("S2\\9\\input\\1654_input.txt", "r", stdin);
    if(!stream) perror("freopen");

    int K, N;
    long long left, right;
    long long max_length = 0;
    long long max_num = 0;

    scanf("%d %d", &K, &N);

    for(int i = 0; i < K; i++){
        scanf("%d", &cables[i]);
    }

    sort(cables, cables + K);
    left = 0;
    right = INT_MAX;
    right += 1; // 이 부분 주의! 케이블 값이 INT_MAX가 들어오는 경우까지 고려해서 + 1 해주어야 함

    while(right - left > 1){
        long long mid = (left + right) / 2;
        int cut_cable = 0;

        for(int i = 0; i < K; i ++){
            cut_cable += cables[i] / mid;
        }
        
        // 케이블을 N개 만큼 만들 수 있음
        if(cut_cable >= N){
            // 현재 자른 케이블의 개수가 최대보다 크면 갱신
            if(cut_cable > max_num){
                max_length = mid;
            }
            // mid 만큼의 길이로 N개 만큼 만들 수 있다면, 케이블의 길이를 더 늘려도 됨
            left = mid;
        // 케이블이 N개만큼 안나오면 케이블의 길이를 줄여야 함
        }else{
            right = mid;
        }
    }

    printf("%lld", max_length);
    return 0;
}
