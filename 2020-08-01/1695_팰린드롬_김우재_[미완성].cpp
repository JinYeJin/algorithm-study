#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int n;
vector<int> arr;
int main(){
    cin >> n;
    
    arr.resize(n);

    for(int i=0; i < arr.size(); i++){
        cin >> arr[i];
    }
    
    int left = 0;
    int right = arr.size()-1;
    int count = 0;
    
    while(left < right){
        if(arr[left] != arr[right]){
            if(arr[left] < arr[right]){
                left++;
            } else {
                right--;
            }
            count++;
        } else {
            left++;
            right--;
        }
    }
    cout << count << "\n";

    return 0;
}
