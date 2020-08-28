/*
[백준 14427 수열과 쿼리] https://www.acmicpc.net/problem/14427
참고 https://blog.encrypted.gg/487
세그먼트 트리? 바이너리 서치 트리? https://os94.tistory.com/88
*/
#include <stdio.h>
#include <set>
#include <utility>

using namespace std;

int N, M;
int A[100004];

int main(void){
    FILE *stream =freopen("S2\\13\\input\\14427.txt", "r", stdin);
    if(!stream) perror("freopen");
    int temp;

	set<pair<int, int>> S; // 오름차순으로 자동정렬
    scanf("%d", &N);

    for(int i = 1; i <= N; i++){
        scanf("%d", &temp);
        A[i] = temp;
		S.insert({ A[i], i }); // value가 키, index가 값
        // value우선, 다음은 index 기준으로 정렬되므로, 최소값 삭제에 O(1)의 시간 소요
	}


    scanf("%d", &M);

	while (M--) {
		int query;
        scanf("%d", &query);

        // 수정인 경우
		if (query == 1){
			int i, v;
            scanf("%d %d", &i, &v);
			S.erase({ A[i], i });
			A[i] = v;
			S.insert({ A[i], i });
		}
        // 최소값 삭제인 경우
		else if(query == 2){
			auto t = *S.begin();
            // 삭제되는 값의 index 출력
            printf("%d\n", t.second);
		}
	}
}
