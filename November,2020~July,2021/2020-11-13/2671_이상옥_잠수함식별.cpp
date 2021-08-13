#include <iostream>
#include <vector>
#include <regex>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    string s;
    cin>>s;
    regex re("(100+1+|01)+");
    cout<<(regex_match(s, re)?"SUBMARINE":"NOISE");
    return 0;
}
