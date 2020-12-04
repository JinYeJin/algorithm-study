#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

int main(){
    FILE *stream = freopen("S2\\23\\input\\1475.txt", "r", stdin);
    if(!stream) perror("freopen");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, len;
    int count[9];
    cin >> N;

    memset(count, 0, sizeof(count));

    while(N > 0){
        int num = N % 10;
        if(num == 9) count[6]++;
        else count[num]++;
        N /= 10;
    }

    // 사용하는 번호세트 최솟값
    int answer = 1;
    if(count[6] != 0) count[6] = count[6]%2 == 0 ? count[6]/2 : count[6]/2 + 1;
    
    for(int i = 0; i < 9; i++){
        answer = answer > count[i] ? answer : count[i];
    }

    cout << answer;

    return 0;
}
