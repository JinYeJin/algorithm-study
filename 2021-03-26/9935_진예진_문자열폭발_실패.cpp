/*
9935 문자열 폭발
*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main(){
    FILE *stream = freopen("C:\\Users\\yeen0\\Documents\\github\\algorithm\\S2\\36\\input\\9935.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    deque<char> dq;
    string input;
    string bomb_input;

    cin >> input >> bomb_input;

    for(int idx = 0; idx < input.length();){
        // bomb의 마지막과 같은 문자열이 있을 경우
        if(bomb_input.back() == input[idx]){
            int back_idx = 1;
            for(back_idx; back_idx < bomb_input.length(); back_idx++){
                char a = bomb_input[bomb_input.length()-back_idx-1];
                char b = input[idx - back_idx];
                if(a != b) break;
            }
            if(back_idx == bomb_input.length()){
                back_idx--;
                input.erase(idx--);
                while(back_idx--){
                    input.erase(idx--);
                    dq.pop_back();
                }
                idx++;
            }
            idx++;
        }
        else{
            dq.push_back(input[idx]);
            idx++;
        }

    }

    while(!dq.empty()){
        cout << dq.front();
        dq.pop_front();
    }


    return 0;
}
