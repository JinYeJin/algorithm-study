#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

int k;
long long n;
vector<int> len;

long long calcCount(long long mid){
    long long ans = 0;
    for(int i=0; i < len.size(); i++){
        ans += len[i]/mid;
    }
    return ans;
}

int main(){
    cin >> k >> n;
    
    len.resize(k);
    
    for(int i=0; i < k; i++){
        cin >> len[i];
    }
    sort(len.begin(), len.end());
    
    long long left = 1; // 최저 값
    long long right = len[k-1]; // 최대 값 -> 원래 최저값 했는데 반례 존재.
    long long ans = 0;
    while(left <= right){
        long long mid = (left + right) / 2;
        long long len = calcCount(mid);
        if(len < n){ // len 이 11보다 작다면 크게 잘랐다는 의미이다.
            right = mid-1;
        } else{ // len이 11보다 크다면 작게 잘랐다는 의미이다.
            ans = mid;
            left = mid+1;
        }
    }
    // 계산식을 만들어야 하는데
    // calc(mid) => 갯수가 나와야 함
    // 11 보다 작을 경우 자를 크기를 줄이고
    // 11 보다 클 경우 자를 크기를 높인다.
    
    cout << ans << "\n";
    
    return 0;
}
