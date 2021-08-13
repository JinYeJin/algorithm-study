/*
[백준 14235 크리스마스 선물] 
*/
#include <stdio.h>
#include <iostream> 
#include <queue>

using namespace std;

int main(){
    FILE *stream =freopen("S2\\26\\input\\14235.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    priority_queue<int> presents;

    int N, a, num_present, present;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> a;
        if(a != 0){ 
            num_present = a;
            while(num_present--){
                cin >> present;
                presents.push(present);
            }
        }
        else{
            if(!presents.empty()){
                cout << presents.top() << "\n";
                presents.pop();
            }
            else cout << -1 << "\n";
        }
    }
    return 0;
}
