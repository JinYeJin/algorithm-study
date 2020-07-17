/*
2020-07-12 진예진
[백준 3020 개똥벌레] https://www.acmicpc.net/problem/3020
*/
#include <stdio.h>
#include <algorithm>

using namespace std;

int ceiling[100001];
int floor_list[100001];

int main(){
    FILE *stream = freopen("S2\\7\\input\\3020_input.txt", "r", stdin);
    if(!stream) perror("freopen");

    int N, H;
    int result = 200001;
    int result_count = 0;

    scanf("%d %d", &N, &H);

	for(int i = 0; i < N/2; i++){
        scanf("%d", &ceiling[i]);
        scanf("%d", &floor_list[i]);
    }
		
	sort(ceiling, ceiling + N/2);
	sort(floor_list, floor_list + N/2);


	for (int current_height = 1; current_height <= H; current_height++) {
        int left = 0, right = N/2 - 1, mid;
        int floor_count = 0, ceiling_count = 0;


		// floor_count = lower_bound(floor_list, floor_list + (n / 2), current_height) - floor_list;

        while(left <= right){
            mid = (left + right) / 2;
            // 목표값보다 더 크니 right의 범위를 줄임
            // 같거나 작은 경우를 같이 처리해주는 이유는 정확히 같은 값이 존재하지 않을 수 있으므로
            if(floor_list[mid] >= current_height){
                floor_count = N/2 - mid;
                right = mid - 1;
            }
            // 이 경우는 목표값보다 작음
            else left = mid + 1;
            // 같은경우, 배열 길이에서 찾은 인덱스의 값만큼 뺌
        }

        left = 0, right = N/2 - 1;

		// ceiling_count = upper_bound(ceiling, ceiling + (n / 2), H - current_height + 1) - ceiling;

        while(left <= right){
            mid = (left + right) / 2;
            int position = H - ceiling[mid] + 1;
            // 천장에서 종유석 길이만큼 빼주고 1 더해야 개똥벌레가 지나가는 칸
            if(position <= current_height){
                ceiling_count = N/2 - mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }

        int count = floor_count + ceiling_count;

		if (result == count)
			result_count++;
		else if (result > count) { 
			result = count;
			result_count = 1;
		}
	}

    printf("%d %d", result, result_count);
    return 0;
}
