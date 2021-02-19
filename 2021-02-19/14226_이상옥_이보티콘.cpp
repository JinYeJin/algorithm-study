#include <iostream>
#include <queue>

using namespace std;

int N;
bool visited[1001][1001]={0};

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>N;
    for(int i=0;i<1001;i++) visited[0][i]=1;
    queue<pair<int,pair<int,int>>> Q;
    Q.push({0,{1,0}});
    while(Q.size()){
        auto q=Q.front();Q.pop();
        int cnt=q.first,len=q.second.first,clip=q.second.second;
        if(visited[len][clip]) continue;
        if(len==N){
            cout<<cnt;
            break;
        }
        visited[len][clip]=1;
        cnt++;
        if(!visited[len][len]) Q.push({cnt,{len,len}});
        if(len+clip<1001 and !visited[len+clip][clip]) Q.push({cnt,{len+clip,clip}});
        if(!visited[len-1][clip]) Q.push({cnt,{len-1,clip}});
    }
    return 0;
}
