#include <stdio.h>
#include <iostream> 

using namespace std;

int main(){
    FILE *stream =freopen("S2\\31\\input\\2003.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    int numbers[10001];

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> numbers[i];
    }

    int left = 0;
    int right = 1;
    int number = numbers[left] + numbers[right];
    int answer = 0;

    while(left < N){
        if(number == M) answer++;
        if(number < M){
            right++;
            number += numbers[right];
            if(right > N) break;
        }
        else{
            number -= numbers[left];
            left++;
        }
    }

    cout << answer;

    return 0;
}
