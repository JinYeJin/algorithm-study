#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main(){
    int t; // 테스트 케이스.
    cin >> t; // 테스트 케이스 입력.
    
    while(t--){
        int n; // 편의점 갯수.
        int now_x, now_y; // 현재 위치를 위한 변수
        int end_x, end_y; // 마지막 위치를 위한 변수.
        bool ok = false; // 도중에 불가능하면 바로 false 로 끝난걸로 테스트.
        vector<pair<int, int>> conveniences; // 편의점 위치를 저장하기 위한 동적 배열.

        cin >> n; // 편의점 갯수 입력.
        cin >> now_x >> now_y; // 시작 지점 초기화.
        
        for(int i=0 ; i < n; i++){ // 편의점 초기화를 위한 반복문.
            int con_x, con_y; // 편의점 위치
            cin >> con_x >> con_y; // 편의점 위치 입력
            conveniences.push_back(make_pair(con_x, con_y)); // 순서대로 입력.
        }
        
        sort(conveniences.begin(), conveniences.end()); // x 기준으로 정렬 진행.
        
        cin >> end_x >> end_y; // 마지막 도착점 입력.
        
        conveniences.push_back(make_pair(end_x, end_y)); // 편의를 위해서 배열에도 넣어줌
        
        for(int j=0; j < n+1; j++){ // 0부터 n까지 반복. -> end 를 넣어줬기 때문에 +1
           if((abs(abs(now_x) - abs(end_x)) + abs(abs(now_y) - abs(end_y))) <= 1000){
               ok = true;
               break;
           }
            
            int next_x = conveniences[j].first; // 다음 x 위치
            int next_y = conveniences[j].second; // 다음 y 위치.
    
            if((abs(abs(next_x) - abs(now_x)) + abs(abs(next_y)-abs(now_y))) > 1000){
                ok = false;
                break;
            }
            
            now_x = next_x;
            now_y = next_y;
            
        }
        if(ok) cout << "happy" << "\n";
        else cout << "sad" << "\n";
    }
    
    return 0;
}
