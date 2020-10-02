#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int n;
int arr[200];
int d[200];
int main() {
    cin >> n;
    for(int i=0; i < n; i++){
        cin >> arr[i];
    }
    
    for(int i=0; i < n; i++){
        d[i] = 0;
        int standard = d[i];
        for(int j=0; j < i; j++){
            if (arr[j] > standard) {
                d[i] = d[j] + 1;
                standard = d[j];
            }
        }
    }
    
    cout << d[n-1] << " ";
    
    return 0;
}
