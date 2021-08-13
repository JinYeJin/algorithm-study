#include <iostream>
#include <algorithm>
#include <string>

#define crashes_wall(x,y) (x<1 or A<x or y<1 or B<y)

using namespace std;
char num_dir[]={'N','E','S','W'},dir;
int N,M,A,B,x,y,board[101][101]={0},d,dx[]={0,1,0,-1},dy[]={1,0,-1,0},nx,ny;
int cmds=0;

pair<pair<int,int>,int> robots[101];

string exe_cmd(){
    int robot, loop;
    char kind;
    for(;cmds<M;cmds++){
        cin>>robot>>kind>>loop;
        int &x=robots[robot].first.first, &y=robots[robot].first.second, &d=robots[robot].second;
        if(kind=='F'){
            for(;loop--;){
                nx=x+dx[d], ny=y+dy[d];
                if(crashes_wall(nx,ny))
                    return "Robot "+to_string(robot)+" crashes into the wall";
                if(board[ny][nx]>0)
                    return "Robot "+to_string(robot)+" crashes into robot "+to_string(board[ny][nx]);
                board[y][x]=0;
                x=nx,y=ny;
                board[y][x]=robot;
            }
        }
        else{
            if(kind=='R') d=(d+loop)%4;
            else d=(d+loop*3)%4;
        }
    }
    return "OK";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>A>>B;
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        cin>>x>>y>>dir;
        d=find(num_dir,num_dir+4,dir)-num_dir;
        robots[i]={{x,y},d};
        board[y][x]=i;
    }
    cout<<exe_cmd();
    return 0;
}
