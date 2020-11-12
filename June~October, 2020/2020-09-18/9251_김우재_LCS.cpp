#include <iostream>
#include <string>
#include <vector>

using namespace std;

int d[1001][1001];
int main(){
    string str1, str2;
    cin >> str1 >> str2;
    
    int size1 = str1.size();
    int size2 = str2.size();

    for(int i=1; i <= size1; i++){
        for(int j=1; j <= size2; j++){
            if(str1[i-1] == str2[j-1]) {d[i][j] = d[i-1][j-1]+1;}
            else {d[i][j] = max(d[i][j-1], d[i-1][j]);}
        }
    }
    
    cout << d[size1][size2] << "\n";
    
    return 0;
}
