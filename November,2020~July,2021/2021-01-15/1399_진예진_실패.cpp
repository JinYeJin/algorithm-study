#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    FILE *stream = freopen("S2\\28\\input\\1339.txt", "r", stdin);
    if(!stream) perror("freopen");

    int N;
    int map[52]; // 알파벳에 숫자 매핑
    memset(map, -1, sizeof(map));

    cin >> N;

    vector<string> alphabets;
    vector<string> answer_numbers(10, "");



    for(int n = 0; n < N; n++){
        string temp;
        cin >> temp;
        alphabets.push_back(temp);
    }

    sort(alphabets.begin(), alphabets.end());

    int number = 9; // 할당할 숫자
    int idx = alphabets[0].size() - 1;

    while(idx >= 0){
        for(int n = 0; n < N; n++){
            int size = alphabets[n].size()-1;
            char ascii = alphabets[n][size-idx];
            int character_idx = (int)ascii - 'A'; 

            // 알파벳에 할당된 수가 없으면
            if(map[character_idx] == -1){
                map[character_idx] = number;
                number--;
            }

            answer_numbers[n].push_back((char)map[character_idx] + 0x30);

            // 마지막 단어이면 idx 감소
            if(n == N-1){
                idx--;
            }
            // 마지막 단어가 아니고, 다음 문자열이 index 보다 짧으면 지금 문자열 한번 더 실행
            else{
                if(alphabets[n+1].size()-1 < idx){
                    n--;
                    idx--;
                }
            }
        }
    }

    int answer = 0;

    for(int n = 0; n < N; n++){
        answer+= stoi(answer_numbers[n]);
    }

    cout << answer;

    return 0;
}
