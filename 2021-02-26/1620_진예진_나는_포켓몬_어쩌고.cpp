#include <iostream>
#include <stdio.h>
#include <map>
#include <string>

using namespace std;

int main(){
    FILE *stream = freopen("S2\\32\\input\\1620.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    map<int, string> dictionary1;
    map<string, int> dictionary2;

    cin >> N >> M;

    for(int n = 1; n <= N; n++){
        string temp;
        cin >> temp;
        dictionary1[n] = temp;
        dictionary2[temp] = n;
    } 

    for(int m = 0; m < M; m++){
        string temp;
        bool is_int = true;
        int input_value;
        cin >> temp;

        try{
            input_value = stoi(temp);
        }catch(const std::invalid_argument& ia){
            is_int = false;
        }

        if(is_int){
            cout << dictionary1[input_value] << "\n";
        }else{
            cout << dictionary2[temp] << "\n";
        }

    }
    return 0;
}
