#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int N,K,dx[]={0,1,-1,0,0}, dy[]={0,0,0,-1,1}, board[14][14], group_on_board[14][14], groups[10],x,y,d;
vector<pair<int,int>> members[10];
pair<int,int> members_xy[10];
int get_group(int a){
    return groups[a]==-1?a:groups[a]=get_group(groups[a]);
}
int change_dir(int d){
    return d%2?d+1:d-1;
}
vector<pair<int,int>> change_horses(vector<pair<int,int>> horses){
    int N=horses.size();
    vector<pair<int,int>> new_horses(N);
    for(int i=0;i<N;i++) new_horses[i]=horses[N-i-1];
    return new_horses;
}
int go(){
    for(int i=0;i<1000;i++){
        for(int horse=0; horse<K; horse++){
            int group=get_group(horse);

            if(horse!=members[group][0].first) continue; //맨아래에 있는지 확인.
            int &x=members_xy[group].first, &y=members_xy[group].second, &d=members[group][0].second;
            int nx=x+dx[d], ny=y+dy[d];

            if(board[ny][nx]==2){
                d=change_dir(d);
                nx=x+dx[d], ny=y+dy[d];
                if(board[ny][nx]==2)continue;
            }
            if(board[ny][nx]==1) members[group]=change_horses(members[group]);

            group_on_board[y][x]=-1;
            if(group_on_board[ny][nx]!=-1){
                int new_group=group_on_board[ny][nx];
                groups[group]=new_group;
                members[new_group].insert(members[new_group].end(), members[group].begin(), members[group].end());
            }
            else{
                members_xy[group]={nx,ny};
                group_on_board[ny][nx]=group;
            }
            x=nx, y=ny;
        }
        for(int horse=0; horse<K; horse++) if(members[get_group(horse)].size()>3) return i+1;
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    memset(groups,-1,sizeof(groups));
    memset(group_on_board,-1,sizeof(group_on_board));

    cin>>N>>K;
    for(int i=0;i<N+2;i++)
        for(int j=0;j<N+2;j++)
            board[i][j]=2;
            
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            cin>>board[i][j];
    
    for(int i=0;i<K;i++){
        cin>>y>>x>>d;
        members[i].push_back({i,d});
        members_xy[i]={x,y};
        group_on_board[y][x]=i;
    }
    cout<<go();
    return 0;
}
