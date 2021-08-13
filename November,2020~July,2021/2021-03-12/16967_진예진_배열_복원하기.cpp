/*
16967 배열 복원하기
*/
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main(){
    FILE *stream =freopen("S2\\34\\input\\16967.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int H, W, X, Y;
    int arr[601][601];

    cin >> H >> W >> X >> Y;

    memset(arr, 0, sizeof(arr));

    for(int r = 0; r < H + X; r++){
        for(int c = 0; c < W + Y; c++){
            cin >> arr[r][c];
        }
    }

    for(int r = X; r < H + X; r++){
        for(int c = Y; c < W + Y; c++){
            arr[r][c] -= arr[r-X][c-Y];
            // cout << arr[r][c] << " " << arr[r-X][c-Y] << "\n";
        }
    }

    for(int r = 0; r < H; r++){
        for(int c = 0; c < W; c++){
            cout << arr[r][c] << " ";
        }
        cout << "\n";
    }

    return 0;
}
