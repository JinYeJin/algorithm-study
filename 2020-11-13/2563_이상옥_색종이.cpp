#include <iostream>
#include <vector>

using namespace std;

int N,x,y;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>N;
    int paper[100][100]={0},answer=0;
    
    for(int i=0;i<N;i++){
        cin>>x>>y;
        for(int dy=0;dy<10;dy++){
            if(y+dy>=100) break;
            for(int dx=0;dx<10;dx++){
                if(x+dx>=100) break;
                paper[y+dy][x+dx]=1;
            }
        }
    }
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            answer+=paper[i][j];
        }
    }
    cout<<answer;
    return 0;
}
