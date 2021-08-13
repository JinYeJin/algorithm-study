#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
    string a;
    string b;
    cin >> a >> b;
    // 브르투 포스 방식 2^26까지 감 -> 안됨
    int minValue = b.length();
    for(int i=0; i <= b.size()-a.size(); i++){
        int count = 0;
        for(int j=0; j < a.length(); j++){
            if(a[j] != b[j+i]) count++;
        }
        minValue = min(minValue, count);
    }
    
    cout << minValue << "\n";
    
    
    
    
    
    return 0;
}
