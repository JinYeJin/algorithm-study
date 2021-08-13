#include <iostream>
#include <algorithm>

using namespace std;

bool hor[31][11]={0};
int change[31][11];
int N,M,H,a,b;


bool DFS(pair<int,int> s, int n){
    if(n==0){ //만들어야하는 선이 없을때.
        for(int j=1;j<=N;j++){
            int nj=j;
            for(int i=1;i<=H;i++){
                nj=change[i][nj];
            }
            if(nj!=j){
                return false;
            }
        }
        return true;
    }
    for(int i=s.first;i<=H;i++){
        for(int j=(i==s.first?s.second:0);j<N;j++){
            if(hor[i][j-1] || hor[i][j] || hor[i][j+1]){//좌우로 가로선이 혹은 현재꺼가 가로선일경우
                continue;
            }
            hor[i][j]=1;
            swap(change[i][j],change[i][j+1]);
            if(DFS({i,j},n-1)){ //선만들고 다음으로 넘김.
                return true;
            }
            hor[i][j]=0;
            swap(change[i][j],change[i][j+1]);
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    cin>>N>>M>>H;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=N;j++){
            change[i][j]=j;
        }
    }
    for(int i=0;i<M;i++){
        cin>>a>>b;
        hor[a][b]=1;
        swap(change[a][b],change[a][b+1]);
    }
    int answer=-1;
    for(int n=0;n<4;n++){
        if(DFS({1,1},n)){
            answer=n;
            break;
        }
    }

    cout<<answer;
    return 0;
}
