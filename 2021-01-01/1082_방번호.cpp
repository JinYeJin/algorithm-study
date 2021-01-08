/*
[1082 방 번호]
*/
#include <stdio.h>
#include <iostream> 
#include <string>
#include <string.h>

using namespace std;

int purchased[11];
int price[11];
int N, cost;
string max_room_number = "-1";

void dfs(int purchased[], string room_number, int index, int current_cost){
    if(index == -1){
        cout << room_number;
        return;
    }

    if(index > 0){
        string next_room_number = room_number;
        next_room_number += to_string(index);
        purchased[index]++;

        if(stoi(room_number) > stoi(max_room_number)){
            if(current_cost + price[index] < cost){
                max_room_number = room_number;
            }
        }

        // 다음 번호를 구매하는 경우
        dfs(purchased, next_room_number, index - 1, current_cost);
        // 이번 번호를 다시 구매하는 경우
        dfs(purchased, room_number, index, current_cost);
    }
}

int main(){
    FILE *stream =freopen("S2\\27\\input\\1082.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> price[i];
    }

    cin >> cost;

    string a = "a";
    int b = 1;
    //char cb = "b";
    string sb = "b";
    a += sb;
    // a += (char)b;

    cout << a;

    dfs(purchased, "", N-1, 0);

    return 0;
}
