#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N,K,M, p, size;
    scanf("%d%d%d",&N,&K,&M);
    vector<int> map(N);
    for(int i=0; i<N; i++)
        map[i]=i+1;
    p=N;
    size=N;
    for(int i=0; i<N; i++){
        p = (p+K-1)%size--;
        if(map[p] == M){
            printf("%d\n",i+1);
            break;
        }
        map.erase(map.begin()+p);
    }
    
    return 0;
}

