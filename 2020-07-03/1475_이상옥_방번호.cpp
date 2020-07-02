#include <iostream>
using namespace std;

#define max(a,b) a>b ? a:b

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    string room;
    int number[10] ={0,};
    
    cin>>room;

    for(char i:room)
        number[i-'0']++;

    number[6] = (number[6]+number[9]+1)/2; //69를 하나로 침.
    number[9]=0;

    for(int i:number)
        number[0]=max(number[0], i);

    cout<<number[0]<<endl;
    return 0;
}

