#include <iostream>

#define INF 987654321
using namespace std;

char arr[10002]={0};
int N;

int PANG(int top,int bot,int cnt,char color){
    int answer=top+N-bot+1;
    while(color!=0 and color==arr[top]){
        cnt++;
        top--;
    }
    while(color!=0 and color==arr[bot]){
        cnt++;
        bot++;
    }
    if(cnt<4) return answer;
    answer=PANG(top,bot,0,arr[top]);
    if(arr[top]!=arr[bot]) answer=min(answer,PANG(top,bot,0,arr[bot]));
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int answer=INF;
    cin>>N;
    for(int i=1;i<=N;i++) cin>>arr[i];
    for(int i=1;i<=N;i++)
    {
        answer=min(answer,PANG(i-1,i+1,1,arr[i-1]));
        if(arr[i-1]!=arr[i+1]) answer=min(answer,PANG(i-1,i+1,1,arr[i+1]));
    }
    cout<<answer;
    return 0;
}
