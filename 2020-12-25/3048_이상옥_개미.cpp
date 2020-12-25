#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N1, N2;
    pair<char,int> map[200];
    cin>>N1>>N2;
    for(int i=N1-1;i>=0;i--){
        cin>>map[i].first;
        map[i].second=1;
    }for(int i=0;i<N2;i++){
        cin>>map[N1+i].first;
        map[N1+i].second=2;
    }
    int T;
    cin>>T;
    for(;T--;){
        for(int j=1;j<N1+N2;j++){
            if(map[j-1].second<map[j].second){
                reverse(map+j-1,map+j+1);
                j++;
            }
        }
    }
    for(int i=0;i<N1+N2;i++){
        cout<<map[i].first;
    }
    return 0;
}
