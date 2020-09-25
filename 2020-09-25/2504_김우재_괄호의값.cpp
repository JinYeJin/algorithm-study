int ans = 0;
int recursive(string str){
    if(str == ")") return 2;
    if(str == "]") return 3;
    char temp = str[0]; // 짜른 값
    string next = str.substr(1);
    if(recursive(next) == 2){
        if(temp == '(') ans += 2;
        else ans += 2*3;
    }
    if(recursive(next) == 3){
           if(temp == '[') ans += 3;
           else ans += 2*3;
    }
    return ans;
}

int main() {
    string str;
    cin >> str;
    stack<char> s;
    
    // 괄호 검사
    for (char ch : str) {
        if(ch == '(' || ch == '['){ s.push(ch);}
        else if(!s.empty() && s.top() == '(' && ch == ')'){s.pop();}
        else if(!s.empty() && s.top() == '[' && ch == ']'){s.pop();}
        else if(ch == ')' || ch == ']' ) s.push(ch);
    }
    if(!s.empty()) {cout << 0 << "\n"; return 0;}
    
    return 0;
}
