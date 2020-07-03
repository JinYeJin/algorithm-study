/*
2020-07-02 진예진
[백준 2011] https://www.acmicpc.net/problem/2011
*/
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    FILE *stream = freopen("S2\\5\\input\\2011_input.txt", "r", stdin);
    if(!stream) perror("freopne");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string code;
    int dp[5001];
    int temp;

    cin >> code;

    // input == 0 인 경우 예외처리
    // 아니 문제 조건에 안줬잖아...
    if(code.size() == 1 && code[0] == '0'){
        cout << "0";
        return 0;
    }

    // 한글자 넣어줌, 인덱스 맞추려고
    code = '0' + code;

    dp[0] = 1;

    // code 의 원래길이는 -1 까지
    for(int i = 1; i <= code.size()-1; i++){
        // 0인 경우에는 pass
        // i가 2부터 시작했으므로 인덱스는 i-1
        if(code[i] != '0'){
            dp[i] = (dp[i] + dp[i-1]) % 1000000;
        }
        temp = (code[i] - '0') + (code[i-1] - '0') * 10;
        // i가 1이면 i-2에서 인덱스 밖으로 벗어남
        if(i != 1 && temp >= 10 && temp <= 26){
            dp[i] = (dp[i] + dp[i-2]) % 1000000;
        }
    }

    cout << dp[code.size()-1];
    return 0;
}
