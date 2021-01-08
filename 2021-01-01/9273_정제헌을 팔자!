/*
https://www.slideserve.com/urbana/sample-solutions-ctu-open-contest-2013-czech-technical-university-in-prague
https://www.acmicpc.net/problem/7516
*/
#include <stdio.h>
#include <iostream> 
#include <string>

using namespace std;

int main(){
    FILE *stream =freopen("S2\\27\\input\\9273.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string input_value;

    while(true){
        cin >> input_value;
        string denominator = input_value.substr(2);
        int n = stoi(denominator);

        int answer = 0;

        for(int a = n+1; a <= n*2; a++){
            if(a*n%(a-n) == 0){
                answer++;
                cout << "answer: " << a << "\n";
            }
        }

        cout << answer;
        if(cin.eof() == true) break;
        else cout << "\n";
    }

    return 0;
}
