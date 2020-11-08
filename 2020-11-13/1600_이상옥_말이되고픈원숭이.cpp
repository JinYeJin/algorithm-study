#include <iostream>
#include <queue>

#define check(i,j) (0<=i and i<H and 0<=j and j<W)
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    bool board[200][200]={0}, visited[200][200][31]={0};
    int K,W,H,di[]={1,-1,0,0}, dj[]={0,0,1,-1}, dhi[]={2,2,-2,-2,1,-1,1,-1}, dhj[]={1,-1,1,-1,2,2,-2,-2};
    cin>>K>>W>>H;
    for(int i=0;i<H;i++)
        for(int j=0;j<W;j++)
            cin>>board[i][j];
    queue<pair<pair<int,int>,pair<int,int>>> Q;
    Q.push({{0,K},{0,0}});
    while(Q.size()){
        auto q=Q.front(); Q.pop();
        int cnt=q.first.first, k=q.first.second, i=q.second.first, j=q.second.second;
        if(visited[i][j][k]) continue;
        visited[i][j][k]=1;
        if(i==H-1 and j==W-1){
            cout<<cnt;
            return 0;
        }
        cnt++;
        for(int d=0;d<4;d++){
            int ni=i+di[d], nj=j+dj[d];
            if(check(ni,nj) and !board[ni][nj]) Q.push({{cnt, k},{ni,nj}});
        }
        k--;
        if(k<0) continue;
        for(int d=0;d<8;d++){
            int ni=i+dhi[d], nj=j+dhj[d];
            if(check(ni,nj) and !board[ni][nj]) Q.push({{cnt, k},{ni,nj}});
        }
    }
    cout<<-1;
    return 0;
}
