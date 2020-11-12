#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include<tuple>
#include <algorithm>
#include <stack>

using namespace std;

int n;
int used[100001]; // 횟수를 저장하는 배열

vector<int> arr;

int getIndex(int value){
    int index = 0;
    vector<int>::iterator itr;
    for(itr = arr.begin(); itr != arr.end(); itr++){
        if(*itr == value){
            break;
        } else index++;
    }
    return index;
}

int main(){
    cin >> n;
    arr.resize(n);
    
    for(int i=0; i < n; i++){
        cin >> arr[i]; // 맞춤.
    }
    
    int j = 0;
    for(int i=0; i < n/2; i++){
        int prefixValue = i+1; // 내가 찾는 값 -> 1부터 찾음
        int suffixValue = n-i; // n값 부터 찾음
        
        int prefixIndex = getIndex(prefixValue);
        while(prefixIndex > i){
            int temp = arr[prefixIndex];
            arr[prefixIndex] = arr[prefixIndex-1];
            arr[prefixIndex-1] = temp;
            used[j]++;
            prefixIndex--;
        }
        j++;
        int suffixIndex = getIndex(suffixValue);
        while(suffixIndex < n-1-i){
            int temp = arr[suffixIndex];
            arr[suffixIndex] = arr[suffixIndex+1];
            arr[suffixIndex+1] = temp;
            used[j]++;
            suffixIndex++;
        }
        j++;
    }
    
    for(int i=0; i < n ; i++){
        cout << used[i] << "\n";
    }
    
    return 0;
}

