#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string A, B, AA;

    cin >> A >> B;

    AA = A;

    while(A.size() != B.size()){
        A = B[B.size()-A.size()-1] + A;
        // cout <<"BBB: " <<  B[AA.size()] << "\n";
        AA = AA + B[AA.size()];
        // cout << A << " " << AA;
    }

    int a_count = 0;
    int aa_count = 00;

    for(int i = 0; i < A.size(); i++){
        if(A[i] != B[i]) a_count++;
        if(AA[i] != B[i]) aa_count++;        
    }

    cout << (a_count < aa_count ? a_count : aa_count);

    return 0;
}


temp = input()
string_a, string_b = temp.split()

start_index = 0
max_hit = 0
len_of_gap = len(string_b) - len(string_a)

# string_a를 한칸씩 이동하면서 b와 몇개나 같은지 수를 센다.
for i in range(0, len_of_gap + 1):
    hit = 0

    for j in range(0, len(string_a)):
        if string_a[j] == string_b[start_index + j]:
            hit += 1

    start_index += 1
    whole_hit = hit + len_of_gap

    if max_hit < whole_hit:
        max_hit = whole_hit

print(len(string_b) - max_hit)
