#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool flag=0;
int answer=0,num=1,m=0;
int mul[100];
stack<char> st;
string S;
int main(){
    cin.tie(NULL);ios::sync_with_stdio(false);
    cin>>S;
    for(int i=0;i<S.size();i++){
        if(S[i]=='('){
            st.push('(');
            mul[m++]=2;
            flag=1;
        }
        else if(S[i]=='['){
            st.push('[');
            mul[m++]=3;
            flag=1;
        }
        else if((S[i]==')' or S[i]==']') and st.empty()){
            st.push(S[i]);
            break;
        }
        else if(S[i]==')' and st.top()=='('){
            int a=2;
            st.pop();
            if(flag){
                for(int i=0;i<st.size();i++) a*=mul[i];
                answer+=a;
            }
            m--;
            flag=0;
        }
        else if(S[i]==']' and st.top()=='['){
            int a=3;
            st.pop();
            if(flag){
                for(int i=0;i<st.size();i++) a*=mul[i];
                answer+=a;
            }
            m--;
            flag=0;
        }
    }
    if(st.empty()) cout<<answer;
    else cout<<0;
    return 0;
}
