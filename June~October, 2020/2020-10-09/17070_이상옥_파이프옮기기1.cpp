#include <iostream>

using namespace std;

int N;
int map[16][16],dp_hor[16][16]={0},dp_ver[16][16]={0},dp_dia[16][16]={0};
int main(){
    cin.tie(NULL);ios::sync_with_stdio(false);
    cin>>N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>map[i][j];

    dp_hor[0][1]=1;
    for(int i=1;i<N;i++) if(map[0][i]==0) dp_hor[0][i]+=dp_hor[0][i-1];

    for(int i=1;i<N;i++)
        for(int j=1;j<N;j++)
            if(map[i][j]==0){
                dp_hor[i][j]+= dp_hor[i][j-1]+dp_dia[i][j-1];
                dp_ver[i][j]+= dp_ver[i-1][j]+dp_dia[i-1][j];
                if(map[i-1][j]==0 and map[i][j-1]==0) dp_dia[i][j]+=dp_hor[i-1][j-1]+dp_ver[i-1][j-1]+dp_dia[i-1][j-1];
            }

    cout<<dp_dia[N-1][N-1]+dp_hor[N-1][N-1]+dp_ver[N-1][N-1];
    return 0;
}
