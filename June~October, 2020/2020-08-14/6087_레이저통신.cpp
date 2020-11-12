#include <stdio.h>
#include <queue>

using namespace std;

int W, H,answer=0, dw[]={1,-1,0,0}, dh[]={0,0,1,-1} , w,h, size;
char temp, map[102][102]={0,};

int main(){
    queue<pair<int, int>> q;
    scanf("%d%d\n",&W, &H);
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            scanf("%c",&temp);
            map[i][j] = temp;
            if(temp == 'C') q.push({i,j});
        }scanf("%c",&temp);
    }
    map[q.front().first][q.front().second]='E';
    q.pop();
    while(!q.empty()){
        size = (int)q.size();
        while(size--!=0){
            auto point = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                h=point.first;
                w=point.second;
                while(true){
                    h+=dh[i];
                    w+=dw[i];
                    if(map[h][w]=='*' or map[h][w]==0) break;
                    if(map[h][w]=='E'){
                        printf("%d",answer);
                        return 0;
                    }
                    if(map[h][w]=='.'){
                        map[h][w]='C';
                        q.push({h,w});
                    }
                }
            }
        }
        answer++;
    }
    return 0;
}
