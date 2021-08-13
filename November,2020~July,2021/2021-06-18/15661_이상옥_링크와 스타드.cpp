#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int N, S[20][20],answer=987654321;
bool team[20]={1};
int get_sub_point(){
    int point=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(team[i]==team[j]){
                if(team[i]){
                    point+=S[i][j];
                }else{
                    point-=S[i][j];
                }
            }
        }
    }
    return abs(point);
}

void DFS(int n,int s){
    if(n==0){
        answer=min(answer,get_sub_point());
        return;
    }
    for(int i=s+1;i<N;i++){
        if(!team[i]){
            team[i]=1;
            DFS(n-1,i);
            team[i]=0;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>S[i][j];
        }
    }
    for(int n=0;n<N-1;n++){
        DFS(n,0);
    }
    cout<<answer;
    return 0;
}
