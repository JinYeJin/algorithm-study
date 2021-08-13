#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;


int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    
    string s,answer="";
    cin>>s;
    int cnt=0;
    for(char c : s){
        if(c=='X'){
            cnt++;
        }else{
            if(cnt%2!=0){
                cout<<-1;
                return 0;
            }
            else{
                answer+=string(4*(cnt/4),'A');
                answer+=string((cnt%4),'B');
            }
            cnt=0;
            answer+='.';
        }
    }
    if(cnt%2!=0){
        cout<<-1;
        return 0;
    }
    else{
        answer+=string(4*(cnt/4),'A');
        answer+=string((cnt%4),'B');
    }
    cout<<answer;
    return 0;
}
