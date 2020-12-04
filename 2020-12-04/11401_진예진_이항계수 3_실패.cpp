/*
[백준 11401] https://www.acmicpc.net/problem/11401
*/
#include <stdio.h>
#include <iostream> 
#define MOD 1000000007

using namespace std;

long long facto(long long n){
    if(n <= 1) return 1;
    return n * facto(n-1);
}

int main(){
    FILE *stream =freopen("S2\\23\\input\\11401.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long N, K;

    cin >> N >> K;

    cout << (facto(N) / (facto(K) * facto(N-K))) % MOD;

    return 0;
}
