#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main() {
    vector<string> s;
    
    while (true) {
        string str;
        getline(cin, str);
        if(str == ".") break;
        stack<char> s;
        for(char ch : str){
            if(ch == '(' || ch == '[') {s.push(ch); continue;}
            else if(ch == ')' && !s.empty() && s.top()=='(') {s.pop();}
            else if(ch == ']' && !s.empty() && s.top()=='[') {s.pop();}
            else if(ch == ')' || ch == ']') s.push(ch);
        }
        s.empty() ? cout << "yes\n": cout << "no\n";
    }
    
    
    return 0;
}
