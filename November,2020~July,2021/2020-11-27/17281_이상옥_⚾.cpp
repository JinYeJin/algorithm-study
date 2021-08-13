#include <iostream>
#include <algorithm>

using namespace std;

int inning[50][9],permu[9]={1,2,3,4,5,6,7,8,0},N;
int answer=0,score,player,out_cnt,field,hitter;
void run_field(int hit){
    if(hit==0){
        out_cnt--;
        return;
    }
    field+=16;
    while(hit--){
        field>>=1;
        if(field&1) score++;
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) for(int j=0;j<9;j++) cin>>inning[i][j];
    do{
        score=0,player=5;
        for(int i=0;i<N;i++){
            field=0,out_cnt=3;
            while(out_cnt){
                hitter=permu[player++];
                player%=9;
                run_field(inning[i][hitter]);
            }
        }
        answer=max(answer,score);
    }while(next_permutation(permu,permu+8));
    cout<<answer;
    return 0;
}
