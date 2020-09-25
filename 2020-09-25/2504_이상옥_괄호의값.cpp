#include <iostream>
#include <string>
#include <stack>
using namespace std;

int answer=0,num=1,m=0;
int mul[30];
stack<char> st;
string S;
int main(){
    cin.tie(NULL);ios::sync_with_stdio(false);
    for(int i=0;i<30;i++) mul[i]=1;
    cin>>S;
    if(S[0]==')' or S[0]==']') cout<<0;
    for(int i=0;i<S.size();i++){
        if(S[i]=='('){
            st.push('(');
            mul[m++]=1;
        }
        if(S[i]=='['){
            st.push('[');
            mul[m++]=1;
        }
        if(S[i]==')' and st.top()=='('){
            for(int i=0;i<st.size();i++){
                mul[i]*=2;
            }
            answer+=mul[--m];
            st.pop();
        }
        if(S[i]==']' and st.top()=='['){
            for(int i=0;i<st.size();i++){
                mul[i]*=3;
            }
            answer+=mul[--m];
            st.pop();
        }
    }
    if(st.empty()) printf("%d",answer);
    else puts("0");
    return 0;
}
