/*
2020-07-09 진예진
[백준 3425 고스택] https://www.acmicpc.net/problem/3425
*/

#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    FILE *stream = freopen("S2\\6\\input\\3425_input.txt", "r", stdin);
    if(!stream) perror("freopen");

    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    
    vector<string> commands;
    // NUM 연산의 숫자 저장
    int temp_number[10000];
    stack<long long> numbers;
    string input_command;
    int input_number, N;
    long long temp, temp2;
    bool error_flag;

    while(true){
        commands.clear();
        cin >> input_command;
        // 종료
        if(input_command == "QUIT") return 0;

        int i = 0;
        while(input_command != "END"){
            if(input_command == "NUM"){
                cin >> input_number;
                temp_number[i] = input_number;
            }
            commands.push_back(input_command);
            cin >> input_command;
            i++;
        }

        // 개행
        cin;
        // N: 숫자의 개수
        cin >> N; 

        for(int i = 0; i < N; i++){
            cin >> input_number;
            numbers.push(input_number);
            error_flag = false;

            for(int j = 0; j < commands.size(); j++){
                // 스택에 값이 하나라도 있어야 연산가능
                if(numbers.empty()){
                    error_flag = true;
                    break;
                }
                string command = commands[j];
                temp = numbers.top();
                numbers.pop();
                
                if(command == "NUM"){
                    numbers.push(temp);
                    numbers.push(temp_number[j]);
                }else if(command == "POP"){
                    // numbers.pop();
                    continue;
                }else if(command == "INV"){
                    temp = -(temp);
                    numbers.push(temp);
                }else if(command == "DUP"){
                    numbers.push(temp);
                    numbers.push(temp);
                }else if(command == "SWP"){
                    if(numbers.empty()){
                        error_flag = true;
                        break;
                    }
                    temp2 = numbers.top();
                    numbers.pop();
                    numbers.push(temp);
                    numbers.push(temp2);
                }else if(command == "ADD"){
                    if(numbers.empty()){
                        error_flag = true;
                        break;
                    }
                    temp2 = abs(numbers.top());
                    numbers.pop();
                    numbers.push(temp + temp2);
                }else if(command == "SUB"){
                    if(numbers.empty()){
                        error_flag = true;
                        break;
                    }
                    temp2 = numbers.top();
                    numbers.pop();
                    numbers.push(temp - temp2);
                }else if(command == "MUL"){
                    if(numbers.empty()){
                        error_flag = true;
                        break;
                    }
                    temp2 = numbers.top();
                    numbers.pop();
                    numbers.push(temp * temp2);
                }else if(command == "DIV"){
                    if(numbers.empty()){
                        error_flag = true;
                        break;
                    }
                    temp2 = numbers.top();
                    if(temp == 0){
                        error_flag = true;
                        break;
                    }
                    numbers.pop();
                    // long long temp_result = temp2 / abs(temp);
                    long long temp_result = temp2 / temp;
                    // 둘 중 하나만 음수일 때 몫은 음수
                    if((temp2 > 0 && temp <= 0) || (temp2 <= 0 && temp > 0))
                        temp_result = -abs(temp_result);
                    else temp_result = abs(temp_result);
                    numbers.push(temp_result);
                }else if(command == "MOD"){
                    if(numbers.empty()){
                        error_flag = true;
                        break;
                    }
                    temp2 = numbers.top();
                    if(temp == 0){
                        error_flag = true;
                        break;
                    }
                    numbers.pop();
                    long long temp_result = temp2 % temp;
                    // 나머지의 부호는 피제수의 부호와 같음
                    // 걍 계싼값 넣으면 됨
                    numbers.push(temp_result);
                }
                if(error_flag == true) break;
                if(numbers.top() > 1e9 || numbers.top() < -1e9){
                    error_flag = true;
                    break;
                }
            }

            // 스택사이즈 1 아니거나, 커맨드 실행도중 에러가 난 경우
            if(numbers.size() != 1 || error_flag == true){
                cout << "ERROR" << "\n";
                while(!numbers.empty()) numbers.pop(); 
            }
            else{
                cout << numbers.top() << "\n";
                numbers.pop();
            }
        }

        cout << "\n";
        // 다음 반복 시작전 개행 없애기
        cin;
    }
    return 0;
}
