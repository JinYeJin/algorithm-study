/*
*/
#include <stdio.h>
#include <stack>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    FILE *stream =freopen("S2\\15\\input\\4949.txt", "r", stdin);
    if(!stream) perror("freopen");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    stack<char> brackets;
    string temp;
    vector<char> open_bracket = {'(', '{', '['};
    vector<char> close_bracket = {')', '}', ']'};
    bool skip_char = false;
    bool skip_sen = false;

    while(true){
        skip_sen = false;
        getline(cin, temp);
        if(temp.size() == 1 && temp[0] == '.') break;

        while(!brackets.empty()) brackets.pop();

        for(int i = 0; i < temp.size(); i++){
            if(skip_sen == true) break;
            char cur = temp[i];
            skip_char = false;
            for(auto b : open_bracket){
                if(temp[i] == b){
                    brackets.push(temp[i]);
                    skip_char = true;
                    break;
                }
            }

            if(skip_char == true) continue;
            
            for(int j = 0; j < close_bracket.size(); j++){
                if(temp[i] == close_bracket[j]){
                    if(brackets.empty()){
                        cout << "no\n";
                        skip_sen = true;
                        break;
                    }
                    if(brackets.top() == open_bracket[j]){
                        brackets.pop();
                        break;
                    }
                    else{
                        cout << "no\n";
                        skip_sen = true;
                        break;
                    }
                }
            }
        }

        if(skip_sen != true){
            if(brackets.empty()) cout << "yes\n";
            else cout << "no\n"; 
        }
    }
    return 0;
}
