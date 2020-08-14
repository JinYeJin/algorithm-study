#include <stdio.h>

using namespace std;
int N, point[1001][4], answer=-1;
bool visited[1001];

bool check(int a,int b){
    int a_x1=point[a][0], a_y1=point[a][1], a_x2=point[a][2], a_y2=point[a][3], b_x1=point[b][0], b_y1=point[b][1], b_x2=point[b][2], b_y2=point[b][3];
    if((a_x2<b_x1 or b_x2<a_x1 or a_y2<b_y1 or b_y2<a_y1) or ((a_x1>b_x1 and a_x2<b_x2 and a_y1>b_y1 and a_y2<b_y2) or (b_x1>a_x1 and b_x2<a_x2 and b_y1>a_y1 and b_y2<a_y2)))
        return false; //직사각형이 안에 있는경우
    return true;
}
void DFS(int p){
    if(visited[p]) return;
    visited[p] = true;
    for(int i=1; i<=N; i++)
        if(check(i, p)) //서로 곂치면
            DFS(i);
}
int main(){
    scanf("%d",&N);
    for(int i=0; i<4; i++)
        point[0][i]=0;
    for(int i=1;i<=N; i++)
        scanf("%d%d%d%d",point[i],point[i]+1,point[i]+2,point[i]+3);
    
    for(int i=0; i<=N; i++){
        if(!visited[i]){
            answer++;
            DFS(i);
        }
    }
    printf("%d",answer);
    return 0;
}
