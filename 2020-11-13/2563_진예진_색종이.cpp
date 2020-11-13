#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
    FILE *stream = freopen("S2/20/input/2563.txt", "r", stdin);
    if(!stream) perror("open error");

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, x, y;
    bool paper[110][110];
    memset(paper, false, sizeof(paper));

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> x >> y;

        for(int j = y; j < y+10; j++){
            for(int k = x; k < x+10; k++){
                paper[j][k] = true;
            }
        }
    }

    int answer = 0;

    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            // printf("%d ", paper[i][j]? 1 : 0);
            if(paper[i][j] == true) answer++;
        }
        printf("\n");
    }

    cout << answer;

    return 0;
}
