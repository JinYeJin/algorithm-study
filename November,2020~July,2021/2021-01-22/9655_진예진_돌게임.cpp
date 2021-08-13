/*
9655 돌게임
*/
#include <stdio.h>
#include <iostream> 

using namespace std;

int main(){
    FILE *stream =freopen("S2\\29\\input\\9655.txt", "r", stdin);
    if(!stream) perror("freopen");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;

    cin >> N;

    if(N%2==0) cout << "CY";
    else cout << "SK";

    return 0;
}
