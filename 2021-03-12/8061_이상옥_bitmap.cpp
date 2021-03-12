#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

#define check(i,j) (0<=i && i<n && 0<=j && j<m)
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    vector<string> pixel;
    int answer[183][183], di[]={1,-1,0,0}, dj[]={0,0,1,-1};
    string s;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s;
        pixel.push_back(s);
    }
    memset(answer,-1,sizeof(answer));
    queue<pair<int,pair<int,int>>>  Q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(pixel[i][j]=='1'){
                Q.push({0,{i,j}});
            }
        }
    }
    while(Q.size()){
        auto q=Q.front(); Q.pop();
        int cnt=q.first, i=q.second.first, j=q.second.second;
        if(answer[i][j]!=-1) continue;
        answer[i][j]=cnt;
        
        cnt++;
        for(int d=0;d<4;d++){
            int ni=i+di[d], nj=j+dj[d];
            if(check(ni,nj) && answer[ni][nj]==-1){
                Q.push({cnt,{ni,nj}});
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<answer[i][j]<<' ';
        }cout<<'\n';
    }
    return 0;
}
