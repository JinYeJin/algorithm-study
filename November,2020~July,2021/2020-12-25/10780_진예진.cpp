#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
    FILE *stream = freopen("S2\\26\\input\\10708.txt", "r", stdin);
    if(!stream) perror("freopen");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    int target[101];
    int score[101];

    memset(score, 0, sizeof(score));

    cin >> N >> M;

    for(int m = 1; m <= M; m++){
        cin >> target[m];
    }

    for(int m = 1; m <= M; m++){
        for(int n = 1; n <= N; n++){
            int answer;
            cin >> answer;

            // 정답 맞춤
            if(answer == target[m]) score[n]++;
            else score[target[m]]++;
        }
    }

    for(int n = 1; n <= N; n++){
        cout << score[n] << "\n";
    }

    return 0;
}
