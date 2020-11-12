#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main() {
    // 1~6 줄
    // 1~p 프렛
    // 해당 줄에서 프렛 누르면 연주됨 -> 6*p개 있음
    // 같은 줄 프렛 5 -> 7 일 경우 5번 손가락 놔두고 새 손가락으로 7 누름
    // 같은 줄 프렛 7 -> 2 일 경우 5번이랑 7둘다 버리고 새 손가락으로 2 누름
    // 손가락으로 프렛을 한번 누르거나 떼는 것을 손가락 한 번 움직였다고 가정
    // 스택 사용이네
    
    
    int n;
    cin >> n;
    
    int p; cin >> p;
    stack<int> s[7];
    int count = 0;
    for (int i=0; i < n; i++) {
        int line, fret;
        cin >> line >> fret;
        if(s[line].empty()) {s[line].push(fret); count++; continue;}
        if(!s[line].empty() && s[line].top() == fret){continue;}
        if(!s[line].empty() && s[line].top() < fret ){s[line].push(fret); count++; continue;}
        if(!s[line].empty() && s[line].top() > fret ){
            while (!s[line].empty() && s[line].top() > fret) {
                s[line].pop();
                count++;
            }
            if(!s[line].empty() && s[line].top() == fret){continue;}
            s[line].push(fret);
            count++;
            continue;
        }
    }
    cout << count << "\n";
    
    return 0;
}
