#include <iostream>
#include <cstring>

using namespace std;

int pnt[1000001],N,M;

int get_pnt(int a){
    return pnt[a]==-1?a:pnt[a]=get_pnt(pnt[a]);
}
void update_pnt(int a, int b){
    int p_a=get_pnt(a), p_b=get_pnt(b);
    if(p_a!=p_b) pnt[p_b]=p_a;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    memset(pnt,-1,sizeof(pnt));
    cin>>N>>M;
    bool check_sameset;
    int a,b;
    while(M--){
        cin>>check_sameset>>a>>b;
        if(check_sameset){
            cout<<(get_pnt(a)==get_pnt(b)?"YES\n":"NO\n");
        }else{
            update_pnt(a,b);
        }
    }
    return 0;
}
