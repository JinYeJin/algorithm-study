#include <stdio.h>
#include <iostream>
#include <stack>


using namespace std;

int main(){
    FILE *stream =freopen("S2\\37\\input\\1094.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int X;
    stack<int> stick;

    cin >> X;
    stick.push(64);
    int sum = 64;

    int i = 0;
    while(true){
        if(sum == X) break;
        int current_stick = stick.top();
        stick.pop();
        int half = current_stick / 2;
        sum -= current_stick;

        if(sum + half >= X){
            stick.push(half);
            sum += half;
        }else{
            stick.push(half);
            stick.push(half);
            sum += current_stick;
        }
    }

    cout << stick.size();
    
    return 0;
}
