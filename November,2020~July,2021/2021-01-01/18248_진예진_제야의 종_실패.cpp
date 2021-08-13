/*
[18248 제야의 종]
*/
#include <stdio.h>
#include <iostream> 
#include <string.h>
#include <vector>

using namespace std;

int main(){
    FILE *stream =freopen("S2\\27\\input\\18248.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    vector<vector<int>> bell_sound;


    cin >> N >> M;


    for(int i = 0; i < N; i++){
        vector<int> temp;
        for(int j = 0; j < M; j++){
            int s;
            cin >> s;
            temp.push_back(s);
        }
        bell_sound.push_back(temp);
    }

    for(int i = 1; i < N; i++){
        for(int j = 1; j < M; j++){
            if((bell_sound[i-1][j-1] == 1) &&  (bell_sound[i][j-1] == 0)){
                if(bell_sound[i-1][j] == 0 && (bell_sound[i][j]) == 1){
                    cout << "NO";
                    return 0;
                }
            }
            else if((bell_sound[i-1][j-1] == 0) &&  (bell_sound[i][j-1] == 1)){
                if(bell_sound[i-1][j] == 1 && (bell_sound[i][j]) == 0){
                    cout << "NO";
                    return 0;
                }
            }
        }
    }

    cout << "YES";

    return 0;
}
