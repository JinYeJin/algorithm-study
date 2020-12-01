#include <iostream>
#include <algorithm>

#define check(i,j) (0<=i and i<R and 0<=j and j<C)
using namespace std;

int R,C,di[]={1,-1,0,0}, dj[]={0,0,1,-1};
char farm[500][500];

int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    cin>>R>>C;
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            cin>>farm[i][j];
    
    bool answer=1;
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            if(farm[i][j]=='W')
                for(int d=0;d<4;d++){
                    int ni=i+di[d], nj=j+dj[d];
                    if(check(ni,nj)){
                        if(farm[ni][nj]=='.') farm[ni][nj]='D';
                        else if(farm[ni][nj]=='S') answer=0;
                    }
                }
    cout<<answer<<'\n';
    if(answer){
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++) cout<<farm[i][j];cout<<'\n';
        }
    }
    return 0;
}
