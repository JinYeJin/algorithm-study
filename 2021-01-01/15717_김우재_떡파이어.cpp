#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>

using namespace std;
// 참고: https://travelbeeee.tistory.com/117

int main() {
    long long n; cin >> n;
    long long answer = 1, a=2;
    if(n <= 1) {
        cout << 1 <<"\n";
        return 0;
    }
    n -=1;
    while (n) {
        if(n & 1){
            answer *= a;
            answer %= 1000000007;
        }
        n/=2;
        a*=a;
        a %= 1000000007;
    }
    cout << answer << "\n";
}
