#include <iostream>
#include <algorithm>

using namespace std;


int main(){
    while(1){
        int add=0,PC=0,mem[32]={0};
        char bit;
        for(int i=0;i<32;i++){
            for(int j=7;j>=0;j--){
                cin>>bit;
                if(cin.eof()) return 0;
                if(bit=='1') mem[i]+=(1<<j);
            }
        }
        bool flag=true;
        while(flag){
            int cmd=mem[PC]>>5, x=mem[PC]&31;
            switch(cmd){
                case 0://STA x
                    mem[x]=add;
                    break;
                case 1://LDA x
                    add=mem[x];
                    break;
                case 2://BEQ x
                    if(add==0)PC=x-1;
                    break;
                case 3://NOP
                    break;
                case 4://DEC
                    add--;
                    add&=255;
                    break;
                case 5://INC
                    add++;
                    add&=255;
                    break;
                case 6://JMP x
                    PC=x-1;
                    break;
                case 7:
                    for(int i=7;i>=0;i--){
                        if(add&(1<<i))cout<<'1';
                        else cout<<'0';
                    }cout<<'\n';
                    flag=false;
                    break;
            }
            PC++;
            PC&=31;
        }
        
    }
    end:
    
    return 0;
}


