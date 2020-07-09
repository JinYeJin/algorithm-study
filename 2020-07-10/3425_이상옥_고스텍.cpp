#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

map<string,int> cmd2num;
long long temp;
vector<string> cmds;
string in;
int n, p, s[1002]={0,}, error, result;

void init(){
    string cmd[] = {"NUM", "POP","INV","DUP","SWP","ADD","SUB","MUL","DIV","MOD"};
    for(int i=0; i<10; i++)
        cmd2num[cmd[i]]=i+1;
}
string fullstack(){
    p=0;
    cin>>s[0];
    for(auto cmd:cmds){
        int c = cmd2num[cmd.substr(0,3)];
        switch(c){
            case 1: //NUM
                temp=stoi(cmd.substr(4));
                p++;
                break;
            case 2: //POP
                if(p<0) return "ERROR";
                p--;
                break;
            case 3: //INV
                if(p<0) return "ERROR";
                temp=-s[p];
                break;
            case 4: //DUP
                if(p<0) return "ERROR";
                temp=s[p];
                p++;
                break;
            case 5: //SWP
                if(p<1) return "ERROR";
                temp=s[p-1];
                s[p-1]=s[p];
                break;
            case 6: //ADD
                if(p<1) return "ERROR";
                temp=s[p-1];
                temp+=s[p];
                p--;
                break;
            case 7: //SUB
                if(p<1) return "ERROR";
                temp=s[p-1];
                temp-=s[p];
                p--;
                break;
            case 8: //MUL
                if(p<1) return "ERROR";
                temp=s[p-1];
                temp*=s[p];
                p--;
                break;
            case 9: //DIV
                if(p<1 or s[p]==0) return "ERROR";
                temp=s[p-1];
                temp/=s[p];
                p--;
                break;
            case 10: //MOD
                if(p<1 or s[p]==0) return "ERROR";
                temp=s[p-1];
                temp%=s[p];
                p--;
                break;
        }
        if(c!=2){
            if(abs(temp)>1000000000) return "ERROR";
            s[p]=((int)temp);
        }
    }
    if(p!=0) return "ERROR";
    return to_string(s[0]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    init();

    while(true){
        cmds.clear();
        getline(cin,in);
        while(in!="END"){
            if(in=="QUIT") return 0;
            if(cmd2num[in.substr(0,3)]!=0)
                cmds.push_back(in);
            getline(cin,in);
        }
        cin>>n;
        for(int i=0;i<n;i++){
            cout<<fullstack()<<endl;
        }
        cout<<endl;
    }
    return 0;
}
