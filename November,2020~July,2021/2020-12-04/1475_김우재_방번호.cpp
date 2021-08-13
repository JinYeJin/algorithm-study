#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<int> arr(10, 0);
    char number[1000000];
    scanf("%s", number);
    
    int numberSize = strlen(number);
    for (int i = 0 ; i < numberSize; i++) {
        arr[number[i] - '0']++;
    }
    
    int answer = 0;
    for (int i = 0; i < 10; i++){
        if (i != 9 && i != 6) {
            answer = max(answer, arr[i]);
        }
    }
    answer = max((arr[6] + arr[9] + 1) / 2, answer);
    printf("%d\n", answer);


    return 0;
}


