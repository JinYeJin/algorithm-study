#include <iostream>
#include <algorithm>

using namespace std;

int inning[50][9],permu[8]={1,2,3,4,5,6,7,8},N;
int answer=0,score,player,out_cnt,field;
bool run_field(int hit){
    if(hit==0){
        if(out_cnt--) return 0; //0 보다 클경우
        return 1;
    }
    field++;
    while(hit--){
        field<<=1;
        if(field & 16){
            score++;
            field-=16;
        }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) for(int j=0;j<9;j++) cin>>inning[i][j];
    do{
        score=0,player=0;
        for(int i=0;i<N;i++){
            field=0,out_cnt=2;
            while(1){
                int hitter=permu[player];
                if(player==3) hitter=0; //4번타자는 1번 선수
                else if(player>3)hitter=permu[player-1];
                player++;
                player%=9;
                if(run_field(inning[i][hitter])) break;
            }
        }
        answer=max(answer,score);
    }while(next_permutation(permu,permu+8));
    cout<<answer;
    return 0;
}
