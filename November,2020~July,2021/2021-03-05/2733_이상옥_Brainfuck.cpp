#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

char cmds[7]={'<','>','+','-','.',']','['};

string run_brainfuck(string S){
    map<int,int> bra_jump;
    //check braket
    vector<int> bra_pair;
    for(int i=0;i<S.size();i++){
        if(S[i]=='['){
            bra_pair.push_back(i);
        }else if(S[i]==']'){
            if(bra_pair.empty()){
                return "COMPILE ERROR";
            }
            bra_jump[bra_pair.back()]=i;
            bra_jump[i]=bra_pair.back();
            bra_pair.pop_back();
        }
    }
    if(!bra_pair.empty()) return "COMPILE ERROR";
    
    int pointer=0;
    char arr[32768]={0};
    string result="";
    for(int i=0;i<S.size();i++){
        if(S[i]=='>'){
            pointer=(pointer+1)&32767;
        }else if(S[i]=='<'){
            pointer=(pointer-1)&32767;
        }else if(S[i]=='+'){
            arr[pointer]++;
        }else if(S[i]=='-'){
            arr[pointer]--;
        }else if(S[i]=='.'){
            result+=arr[pointer];
        }else if(S[i]=='['){
            if(arr[pointer]==0){
                i=bra_jump[i];
            }
        }else{
            if(arr[pointer]!=0){
                i=bra_jump[i];
            }
        }
    }
    return result;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    string S;
    cin>>N;
    for(int i=1;i<=N;i++){
        string parsing="";
        while(1){
            getline(cin,S);
            if(S=="end"){
                break;
            }
            for(char c:S){
                if(c=='%') break;
                if(find(cmds,cmds+7,c)!=cmds+7){
                    parsing+=c;
                }
            }
        }
        cout<<"PROGRAM #"<<i<<":\n";
        cout<<run_brainfuck(parsing)<<'\n';
    }
    return 0;
}
