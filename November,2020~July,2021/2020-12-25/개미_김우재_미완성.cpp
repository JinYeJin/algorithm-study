#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
    int leftNum;
    int rightNum;
    cin >> leftNum >> rightNum;

    vector<pair<char, int>> answer(leftNum+rightNum);
    
    string leftGaemi; cin>> leftGaemi;
    string rightGaemi; cin>> rightGaemi;

    reverse(leftGaemi.begin(), leftGaemi.end());
    int t; cin >> t;
    for(int i=0; i < leftNum; i++){
        answer[i] = make_pair(leftGaemi[i], 0);
    }
    
    for(int i=leftNum; i < leftNum+rightNum; i++){
        answer[i] = make_pair(rightGaemi[i-leftNum], 1);
    }
    
    
    while (t--) {
        for(int i=0; i < (leftNum+rightNum)/2+1; i++){
            if(answer[i].second != answer[i+1].second){
                pair<char, int> temp = answer[i];
                answer[i] = answer[i+1];
                answer[i+1] = temp;
            }
        }
        for(int i=0; i < (leftNum+rightNum); i++){
            cout << answer[i].first;
        }
        cout << "\n";
    }
    for(int i=0; i < (leftNum+rightNum); i++){
        cout << answer[i].first;
    }
    cout << "\n";
    
    
    
    
    
}
