#include <iostream>
#include <algorithm>

using namespace std;

int B[600][600],H,W,X,Y;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>H>>W>>X>>Y;
    for(int i=0;i<H+X;i++){
        for(int j=0;j<W+Y;j++){
            cin>>B[i][j];
        }
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(i>=X && j>=Y){
                B[i][j]-=B[i-X][j-Y];
            }
            cout<<B[i][j]<<' ';
        }cout<<'\n';
    }
    
    return 0;
}
