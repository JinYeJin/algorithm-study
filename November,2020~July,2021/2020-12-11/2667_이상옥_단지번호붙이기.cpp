#include <iostream>
#include <vector>
#include <algorithm>

#define check(i,j) (0<=i && i<N && 0<=j && j<N)
using namespace std;

int N, di[]={1,-1,0,0}, dj[]={0,0,1,-1};
char map[25][25],c;
vector<int> answer;

void DFS(int i,int j){
    answer.back()++;
    map[i][j]=0;
    for(int d=0;d<4;d++){
        int ni=i+di[d], nj=j+dj[d];
        if(check(ni,nj) and map[ni][nj]=='1') DFS(ni,nj);
    }
}
int main(){
    cin.tie(NULL);ios::sync_with_stdio(false);
    cin>>N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>map[i][j];
        
    

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(map[i][j]=='1'){
                answer.push_back(0);
                DFS(i,j);
            }
    cout<<answer.size()<<'\n';
    sort(answer.begin(),answer.end());
    if(answer.size()) for(int ans:answer) cout<<ans<<'\n';
}
