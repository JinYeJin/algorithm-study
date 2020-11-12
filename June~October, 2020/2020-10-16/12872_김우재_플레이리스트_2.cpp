#include <iostream>
#include <cstring>
using namespace std;
int n,m,p;
long long mod = 1000000007;
long long d[101][101];
long long go(int position, int x) {
    int y = n-x; // 현재 담긴 것은 없다.
    if (position == p) { // 길이가 끝까지 오면
        if (y == 0) return 1; else return 0; // y가 0이라면 1 아니라면 0 리턴 -> 경우의 수 이므로
    }
    long long &ans = d[position][x]; // 메모라이제이션
    if (ans != -1) { // 메모라이제이션
        return ans;
    }
    ans = 0; // 결과값
    if (y > 0) { // y 에 있는 노래를 넣었을 경우
        ans += go(position+1, x+1) * y; // 하나 추가시켜보기
    }
    if (x > m) { // x 에 있는 노래를 넣었을 경우
        ans += go(position+1, x) * (x-m); //
    }
    ans %= mod; // mod 로 나누기
    return ans; // 결과
}
int main() {
    cin >> n >> m >> p; // nmp 입력
    memset(d,-1,sizeof(d)); // -1로 초기화
    cout << go(0, 0) << '\n'; // 재귀
    return 0;
}
