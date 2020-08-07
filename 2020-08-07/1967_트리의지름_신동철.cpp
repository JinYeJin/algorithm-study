#include <iostream>
#include <map>
#include <cstring>
#include <queue>
using namespace std;
class info {
public:
	int b, c;
	info(int b_, int c_) :b(b_), c(c_) {}
};
int N, A, B, C, maxv,idx;//노드수,부모,자식,가중치값,최대지름
int check[10001];//거리저장및 재탐지방지 용도 
multimap <int, info> mmap;//부모,자식,가중치순
queue <int> qu;
void bfs() {
	multimap<int, info>::iterator iter;
	while (!qu.empty()) {
		int cur_nd = qu.front();
		qu.pop();
		for (iter = mmap.equal_range(cur_nd).first; iter != mmap.equal_range(cur_nd).second; iter++) {
			int next_nod = iter->second.b;
			int next_wei = iter->second.c;
			if (check[next_nod] == -1) {//경로 검사
				check[next_nod] = check[cur_nd] + next_wei;
				qu.push(next_nod);
				//maxv = (check[next_nod] > maxv) ? check[next_nod] : maxv;
			}
		}
	}
}
void max_find() {
	for (int k = 1; k <= N; k++) 
		if (check[k] > maxv) {
			maxv = check[k];
			idx = k;
		}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//입력
	cin >> N;
	//예외처리
	if (N == 1) {
		cout << 0;
		return 0;
	}
	while (cin >> A) {
		cin >> B >> C;
		mmap.insert(pair<int, info>(A, info(B, C)));
		mmap.insert(pair<int, info>(B, info(A, C)));
	}
	//계산
	memset(check, -1, sizeof(check));//초기화 
	check[1] = 0;
	qu.push(1);
	bfs();
	max_find();
	memset(check, -1, sizeof(check));//초기화 
	check[idx] = 0;
	qu.push(idx);
	bfs();
	max_find();
	//출력
	cout << maxv;
}