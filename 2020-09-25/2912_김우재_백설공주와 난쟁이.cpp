#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

#define INF 1000000
using namespace std;

int main() {
    int n; // 난쟁이의 수
    int c; // 모자 색상의 수
    cin >> n >> c;
    
    vector<int> arr(n+1);
    for(int i=1; i <= n; i++){
        cin >> arr[i];
    }
    /*
    for(int i=1; i <= n; i++){
        cout << arr[i] << " ";
    }
    */
    int t;
    cin >> t;
        
    while(t--){
        vector<int> hat(c, 0);
        int start, end;
        bool ok = false;
        cin >> start >> end;
        if(start == end) {cout << "yes " << arr[start] << "\n"; continue;}
        for(int i=start; i <= end; i++){
            hat[arr[i]]++; // 모자 값이 증가
            if(hat[arr[i]] > (end-start+1)/2){ok = true; cout << "yes " << arr[i] << "\n"; break;}
        }
        
        if(ok == false) cout << "no" << "\n";
    }
    
    
    return 0;
}
