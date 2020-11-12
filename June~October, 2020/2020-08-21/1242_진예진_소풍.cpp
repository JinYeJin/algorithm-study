/*
[백준 1242 소풍] https://www.acmicpc.net/problem/1242
*/
#include <stdio.h>

using namespace std;

int main(){
    FILE *stream =freopen("S2\\12\\input\\1242.txt", "r", stdin);
    if(!stream) perror("freopen");

    int N, K, M;
    int left, right;
    
    // N: 사람 수, K: 퇴장하는 사람 위치, M: 동호 위치
    scanf("%d %d %d", &N, &K, &M);

    // 왼쪽, 오른쪽에 있는 숫자의 개수
    left = M - 1;
    right = N - M;

    int k = 0;
    int count = 0;

    while(true){
        count++;
        k += K;
        // 현재 삭제하는 숫자의 위치가 동호보다 작으면
        if(k > N){
            k %= N;
        }
        if(N == 1 || k == M){
            printf("%d", count);
            break;
        }
        else if(k < M){
            left--;
            N--;
            M--; // 동호 위치 이동
        }else{
            right--;
            N--;
        }
    }

    return 0;
}
