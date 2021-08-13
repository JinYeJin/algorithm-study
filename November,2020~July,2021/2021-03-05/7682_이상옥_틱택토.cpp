#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

string board;
int check[8][3]={{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
bool is_valid(){
    bool O_f=false, X_f=false;
    int O=0,X=0;
    for(int i=0;i<8;i++){
        char f = board[check[i][0]];
        if(f=='.' || f!=board[check[i][1]] || f!=board[check[i][2]]) continue;
        if(f=='O') O_f=true;
        else X_f=true;
    }
    for(char b:board){
        if(b=='O') O++;
        else if(b=='X') X++;
    }
    return (O+X==9 && !O_f && O==4) || (!X_f && O_f && O==X) || (!O_f && X_f && O+1==X);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    while(1){
        cin>>board;
        if(board=="end") break;
        cout<<(is_valid()?"valid\n":"invalid\n");
    }
    return 0;
}
