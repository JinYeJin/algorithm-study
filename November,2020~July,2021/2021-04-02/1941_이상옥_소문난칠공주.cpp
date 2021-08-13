#include <iostream>
#include <cstring>

using namespace std;

int visited[1<<25],answer=0;
char girls[25];

void DFS(int n,int bit_mask){
    if(visited[bit_mask]+n<4) return;
    if(n==0){
        answer++;
    }
    for(int i=0;i<25;i++){
        int bit=(1<<i);
        int bit_next=bit_mask | bit;
        if(visited[bit_next]==-1){
            visited[bit_next]=visited[bit_mask];
            if(girls[i]=='S'){
                visited[bit_next]++;
            }
            if((i%5>0 && (bit_mask&(bit>>1)))|| (i%5<4 && (bit_mask&(bit<<1))) || (bit_mask&(bit<<5)) || (bit_mask&(bit>>5)))
                DFS(n-1,bit_next);
        }
    }
}
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    memset(visited,-1,sizeof(visited));
    for(int i=0;i<25;i++){
        cin>>girls[i];
    }
    for(int i=0;i<25;i++){
        visited[1<<i]=0;
        if(girls[i]=='S') visited[1<<i]++;
        DFS(6,1<<i);
    }
    cout<<answer;
    return 0;
}
