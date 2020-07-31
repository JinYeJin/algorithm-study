#include <stdio.h>

using namespace std;

int R, C, answer=0, dr[]={-1,0,1};
char temp;
bool bread[10002][500];

bool dfs(int r, int c){
    if(!bread[r][c]) return false;
    bread[r][c]=false;

    if(c==C-1){
        answer++;
        return true;
    }
    for(int i=0;i<3;i++)
        if(dfs(r+dr[i],c+1)) return true;
    return false;
}
int main(){
    scanf("%d %d\n",&R, &C);
    for(int r=1; r<=R; r++){
        for(int c=0; c<C; c++){
            scanf("%c",&temp);
            bread[r][c]=temp=='.'; //. 설치가 가능한 부분을 true로 설정.
        }
        scanf("%c", &temp);
    }
    for(int r=0;r<R;r++)
        dfs(r,1);
    printf("%d\n",answer);
    return 0;
}
