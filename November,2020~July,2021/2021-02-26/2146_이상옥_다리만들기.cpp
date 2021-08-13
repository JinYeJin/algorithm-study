#include <iostream>
#include <algorithm>
#include <queue>

#define check(i,j) (0<=i && i<N && 0<=j && j<N)
using namespace std;

int N, di[]={1,-1,0,0}, dj[]={0,0,1,-1}, land_name=2;
int island[100][100];
bool visited[100][100]={0};
vector<queue<pair<int,int>>> bridges(2);

void BFS(int i, int j){
    queue<pair<int,int>> island_q;
    queue<pair<int,int>> bridge_q;
    island_q.push({i,j});
    while(island_q.size()){
        auto q= island_q.front(); island_q.pop();
        int i=q.first, j=q.second;
        for(int d=0;d<4;d++){
            int ni=i+di[d], nj=j+dj[d];
            if(check(ni,nj) && !visited[ni][nj]){
                visited[ni][nj]=1;
                if(island[ni][nj]){
                    island[ni][nj]=land_name;
                    island_q.push({ni,nj});
                }else{
                    bridge_q.push({ni,nj});
                }
            }
        }
    }
    bridges.push_back(bridge_q);
    land_name++;
}
int bridge_num(int name){
    auto Q = bridges[name];
    bool visited[100][100]={0};
    int bridge=1;
    while(Q.size()){
        auto size=Q.size();
        while(size--){
            auto q=Q.front();Q.pop();
            int i=q.first, j=q.second;
            if(visited[i][j]) continue;
            visited[i][j]=1;
            for(int d=0;d<4;d++){
                int ni=i+di[d], nj=j+dj[d];
                if(check(ni,nj) && !visited[ni][nj]){
                    if(island[ni][nj]==0){
                        Q.push({ni,nj});
                    }else if(island[ni][nj]!=name){
                        return bridge;
                    }
                }
            }
        }
        bridge++;
//        cout<<endl;
//        for(int i=0;i<N;i++){
//            for(int j=0;j<N;j++){
//                cout<<visited[i][j]<<' ';
//            }cout<<endl;
//        }
    }
    return bridge;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>island[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!visited[i][j] && island[i][j]){
                visited[i][j]=1;
                island[i][j]=land_name;
                BFS(i,j);
            }
        }
    }
    
    int answer=1000000000;
    for(int name=2; name<land_name; name++){
        answer=min(answer,bridge_num(name));
    }
//    for(int i=0;i<N;i++){
//        for(int j=0;j<N;j++){
//            cout<<island[i][j]<<' ';
//        }cout<<'\n';
//    }
    cout<<answer;
    return 0;
}
