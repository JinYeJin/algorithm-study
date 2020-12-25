#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int main(){
    FILE *stream = freopen("S2\\26\\input\\3048.txt", "r", stdin);
    if(stream) perror("freopen");
    cin.tie(0);
    cout.tie(0);

    int n1, n2;
    int T;
    string a, b;
    vector<char> a_answer, b_answer;

    cin >> n1 >> n2;
    cin >> a >> b;
    cin >> T;

    int temp_t = n1-T;

    for(int i = n1-1; i >= 0; i--){
        if(temp_t > 0){
            a_answer.push_back(a[i]);
            temp_t--;
        }
        else{
            a_answer.push_back('0');
            a_answer.push_back(a[i]);
        }
    }

    temp_t = n2-T;

    for(int i = 0; i < n2; i++){
        if(temp_t > 0){
            b_answer.push_back(b[i]);
            temp_t--;
        }
        else{
            b_answer.push_back('0');
            b_answer.push_back(b[i]);
        } 
    }

    int i = 0;
    while((a_answer.size() != 0) || (b_answer.size() != 0)){
        if(a_answer.size() != 0){
            if(a_answer[i] != '0') cout << a_answer[i];
            a_answer.pop_back();
        }
        if(b_answer.size() != 0){
            if(b_answer[i] != '0') cout << b_answer[i];
            b_answer.pop_back();
        }
        i++;
    }
    return 0;
}
