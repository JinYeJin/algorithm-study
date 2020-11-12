/*
    백준 인강 -> 스터디때 설명 
*/
#include <iostream>
using namespace std;
int n,m,p;
long long mod = 1000000007;
long long d[101][101];
int main() {
    cin >> n >> m >> p; // nmp 입력
    d[0][0] = 1;
    for(int i=1; i <= p; i++){ // i는 길이를 의미합니다.
        for(int j=0; j <= n; j++){ // j는 x를 의미한다.
        if(j != n) d[i][j + 1] = (d[i][j + 1] + d[i - 1][j] * (n - j)) % mod;
        if(m < j) d[i][j] = (d[i][j] + d[i - 1][j] * (j - m)) % mod;
        }
    }
    cout << d[p][n] << "\n";
    
    return 0;
}
