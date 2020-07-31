/*
[백준 2613 숫자구슬] https://www.acmicpc.net/problem/2613
*/
#include <stdio.h>
#include <vector>

using namespace std;

int main(){
    FILE *stream =freopen("S2\\9\\input\\2613_input.txt", "r", stdin);
    if(!stream) perror("freopen");

    int M, N;
    int left, mid, right;
    int marble[301];
    vector<int> group_index;
    vector<int> answer_index;

    // N: 구슬의 개수, M: 만드려는 그룹의 수
    scanf("%d %d", &N, &M);

    for(int i = 0; i < N; i++){
        scanf("%d", &marble[i]);
    }

    int min_sum = 30000;
    left = 0, right = 30000;

    while(right - left > 1){
        group_index.clear();
        mid = (left + right) / 2;

        int local_sum = 0;
        int local_max = 0;

        for(int i = 0; i < N; i++){
            // 현재 정한 최대값(mid)보다 작거나 같은 경우
            if(local_sum + marble[i] <= mid){
                // 최대값을 넘지 않았는데 마지막인덱스인 경우 인덱스 추가
                if(i == N - 1) group_index.push_back(i);
                local_sum += marble[i];
            }else{
                // 그룹의 최대값 구하기
                local_max = local_sum > local_max ? local_sum : local_max;
                local_sum = 0;
                // 이번 i 값을 더하지 못했으니 i--
                if(i == 0){
                    local_max = marble[i] > local_max ? marble[i] : local_max;
                }else i--; // i == 0 일 때 i-- 에러
                group_index.push_back(i);
            }
        }

        // 각 그룹의 최대값이 만약 최소값을 갱신하거, M개의 그룹이 완성됐다면
        if(local_max < min_sum && group_index.size() == M){
            // 정답으로 출력할 각 그룹의 최대값의 최소값 갱신
            min_sum = local_max;
            answer_index = group_index;
        }

        // 그룹이 목표치인 M 보다 더 많으면 최소값을 높여야함
        if(group_index.size() > M) left = mid;
        else right = mid;
    }

    printf("%d\n", min_sum);

    vector<int>::iterator iter = answer_index.begin();

    printf("%d ", *iter+1);

    for(iter; iter != answer_index.end() - 1; iter++){
        printf("%d ", iter[1] - *iter);
    }

    return 0;
}
