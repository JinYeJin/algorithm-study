/*
2020-06-30
[백준 1475 방 번호] https://www.acmicpc.net/problem/1475
*/
#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    FILE *stream = freopen("S2\\5\\input\\1475_input.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string input_string;
    int check[9] = {0,};
    cin >> input_string;

    
    for(auto x : input_string){
        // 6과 9를 하나의 수로 간주
        if(x == '9') check[6]++;
        else check[x-'0']++;
    }

    if(check[6] != 0) check[6] = check[6] % 2 == 0 ? check[6] / 2 : check[6] / 2 + 1;

    cout << *max_element(check, check + 9);
}
