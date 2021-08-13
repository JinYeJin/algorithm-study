/*
[16199 나이 계산하기]
*/
#include <stdio.h>
#include <iostream> 

using namespace std;

int main(){
    FILE *stream =freopen("S2\\27\\input\\16199.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int birthday[3];
    int pivotday[3];
    int man_age, count_age, year_age;

    cin >> birthday[0] >> birthday[1] >> birthday[2];
    cin >> pivotday[0] >> pivotday[1] >> pivotday[2];

    year_age = pivotday[0] - birthday[0];
    count_age = year_age + 1;
    man_age = year_age;

    if(pivotday[0] != birthday[0]){
        man_age = year_age - 1;
        // 생일이 지난 경우
        if(pivotday[1] >= birthday[1]){
            if(pivotday[2] >= birthday[2]){
                man_age++;
            }
        }
    }


    cout << man_age << "\n";
    cout << count_age << "\n";
    cout << year_age << "\n";

    return 0;
}
