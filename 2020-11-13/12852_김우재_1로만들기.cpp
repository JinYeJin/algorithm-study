#include <iostream>
#include <string>
#include <queue>
using namespace std;

int d[1000001];
int pre[1000001];
int main(void) {
    int n; cin >> n;
    d[1] = 0;
    pre[1] = -1;
    for(int i=2; i < 1000001; i++){
        d[i] = d[i-1]+1;
        pre[i] = i-1;
        if(i % 2 == 0 && d[i] > d[i/2]+1) {
            d[i] = d[i/2]+1;
            pre[i] = i/2;
        }
        if(i % 3 == 0 && d[i] > d[i/3]+1) {
            d[i] = d[i/3]+1;
            pre[i] = i/3;
        }
    }
    cout << d[n] << "\n"; // 최소 갯수가 들어감
    int trace = n;
    while (trace != -1) { // 현재 값부터 시작
        cout << trace << " ";
        trace = pre[trace]; // 이전값 trace에 입력
    }
    return 0;
}

