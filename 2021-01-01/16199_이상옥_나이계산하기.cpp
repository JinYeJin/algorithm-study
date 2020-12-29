#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    int b_y,b_m,b_d,y,m,d;
    cin>>b_y>>b_m>>b_d>>y>>m>>d;
    cout<<(y-b_y)+((m-b_m)*100+(d-b_d)<0?-1:0)<<'\n';
    cout<<y-b_y+1<<'\n';
    cout<<y-b_y;
    return 0;
}
