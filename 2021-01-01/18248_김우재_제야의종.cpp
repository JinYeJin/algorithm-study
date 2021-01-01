#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    
    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    sort(arr.begin(), arr.end());
    
    for(int i=1; i < n; i++){
        for(int j=0; j < m; j++){
            if(arr[i-1][j] == 1 && arr[i][j] == 0) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    return 0;
}










