#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <tuple>
#include <queue>

using namespace std;

// 빌딩갯수, 레프트, 라이트
long long d[101][101][101];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l, r;
    cin >> n >> l >> r;

    d[1][1][1] = 1; // 빌딩이 1개이고, 왼쪽 오른쪽은 다 보인다 // 1
    
    d[2][2][1] = 1; // 12
    d[2][1][2] = 1; // 21
        
    for(int i=2; i <= n; i++){
        for(int j=1; j <= i; j++){
            for(int k=1; k <= i; k++){
                if((i == j && k != 1) || (i == k && j != 1)) continue;
                d[i][j][k] = (d[i-1][j-1][k] + d[i-1][j][k-1] + d[i-1][j][k] * (i-2)) % 1000000007;
            }
        }
    }
    
    cout << d[n][l][r] << "\n";
    
    return 0;
}


