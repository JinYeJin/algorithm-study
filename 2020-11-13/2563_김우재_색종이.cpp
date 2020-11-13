#include <iostream>
#include <string>
#include <queue>
#include <deque>
#include <tuple>
#include <algorithm>

using namespace std;

int main(void) {
    int n; cin >> n;
    int map[101][101] = {0,};
    for(int i=0; i < n; i++){
        int x, y;
        cin >> x >> y;
        for(int j=0; j < 10; j++){
            for(int k=0; k < 10; k++){
                map[x+j][y+k]++;
            }
        }
    }
    
    int count = 0;
    for(int i=0; i < 101; i++){
        for(int j=0; j < 101; j++){
            if(map[i][j] > 0) count++;
        }
    }
    
    cout << count << "\n";
    
    
    
    
    return 0;
}




