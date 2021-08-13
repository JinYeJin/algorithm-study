#include <iostream>

const int H=3*(1<<10),W=6*(1<<10);
using namespace std;

char answer[H][W];

void make_star(int i,int j,int size){
    if(size==3){
        for(int ni=0;ni<3;ni++)
            for(int nj=0;nj<3+ni;nj++){
                if(ni+nj>1 and !(ni==1 and nj==2)) answer[i+ni][j+nj]='*';
            }
    }
    else{
        size/=2;
        make_star(i,j+size,size);
        make_star(i+size,j,size);
        make_star(i+size,j+size*2,size);
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){//fill space
        int j=0;
        for(;j<N*2-1;j++) answer[i][j]=' ';
        answer[i][j]='\0';
    }
    make_star(0,0,N);
    for(int i=0;i<N;i++) cout<<answer[i]<<'\n';
    return 0;
}
