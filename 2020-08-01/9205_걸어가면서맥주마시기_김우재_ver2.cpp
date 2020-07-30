#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <queue>

using namespace std;

bool check(int now_x, int now_y , int next_x, int next_y){
    if(abs(abs(next_x) - abs(now_x)) + abs(abs(next_y)-abs(now_y)) <= 1000) return true;
    else return false;
}


int n;
int main(){
    int t; // 테스트 케이스.
    cin >> t; // 테스트 케이스 입력.
    while(t--){
        int now_x, now_y;
        int end_x, end_y;
        queue<pair<int, int>> q;
        vector<pair<int, int>> conv;
        
        cin >> n;
        cin >> now_x >> now_y;
        
        conv.resize(n);
         
        for(int i=0; i < n; i++){
            int temp_x, temp_y;
            cin >> temp_x >> temp_y;
            conv[i] = make_pair(temp_x, temp_y);
        }
        
        cin >> end_x >> end_y;
        
        if(check(now_x, now_y, end_x, end_y)){
            cout << "happy" << "\n";
            continue;
        }
        
        sort(conv.begin(), conv.end());
        
        for(int i=0; i < conv.size(); i++){
            int vec_x, vec_y;
            vec_x = conv[i].first;
            vec_y = conv[i].second;
            q.push(make_pair(vec_x, vec_y));
        }
        
        bool ok = false;
        
        while(!q.empty()){
            int next_x = q.front().first;
            int next_y = q.front().second;
            q.pop();
            if(!check(now_x, now_y, next_x, next_y)){
                ok = false;
                break;
            }
            
            now_x = next_x;
            now_y = next_y;
            
            if(check(now_x, now_y, end_x, end_y)){
                ok = true;
                break;
            }
        }
        if(ok) cout << "happy" << "\n";
        else cout << "sad" << "\n";
        
    }
    return 0;
}

