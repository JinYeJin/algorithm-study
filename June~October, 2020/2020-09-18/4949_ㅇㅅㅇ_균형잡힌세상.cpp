#include <stdio.h>

using namespace std;

char c,stack[1000000];
int s=0;
bool flag=false;

int main(){
    stack[0]='n';
    while(scanf("%c",&c)){
        if(c=='.'){
            if(flag) break;
            if(s) printf("no\n");
            else printf("yes\n");
            s=0;
        }
        if(c=='(' or c=='[' or c==')' or c==']')
        {
            if(c==')' && stack[s]=='(')s--;
            else if(c==']' && stack[s]=='[')s--;
            else stack[++s]=c;
        }
        if(c=='\n') flag=true;
        else flag=false;
    }
    return 0;
}
