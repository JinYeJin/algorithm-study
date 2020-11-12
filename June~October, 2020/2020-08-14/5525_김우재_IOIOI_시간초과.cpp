#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include<tuple>
#include <algorithm>
#include <stack>

using namespace std;


int main(){
    int n;
    int size;
    string word;
    cin >> n;
    cin >> size;
    cin >> word;

    int count = 0;
    for(int i=0; i < size;i++){
        if(word[i] != 'I' || word[i+1] != 'O' || word[i+2] != 'I'){
            continue;
        }
        // 여기까지는 IOI가 맞다.
        bool ok = true;
        
        for(int j=1; j <= 2*(n-1); j+=2){
            if(word[i+2+j] != 'O' || word[i+2+j+1] != 'I'){
                ok = false;
                break;
            }
        }
        if(ok){
            count++;
            i++;
        }
    }
    cout << count << "\n";
    return 0;
}


