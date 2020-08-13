/*
[백준 5525 IOIOI] https://www.acmicpc.net/problem/5525
*/
#include <stdio.h>
#include <cstring>

using namespace std;

bool pattern_check[1000000];

bool ioi_check(char comp[3]){
    char mask[] = "IOI";
    bool check = true;
    for(int i = 0; i < 3; i++){
        if(mask[i] != comp[i]) check = false;
    }
    return check;
}

int main(){
    FILE *stream =freopen("S2\\11\\input\\5525.txt", "r", stdin);
    if(!stream) perror("freopen");

    int N, M;
    int combo = 0;
    int answer = 0;
    char temp_char[3] = "";

    memset(pattern_check, 0, sizeof(pattern_check));

    scanf("%d\n%d\n", &N, &M);
    scanf("%c%c", &temp_char[1], &temp_char[2]);

    for(int i = 2; i < M; i++){
        temp_char[0] = temp_char[1];
        temp_char[1] = temp_char[2];

        scanf("%c", &temp_char[2]);
        // IOI 패턴이 나타나면
       pattern_check[i] = ioi_check(temp_char);

        // 연속된 패턴이 있는 경우
        if(pattern_check[i] && pattern_check[i-2])
            combo++;
        // 새로 시작하는 패턴이 있는 경우
        else if(pattern_check[i])
            combo = 1;
        // 아무런 패턴이 없는 경우 -> 암것도 안함

        // 콤보 수가 N이 되면 맨 첫번째 패턴 빼고 두번째 패턴부터
        if(combo == N){
            answer++;
            combo--;
        }
    }

    printf("%d", answer);

    return 0;
}
