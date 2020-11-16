#include <iostream>

using namespace std;

int pow(int a){
    return a*a;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T,x1,y1,x2,y2,n,cx,cy,r;
    for(cin>>T;T--;){
        int answer=0;
        cin>>x1>>y1>>x2>>y2;
        for(cin>>n;n--;){
            cin>>cx>>cy>>r;
            if(pow(cx-x1)+pow(cy-y1)<pow(r)^pow(cx-x2)+pow(cy-y2)<pow(r)) answer++;
        }
        cout<<answer<<'\n';
    }
    return 0;
}
