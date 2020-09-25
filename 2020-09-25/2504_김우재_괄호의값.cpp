
int recursive(string str){
    if(str == "") return 1;
    int ans = 0;
    stack<pair<int, char>>s;
    for(int i=0; i < str.size(); i++){
        char ch = str[i];
        if(ch == '(' || ch == '['){ s.push(make_pair(i, ch));}
        else if(!s.empty() && s.top().second == '(' && ch == ')'){
            ans += 2*recursive(str.substr(s.top().first, i - s.top().first));
            s.pop();
        }
        else if(!s.empty() && s.top().second == '[' && ch == ']'){
            ans += 3*recursive(str.substr(s.top().first, i - s.top().first));
            s.pop();
        }
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
    
    cout << recursive(str) << "\n";
    
    
    return 0;
}
