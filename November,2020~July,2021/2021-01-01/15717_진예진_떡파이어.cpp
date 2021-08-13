/*
[백준 15717 떡파이어]
https://onsil-thegreenhouse.github.io/programming/problem/2018/03/29/problem_math_power/
*/
#include <stdio.h>
#include <iostream> 
#define MOD 1000000007

using namespace std;

long long my_pow(long long a, long long n){
    if(n == 0) return 1;
    else{
        long long temp = my_pow(a, n/2);
        if(n%2 == 0) return (temp * temp) % MOD;
        else return (temp * temp * a) % MOD;
    }
}

int main(){
    FILE *stream =freopen("S2\\27\\input\\15717.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long age;

    cin >> age;

    if(age == 0) cout << 1;
    else if(age == 1) cout << 2;
    else cout << my_pow(2, age-1);

    return 0;
}
