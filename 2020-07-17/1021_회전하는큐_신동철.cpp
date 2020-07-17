//그리디알고리즘 이용 덱이용
#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
using namespace std;
int N, M;
queue<int> order_qu;
deque<int> dq;
int main() {
	//입력
	cin >> N >> M;
	int od, answer = 0;
	for (int m = 1; m <= M; m++) {
		cin >> od;
		order_qu.push(od);
	}
	for (int n = 1; n <= N; n++) dq.push_back(n);
	while (!order_qu.empty()) {
		int cur_od = order_qu.front(), left, right;;
		order_qu.pop();
		for (int id = 0; id < N; id++) {
			if (dq[id] == cur_od) {
				if (id < N - id)
					rotate(dq.begin(), dq.begin() + id, dq.end());
				else
					rotate(dq.begin() + id, dq.begin()+N-1, dq.end()-N);
				answer += (id < N - id) ? id : N - id;
				break;
			}
		}
		N--;  dq.pop_front();
	}
	cout << answer;
}

/*
//그리디알고리즘 이용 덱이용
#include <iostream>
#include <deque>
#include <queue>
using namespace std;
int N, M;
queue<int> order_qu;
deque<int> dq;
int main() {
	//입력
	cin >> N >> M;
	int od,answer=0;
	for (int m = 1; m <= M; m++) {
		cin >> od;
		order_qu.push(od);		 }
	for (int n = 1; n <= N; n++) dq.push_back(n);
	while (!order_qu.empty()) {
		int cur_od = order_qu.front() , left, right;;
		order_qu.pop();
		for (int id = 0; id < N; id++) {
			if (dq[id] == cur_od) {
				left = id; right = N - left;
				break;
			}
		}
		if (left < right){//left선택
			answer += left;
			for (int count = 1; count <= left; count++) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else {//Right선택
			answer += right;
			for (int count = 1; count <= right; count++) {
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
		N--;  dq.pop_front();
	}
	cout << answer;
}
*/