#include <iostream>
#include <algorithm>

#define check(i,j) (0<=i && i<R && 0<=j && j<C)

using namespace std;

int R,C,di[]={1,-1,0,0},dj[]={0,0,1,-1};
char earth[10][10];
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    cin>>R>>C;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>earth[i][j];
        }
    }
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            int sea=0;
            for(int d=0;d<4;d++){
                int ni=i+di[d],nj=j+dj[d];
                if(check(ni,nj) && earth[i][j]=='.')
                    sea++;
            }
            if(sea>2)
                earth[i][j]='O';
        }
    }
    int top=0, bot=R-1, left=0, right=C-1;
    for(;;top++){
        for(int j=0;j<C;j++)
            if(earth[top][j]=='X')
                goto b;
    }
    b:
    for(;;bot--){
        for(int j=0;j<C;j++)
            if(earth[bot][j]=='X')
                goto l;
    }
    l:
    for(;;left++){
        for(int i=0;i<R;i++)
            if(earth[i][left]=='X')
                goto r;
    }
    r:
    for(;;right--){
        for(int i=0;i<R;i++)
            if(earth[i][right]=='X')
                goto e;
    }
    e:
    for(;top<=bot;top++){
        for(;left<=right;left++){
            cout<<(earth[top][left]=='X'?'X':'.');
        }
        cout<<'\n';
    }
    return 0;
}
