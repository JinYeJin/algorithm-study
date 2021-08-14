#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    string a, b;
    int answer=0;
    getline(cin,a);
    getline(cin,b);
    
    regex re(b);
    smatch m;
    
    while(regex_search(a,m,re)){
        answer++;
        a=m.suffix().str();
    }
    cout<<answer;
    
    return 0;
}
