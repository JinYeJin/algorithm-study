#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
int n;

int main(){
    cin >> n;
    vector<int> island(n);
    vector<vector<long long>> map (n, vector<long long>(n));
    
    for(int i=0; i < n; i++){
        island[i] = i;
    }
    
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            cin >> map[i][j];
        }
    }
    
    long long ans = 9999;
    do {
        long long tempResult = 0;
        int start = 0;
        for(int i=0; i < n; i++){
            tempResult += map[start][island[i]];
            start = island[i];
        }
        tempResult += map[start][0];
        
        if(ans > tempResult){
            ans = tempResult;
        }
    } while (next_permutation(island.begin(), island.end()));
    cout << ans << "\n";
    return 0;
}
// 문제 : 16 팩토리얼이 나오기에 시간이 오바되는건 당연**

