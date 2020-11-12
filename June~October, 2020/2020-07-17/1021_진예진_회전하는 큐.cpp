/*
2020-07-15 진예진
[백준 1021 회전하는 큐] https://www.acmicpc.net/problem/1021
*/
#include <stdio.h>
#include <string.h>
#include <deque>

using namespace std;

int main(){
    FILE *stream = freopen("S2\\7\\input\\1021_input.txt", "r", stdin);
    if(!stream) perror("freopen");

    int N, M, count, count_left, count_right;
    int searching_list[50];
    deque<int> original, left, right;


    scanf("%d %d", &N, &M);

    for(int i = 1; i <= N; i++){
        original.push_back(i);
        left.push_back(i);
        right.push_back(i);
    }

    for(int i = 0; i < M; i++){
        scanf("%d", &searching_list[i]);
    }

    count = 0;

    for(int i = 0; i < M; i++){
        int target = searching_list[i];

        count_left = count_right = 0;

        while(true){
            if(left.front() == target){
                count += count_left;
                left.pop_front();
                right = left;
                break;
            }
            else if(right.front() == target){
                count += count_right;
                right.pop_front();
                // copy(right.begin(), right.end(), original.begin());
                left = right;
                break;
            }
            else{
                left.push_back(left.front());
                left.pop_front();
                count_left++;

                right.push_front(right.back());
                right.pop_back();
                count_right++;
            } 
        }
    }

    printf("%d", count);

    return 0;
}
