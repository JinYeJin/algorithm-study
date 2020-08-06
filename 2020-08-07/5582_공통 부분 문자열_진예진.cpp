/*
[백준 5582 공통 부분 문자열] https://www.acmicpc.net/problem/5582
*/
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

string a, b;
int len_a, len_b;
int check[4000][4000];

bool len_check(int idx_a, int idx_b){ return idx_a < len_a && idx_b < len_b; }

int find_sub_str(int index_a, int index_b, int count){
    if(len_check(index_a, index_b) == false) return count;
    // 두 문자가 다른 경우
    else if(a[index_a] != b[index_b])
        count = max(find_sub_str(index_a + 1, index_b, 0), find_sub_str(index_a, index_b + 1, 0));
    // 두 문자가 같은 경우
    else{
        while (check[index_a][index_b] == -1 && (a[index_a] == b[index_b]) && len_check(index_a, index_b)){
            count++;
            index_a++;
            index_b++;
        }
        check[index_a][index_b] = count;
    }
    return count;
}

int main(){
    FILE *stream =freopen("S2\\10\\input\\5582.txt", "r", stdin);
    if(!stream) perror("freopen");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a;
    cin >> b;

    memset(check, -1, sizeof(check));

    len_a = a.size();
    len_b = b.size();

    cout << find_sub_str(0, 0, 0);
    return 0;
}
