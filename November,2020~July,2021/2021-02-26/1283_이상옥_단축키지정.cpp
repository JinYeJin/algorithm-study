#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    string s;
    int N;
    bool simple_key[26]={0};
    cin>>N;
    getline(cin,s);
    for(;N--;){
        getline(cin,s);
        vector<int> head,tail;
        int key=100;
        bool h=true;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                h=true;
            }
            else if(h){
                head.push_back(i);
                h=false;
            }else{
                tail.push_back(i);
            }
        }
        for(int h:head){
            if(!simple_key[tolower(s[h])-'a']){ //단축키가 없다면
                simple_key[tolower(s[h])-'a']=1;
                key=h;
                break;
            }
        }
        if(key==100){
            for(int t:tail){
                if(!simple_key[tolower(s[t])-'a']){ //단축키가 없다면
                    simple_key[tolower(s[t])-'a']=1;
                    key=t;
                    break;
                }
            }
        }
        
        for(int i=0;i<s.size();i++){
            if(i==key) cout<<'['<<s[i]<<']';
            else cout<<s[i];
        }
        cout<<'\n';
    }
    
    return 0;
}
