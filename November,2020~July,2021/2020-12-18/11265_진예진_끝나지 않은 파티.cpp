/*
[백준 11265 끝나지 않는 파티]
*/

#include <stdio.h>
#include <iostream>
#define INF 987654321

using namespace std;
 
int main(){
    FILE *stream =freopen("S2\\25\\input\\11265.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    int A, B, C;
    int park[501][501];

    cin >> N >> M;
 
    // i == j 대각선은 0으로 초기화. 나머지는 INF
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            park[i][j] = (i == j) ? 0 : INF;
        }
    }

    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= N; c++) {
            cin >> park[r][c];
        }
    }
 
    // k를 거쳐서 가는 것 보다 바로 가는 게 빠른지 확인
    for(int k = 1; k <= N; k++) {
        for(int r = 1; r <= N; r++) {
            for(int c = 1; c <= N; c++) {
                if(park[r][c] > park[r][k] + park[k][c])
                    park[r][c] = park[r][k] + park[k][c];
            }
        }
    }
 
    for(int i = 0; i < M; i++) {
        // 시작, 끝, 가는 데 걸리는 시간
        cin >> A >> B >> C;

        if(park[A][B] <= C) cout << "Enjoy other party\n";
        else cout << "Stay here\n";
    }
}
