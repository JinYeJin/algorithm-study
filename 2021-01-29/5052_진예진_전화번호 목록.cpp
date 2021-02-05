/*
[백준 5052] 전화번호 목록 acmicpc.net/problem/5052
*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int main(){
    FILE *stream =freopen("S2\\21\\input\\5052.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T, N;
    bool exit_flag;
    vector<string> numbers;

    cin >> T;

    for(int t = 0; t < T; t++){
        numbers.clear();
        // 번호 입력

        cin >> N;
        for(int n = 0; n < N; n++){
            string temp;
            cin >> temp;
            numbers.push_back(temp);
        }

        sort(numbers.begin(), numbers.end());
        exit_flag = false;

        for(int n = 0; n < N-1; n++){
            for(int i = 0; i < 10; i++){
                char *char1 = &numbers[n][i];
                char *char2 = &numbers[n+1][i];
                // str1이 str2의 prefix인 경우
                // str2가 str1의 prefix인 경우 => 일관성이 없다.
                if(i >= numbers[n].size() || i >= numbers[n].size()){
                    cout << "NO\n";
                    exit_flag = true;
                    break;
                }


                // cout << numbers[n][1] << "\n";
                // 다른 경우엔 다음 단어로 넘어감
                if(*char1 != *char2) break;
            }

            if(exit_flag) break;
        }

        if(!exit_flag) cout << "YES\n";
    }
    return 0;
}
