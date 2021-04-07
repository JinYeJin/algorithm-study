#include <iostream>
#include <cstring>
#include <queue>

using namespace std;


int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    
    int dps[26],M,N,P,boss_HP,di[]={1,-1,0,0},dj[]={0,0,1,-1};
    char field[1001][1001],player;
    bool visited[1001][1001]={0};

    memset(field,'X',sizeof(field));
    cin>>M>>N>>P;

    queue<pair<int,int>> Q;
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            cin>>field[i][j];
            if(field[i][j]=='B'){
                Q.push({i,j});
                visited[i][j]=1;
            }
        }
    }
    for(int i=0;i<P;i++){
        cin>>player;
        cin>>dps[player-'a'];
    }
    cin>>boss_HP;
    int sum_dps=0,answer=0;
    while(Q.size()){
        int size=Q.size();
        while(size--){
            auto [i,j]=Q.front(); Q.pop();
            for(int d=0;d<4;d++){
                int ni=i+di[d], nj=j+dj[d];
                if(field[ni][nj]!='X' && !visited[ni][nj]){
                    if(field[ni][nj]!='.'){
                        sum_dps+=dps[field[ni][nj]-'a'];
                        answer++;
                    }
                    visited[ni][nj]=1;
                    Q.push({ni,nj});
                }
            }
        }
        boss_HP-=sum_dps;
        if(boss_HP<0) break;
    }
    cout<<answer;
    return 0;
}


