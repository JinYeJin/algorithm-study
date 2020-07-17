#include <iostream>
#include <queue>
using namespace std;

int R,C;

bool check(int r, int c){
    return (0<=r) and (r<R) and (0<=c) and (c<C);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int dc[]={1,-1,0,0}, dr[]={0,0,1,-1},r,c, c_S, c_water;
    char map[50][50];
    pair<int,int> w;
    queue<pair<int,int>> S, water;

    cin>>R>>C;
    
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin>>map[i][j];
            if(map[i][j] == 'S') S.push({i,j});
            else if(map[i][j] == '*') water.push({i,j});
        }
    }
    int cnt=0;
    while(!S.empty()){
        cnt++;
        c_water = (int)water.size();
        while(c_water--!=0){ //범람
            w = water.front();
            water.pop();
            for(int i=0; i<4; i++){
                r=w.first+dr[i];
                c=w.second+dc[i];
                if(check(r,c) and (map[r][c] == '.' or map[r][c] == 'S')){
                    map[r][c] = '*';
                    water.push({r,c});
                }
            }
        }
        c_S = (int)S.size();
        while(c_S--!=0){
            w = S.front();
            S.pop();
            for(int i=0; i<4; i++){
                r=w.first+dr[i];
                c=w.second+dc[i];
                if(check(r,c)){
                    if(map[r][c] == '.'){
                        map[r][c] = 'S';
                        S.push({r,c});
                    }
                    else if(map[r][c] == 'D'){
                        cout<<cnt<<endl;
                        return 0;
                    }
                }
            }
        }
    }
    
    cout<<"KAKTUS"<<endl;
    return 0;
}
