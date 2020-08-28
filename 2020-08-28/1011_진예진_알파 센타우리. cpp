/*
[백준 1011 Fly me to the Alpha Centauri] https://www.acmicpc.net/problem/1011
참고 https://itadventure.tistory.com/16#recentEntries
*/

#include <stdio.h>
#include <limits.h>

using namespace std;



int main(){
    FILE *stream =freopen("S2\\13\\input\\1011.txt", "r", stdin);
    if(!stream) perror("freopen");

    int testcase, x, y, count;

    scanf("%d", &testcase);

    for(int i = 0; i < testcase; i++){
        count = 1;
        long position = 1, pos_pow = 0;
        scanf("%d %d", &x, &y);

        long distance = y - x;

        while(position < distance){
            pos_pow++;
            count++;
            position += pos_pow;
            if(position >= distance) break;

            count++;
            position += pos_pow;
            if(position >= distance) break;
        }
        if(position > distance) count--;
        printf("%ld\n", count);
    }
    return 0;
}
