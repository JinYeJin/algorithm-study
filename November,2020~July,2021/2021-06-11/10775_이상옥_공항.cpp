#include "bits/stdc++.h"

using namespace std;

int G,P,Left[100001];
int get_left(int a){
    return Left[a]==-1?a:Left[a]=get_left(Left[a]);
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    memset(Left,-1,sizeof(Left));
    cin>>G>>P;
    int g;
    for(int i=0;i<P;i++){
        cin>>g;
        
        if(get_left(g)==0){
            cout<<i;
            return 0;
        }
        else{
            Left[get_left(g)]=get_left(g)-1;
        }
    }
    cout<<P;
    return 0;
}


