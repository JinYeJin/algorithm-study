/*
1343 폴리오미노
*/
#include <stdio.h>
#include <iostream> 
#include <string>
#include <queue>

using namespace std;

int main(){
    FILE *stream =freopen("S2\\35\\input\\1343.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string input;
    queue<int> temp;
    int count = 0;

    cin >> input;

    for(int i = 0; i < input.size(); i++){
        if(input[i] == 'X'){
            count++;
        }
        else if(input[i] == '.'){
            temp.push(-1);
            if(count == 1){ // 이거 추가함
                cout << -1;
                return 0;
            }
        }
        if(count == 2){
            temp.push(1);
            count = 0;
        }
    }
    
    if(count == 1){
        cout << -1;
        return 0;
    }

    int iter = temp.size();

    for(int i = 0; i < iter; i++){
        int t = temp.front();
        temp.pop();

        if(t == -1){
            temp.push(count);
            count = 0;
            temp.push(-1);
        }
        else if(t == 1){
            count += t;
        }

        if(count == 2){
            temp.push(2);
            count = 0;
        }
        if(count == 1 && i == iter-1){
            temp.push(1);
        }
    }    

    iter = temp.size();

    for(int i = 0; i < iter; i++){
        int t = temp.front();
        temp.pop();

        if(t == -1) cout << ".";
        if(t == 1) cout << "BB";
        if(t == 2) cout << "AAAA";
    }

    return 0;
}
