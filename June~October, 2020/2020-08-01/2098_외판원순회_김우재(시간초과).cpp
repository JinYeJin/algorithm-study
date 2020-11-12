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
/*


#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
int n;
vector<vector<long long>> map;
vector<bool> passed;

long long check(int count, int idx, long long length){
    if(count == n) {
        return length + map[idx][0];
    }
    long long ans = 9223372036854775807L;
    for(int i=0; i < n ; i++){
        if(passed[i] == true) continue;
        passed[i] = true;
        long long val = check(count+1, i, length+map[idx][i]);
        ans = min(ans, val);
        passed[i] = false;
    }
    return ans;
}

int main(){
    cin >> n;
    map.resize(n, vector<long long>(n));
    passed.resize(n);
    
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            cin >> map[i][j];
        }
    }
    
    passed[0] = true;
    long long answer = check(1, 0, 0);
    cout << answer << "\n";
    return 0;
}

*/
