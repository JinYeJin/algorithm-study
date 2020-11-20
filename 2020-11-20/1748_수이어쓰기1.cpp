#include <iostream>

using namespace std;

int N;

int main(){
    int size=1,num=10,answer=0;
    cin>>N;
    
    for(;num<=N;num*=10,size++){
        answer+=(num-num/10)*size; //N>num
    }
    num/=10;
    N-=num-1;
    answer+=N*size;
    cout<<answer;
    return 0;
}
