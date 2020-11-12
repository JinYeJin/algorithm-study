#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#include <string>

using namespace std;

int abs(int a){
    return a>0?a:-a;
}
int distance(pair<int,int> a, pair<int,int> b){
    return abs(a.first-b.first)+ abs(a.second-b.second);
}

bool beer(){
    int n;
    scanf("%d", &n);
    pair<int, int> home,festival;
    vector<pair<int,int>> con(n);
    queue<pair<int,int>> now;
    map<pair<int,int>,int> visited; //0:방문 x 1:방문 o -1:도착지점

    scanf("%d %d", &home.first, &home.second);
    now.push(home);

    for(int i=0; i<n; i++)
        scanf("%d %d", &con[i].first, &con[i].second);
    scanf("%d %d", &festival.first, &festival.second);
    
    bool flag=true;
    for(int i=0; i<n; i++)
        if(distance(festival,con[i])<=1000){
            flag=false;
            visited[con[i]] = -1;
        }
    if(distance(home, festival)<=1000)
        return true;
    if(flag)
        return false;
    while(!now.empty()){
        int s = (int)now.size();
        while(s--!=0){
            pair<int,int> temp = now.front();
            now.pop();
            for(auto next:con){
                if(visited[next]!=1 and distance(temp, next)<=1000){
                    if(visited[next]==-1)
                        return true;
                    visited[next]=1;
                    now.push(next);
                }
            }
        }
    }
    return false;
}
    
int main(){
    int t;
    scanf("%d",&t);
    while(t--!=0)
        printf("%s\n",beer()?"happy":"sad");
    return 0;
}
