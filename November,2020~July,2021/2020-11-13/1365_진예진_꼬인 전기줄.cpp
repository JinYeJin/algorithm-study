/*
백준 1365 https://www.acmicpc.net/problem/1365
LIS 설명 https://shoark7.github.io/programming/algorithm/3-LIS-algorithms
*/
#include <stdio.h>
#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;


int main(){
    FILE *stream =freopen("S2\\20\\input\\1365.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, num;
    vector<int> connected;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> num;

        int pos = lower_bound(connected.begin(),
                              connected.end(), num)
                              - connected.begin();

        if(pos == connected.size()) connected.push_back(num);
        else if(connected[pos] > num) connected[pos] = num;
    }

    cout << N - connected.size();

    return 0;
}
