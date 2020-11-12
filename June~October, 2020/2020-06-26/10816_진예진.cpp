/*
2020-06-25 진예진
[백준 10816 숫자 카드 2] https://www.acmicpc.net/problem/10816
참고 https://yhwan.tistory.com/10
*/

#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
 
using namespace std;
 
int lower_binary(int*arr, int target, int size) {
    int mid;
    int start = 0;
    int end = size - 1;
 
    while (end > start){
        mid = (start + end) / 2;
        if (arr[mid] >= target)
            end = mid;
        else start = mid + 1;
    }
    return end;
}
 
int upper_binary(int*arr, int target, int size) {
    int mid;
    int start = 0;
    int end = size - 1;
 
    while (end > start) {
        mid = (start + end) / 2;
        if (arr[mid] > target)
            end = mid;
        else start = mid + 1;
    }
    return end;
}
 
int main(void){
    FILE *stream = freopen("S4\\4\\input\\10816_input.txt", "r", stdin);
    if(!stream) perror("freopen");

    int N, M;
    int temp, target;
    int lower_boundary,upper_boundary;
 
    scanf("%d", &N);

    int *m_arr = new int[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &m_arr[i]);
    }

    sort(m_arr, m_arr + N);
    
    scanf("%d", &M);

    int *arr = new int[M];
    int *result = new int[M];

    for (int i = 0; i < M; i++) {
        scanf("%d", &arr[i]);
        result[i] = 0;
    }
 
    for (int i = 0; i < M; i++) {
        lower_boundary = lower_binary(m_arr, arr[i], N);
        upper_boundary = upper_binary(m_arr, arr[i], N);

        if (upper_boundary == N - 1 && m_arr[N - 1] == arr[i])
            upper_boundary++;
        // upper에서 lower을 빼면 상근이가 가진 카드가 몇개인지 알 수 있다.
        result[i] = upper_boundary - lower_boundary;
    }
 
    for (int i = 0; i < M; i++) {
        printf("%d ", result[i]);
    }
    return 0;
}
