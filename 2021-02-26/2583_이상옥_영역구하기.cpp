#include <iostream>
#include <algorithm>
#include <vector>

#define check(i,j) (0<=i && i<M && 0<=j && j<N)

using namespace std;
int M,N,K,di[]={1,-1,0,0},dj[]={0,0,1,-1};
vector<int> answer;
pair<pair<int,int>,pair<int,int>> rects[100];
bool visited[100][100]={0};

bool in_rect(int x,int y){
    for(int k=0;k<K;k++){
        if(rects[k].first.first<=x && x<rects[k].second.first && rects[k].first.second<=y && y<rects[k].second.second){
            return true;
        }
    }
    return false;
}
int DFS(int i,int j){
    if(!check(i,j) || visited[i][j]) return 0;
    visited[i][j]=1;
    if(!in_rect(j,i)){
        return 1+DFS(i+1,j)+DFS(i-1,j)+DFS(i,j+1)+DFS(i,j-1);
    }
    return 0;
}
int main(){
    ios::sync_with_stdio();cin.tie();
    cin>>M>>N>>K;
    for(int i=0;i<K;i++){
        cin>>rects[i].first.first>>rects[i].first.second>>rects[i].second.first>>rects[i].second.second;
    }
    
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(!visited[i][j]){
                if(!in_rect(j,i)){
                    answer.push_back(DFS(i,j));
                }
                visited[i][j]=1;
            }
        }
    }
    sort(answer.begin(),answer.end());
    cout<<answer.size()<<'\n';
    for(int ans:answer){
        cout<<ans<<' ';
    }
    return 0;
}
