#include <stdio.h>
#include <string>

using namespace std;

int puzzle[4][4], answer[4][4];

void reset(){
    for(int i=0; i<16; i++)
        answer[i/4][i%4]=i+1;
}
string make_str(){
    string str="";
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            str+=to_string(answer[i][j])+" ";
    return str;
}
int check(){
    int cnt=0;
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            if(puzzle[i][j]==answer[i][j]) cnt++;
    return cnt;
}
void move(int rc, int i){
    int temp;
    if(rc==2){
        temp=answer[0][i-1];
        for(int j=0; j<3; j++)
            answer[j][i-1]=answer[j+1][i-1];
        answer[3][i-1]=temp;
    }
    else{
        temp=answer[i-1][0];
        for(int j=0; j<3; j++)
            answer[i-1][j]=answer[i-1][j+1];
        answer[i-1][3]=temp;
    }
}
bool DFS(int N, int N_cnt, int lines){
    int c=check();
    if(c==16){
        printf("%d\n", N_cnt);
        return true;
    }
    if(N==N_cnt) return false;
    if(N-N_cnt==1 and c!=12) return false; //맞는 갯수 12
    if(N-N_cnt==2 and c<8 and c>9) return false; //맞는 갯수 8~9
    if(N-N_cnt==3 and c<4 and c>6) return false; //맞는 갯수 4~6
    int line=0;
    for(int a=1;a<5;a++){
        for(int m=1; m<4; m++){
            move(1, a);
            if((lines>>line)%2 and DFS(N, N_cnt+1, 255-(1<<line))){
                printf("%d %d %d\n",1, a, m);
                return true;
            }
        }
        line++;
        move(1,a);
        for(int m=1; m<4; m++){
            move(2, a);
            if((lines>>line)%2 and DFS(N, N_cnt+1, 255-(1<<line))){
                printf("%d %d %d\n",2, a, m);
                return true;
            }
        }
        line++;
        move(2,a);
    }
    return false;
}
int main(){
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            scanf("%d",puzzle[i]+j);
    for(int i=1; i<9; i++){
        reset();
        if(DFS(i,0, 255)) return 0;
    }
    return 0;
}

