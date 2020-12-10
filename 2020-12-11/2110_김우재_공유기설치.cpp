#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, c;
long long answer = -1;
vector<long long> house;
bool go(long long mid) {
    int beforeIndex = 0;
    int count = 1;
    for(int i=1; i < n; i++) {
        if(house[i] - house[beforeIndex] >= mid){ // 간격이 중간 값보다 크면
            beforeIndex = i; // 해당 칸은 설치, 기록
            count++; // 갯수 카운트
        }
    }
    if(count >= c) { // 갯수 만큼 설치
        answer = max(answer, mid); // 중간 값이 최소 거리를 의미
        return true;
    }
    
    return false;
}

int main() {
    cin >> n >> c;
    house.resize(n);
    for(int i=0; i < n; i++) {
        cin >> house[i];
    }
    sort(house.begin(), house.end());
    
    long long start = 1; // 여기가 문제였음 == 사이 값은 첫값이 아닌 1부터 시작
    long long end = house[n-1]; // 맨 뒷 값
        
    while (start <= end) {
        long long mid = (start+end)/2; // 중간 값
        if(go(mid)) {
            start = mid+1; // true면 성립했다는 뜻으로 더 크게 키워봄
        } else {
            end = mid-1; // false면 성립하지 못했다는 뜻으로 작게해서 카운트 늘림
        }
    }
    cout << answer << "\n";
    
    return 0;
}





