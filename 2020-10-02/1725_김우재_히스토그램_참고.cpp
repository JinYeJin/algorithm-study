/*
 참고 : https://wogud6792.tistory.com/19
 */
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

int n;
vector<int> arr;
int divideAndConcurrent(int left, int right){
    if(left >= right){
        return arr[left];
    }
    
    int answer = 0;
    int mid = (left+right)/2;
    answer = max(divideAndConcurrent(left, mid), divideAndConcurrent(mid+1, right));
    
    int start = mid;
    int end = mid+1;
    int high = min(arr[start], arr[end]);
    answer = max(answer, high*2);
    while (left < start || end < right) {
        if(end < right && ((left == start) || arr[start-1] < arr[end+1])){
            end++;
            high = min(high, arr[end]);
        }
        else {
            start--;
            high = min(high, arr[start]);
        }
        answer = max(answer, high*(end-start+1));
    }
    
    /*
    for(int i=mid; i >= low; i--){
        stack<int> s;
        for(int j=mid; j <= mid; j++){
            int high = arr[i] < arr[j] ? arr[i] : arr[j];
            if(s.empty()) s.push(high);
            else if(s.top() > high) s.push(high);
            
            int width = j-i+1;
            if(answer < s.top()*width) answer = s.top()*width;
            cout << answer << " ";
        }
    }
    */
    
    return answer;
}




int main(){
    cin >> n;
    arr.resize(n);
    for(int i=0; i < arr.size(); i++){
        cin >> arr[i];
    }
    
    cout << divideAndConcurrent(0, n-1) << "\n";
    
    return 0;
}
