#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int T,dx[]={0,1,0,-1}, dy[]={1,0,-1,0};
    for(cin>>T;T--;){
        string s;
        int d=0,x=0,y=0,max_x=0,min_x=0,max_y=0,min_y=0;
        cin>>s;
        for(char c:s){
            if(c=='F'){
                x+=dx[d], y+=dy[d];
                max_x=max(max_x,x), min_x=min(min_x,x), max_y=max(max_y,y), min_y=min(min_y,y);
                continue;
            }
            if(c=='B'){
                x-=dx[d], y-=dy[d];
                max_x=max(max_x,x), min_x=min(min_x,x), max_y=max(max_y,y), min_y=min(min_y,y);
                continue;
            }
            d=(d+1)%4;
            if(c=='L') d=(d+2)%4;
        }
        cout<<(max_x-min_x)*(max_y-min_y)<<'\n';
    }
    return 0;
}


