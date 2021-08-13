#include <iostream>
#include <algorithm>

using namespace std;

int ingu[21][21],N,answer=1e9;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>ingu[i][j];
        }
    }
    //O(n^6) = 64000000, 100000000 = 1초
    for(int x=1;x<=N;x++){
        for(int y=1;y<=N;y++){
            for(int d1=1;d1<=N;d1++){
                for(int d2=1;d2<=N;d2++){
                    if(x+d1+d2>N || y-d1<1 || y+d2>N) continue;
                    int line[21][21]={0};
                    
                    for(int nx=x, ny=y; nx<=x+d1; nx++,ny--){
                        line[nx][ny]=5;
                        line[nx+d2][ny+d2]=5;
                    }
                    for(int nx=x, ny=y; nx<=x+d2; nx++,ny++){
                        line[nx][ny]=5;
                        line[nx+d1][ny-d1]=5;
                    }
                    
                    //1번 선거구.
                    for(int r=1;r<x+d1;r++){
                        for(int c=1;c<=y;c++){
                            if(line[r][c]==5) break;
                            line[r][c]=1;
                        }
                    }
                    //2번 선거구.
                    for(int r=1;r<=x+d2;r++){
                        for(int c=N;c>y;c--){
                            if(line[r][c]==5) break;
                            line[r][c]=2;
                        }
                    }
                    //3번 선거구.
                    for(int r=x+d1;r<=N;r++){
                        for(int c=1;c<y-d1+d2;c++){
                            if(line[r][c]==5) break;
                            line[r][c]=3;
                        }
                    }
                    //4번 선거구.
                    for(int r=x+d2+1;r<=N;r++){
                        for(int c=N;c>=y-d1+d2;c--){
                            if(line[r][c]==5) break;
                            line[r][c]=4;
                        }
                    }
                    
                    int gu[6]={0},min_gu=1e9,max_gu=0;
                    for(int i=1;i<=N;i++){
                        for(int j=1;j<=N;j++){
                            if(line[i][j]==0) gu[5]+=ingu[i][j];
                            else gu[line[i][j]]+=ingu[i][j];
                        }
                    }
                    for(int i=1;i<6;i++){
                        min_gu=min(min_gu,gu[i]);
                        max_gu=max(max_gu,gu[i]);
                    }
                    answer=min(answer,max_gu-min_gu);
//                    cout<<x<<' '<<y<<' '<<d1<<' '<<d2<<'\n';
//                    for(int i=1;i<=N;i++){
//                        for(int j=1;j<=N;j++){
//                            cout<<line[i][j]<<' ';
//                        }cout<<'\n';
//                    }
                }
            }
        }
    }
    
    cout<<answer;
    return 0;
}
