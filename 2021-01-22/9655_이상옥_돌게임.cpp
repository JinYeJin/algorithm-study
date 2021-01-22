#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    //1 SK
    //2 CY
    //3 SK
    //4 CY
    //5 SK
    //6 CY
    //7 SK
    //8 CY
    int N;
    cin>>N;
    cout<<(N%2==0?"CY":"SK");
    return 0;
}

