#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

int binary_to_decimal(int n) {
   int decimal_num = 0;
   int base = 1;
   int temp = n;

   while (temp) {
      int digit = temp % 10;
      temp = temp/10;
      decimal_num += digit * base;
      base = base*2;
   }
   return decimal_num;
}

int main(){
    FILE *stream =freopen("S2\\26\\input\\6568.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int pc = 0;
    int adder = 0;
    int memory[17];
    vector<string> commands;

    memset(memory, 0, sizeof(memory));

    for(int i = 0; i < 32; i++){
        string command;
        cin >> command;
        commands.push_back(command);
    }

    bool is_running = true;

    while(is_running){
        string command = commands[pc];
        string op = command.substr(0, 3);
        string address = command.substr(3);
        int deci_op = binary_to_decimal(stoi(op));
        int deci_address = binary_to_decimal(stoi(address));

        switch (deci_op)
        {
        case 0:// STA x   메모리 주소 x에 가산기의 값을 저장한다.
            memory[deci_address] = adder;
            break;
        case 1: // LDA x   메모리 주소 x의 값을 가산기로 불러온다.
            adder = memory[deci_address];
            break;
        case 2: // BEQ x   가산기의 값이 0이면 PC 값을 x로 바꾼다.
            if(adder == 0) pc = deci_address;
            break;
        case 3: // NOP     아무 연산도 하지 않는다.
            break;
        case 4: // DEC     가산기 값을 1 감소시킨다.
            adder -= 1;
            break;
        case 5: //INC     가산기 값을 1 증가시킨다.
            adder += 1;
            break;
        case 6: // JMP x   PC 값을 x로 바꾼다.
            pc = deci_address;
            break;
        case 7: // HLT     프로그램을 종료한다.
            is_running = false;
            break;
        }
        pc++;
        pc %= 32;
    }

    bool answer[8];

    for(int i = 7; i >= 0; i--){
        answer[i] = adder % 2;
        adder /= 2;
    }

    for(int i = 0; i < 8; i++){
        cout << answer[i];
    }

    return 0;
}
