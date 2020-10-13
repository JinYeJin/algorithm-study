#include <iostream>
#include <vector>
#include <set>

#define turn(x) (x+3)%4
using namespace std;

int T,n,r,x,y, dx[]={1,0,-1,0}, dy[]={0,1,0,-1},d;
vector<vector<bool>> map;
set<pair<pair<int,int>,int>> visited;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(cin>>T;T--;){
        cin>>n>>r;
        visited.clear();
        map.clear();
        map.resize(n+2, vector<bool>(n+2,0));
        for(int i=0;i<r;i++){
            cin>>x>>y;
            map[y][x]=1;
        }
        cin>>x>>y;

        if(x==0){x++; d=0;}
        else if(y==0){y++; d=1;}
        else if(x==n+1){x--; d=2;}
        else if(y==n+1){y--; d=3;}
        for(;x!=0 and y!=0 and x!=n+1 and y!=n+1;x+=dx[d],y+=dy[d]){
            if(map[y][x]){
                if(visited.find({{x,y},d})!=visited.end()){
                    x=0;y=0;
                    break;
                }
                visited.insert({{x,y},d});
                d=turn(d);
            }
        }
        cout<<x<<' '<<y<<'\n';
    }
    return 0;
}

