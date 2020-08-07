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
int N, A, B, C, maxv,idx;//����,�θ�,�ڽ�,����ġ��,�ִ�����
int check[10001];//�Ÿ������ ��Ž������ �뵵 
multimap <int, info> mmap;//�θ�,�ڽ�,����ġ��
queue <int> qu;
void bfs() {
	multimap<int, info>::iterator iter;
	while (!qu.empty()) {
		int cur_nd = qu.front();
		qu.pop();
		for (iter = mmap.equal_range(cur_nd).first; iter != mmap.equal_range(cur_nd).second; iter++) {
			int next_nod = iter->second.b;
			int next_wei = iter->second.c;
			if (check[next_nod] == -1) {//��� �˻�
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
	//�Է�
	cin >> N;
	//����ó��
	if (N == 1) {
		cout << 0;
		return 0;
	}
	while (cin >> A) {
		cin >> B >> C;
		mmap.insert(pair<int, info>(A, info(B, C)));
		mmap.insert(pair<int, info>(B, info(A, C)));
	}
	//���
	memset(check, -1, sizeof(check));//�ʱ�ȭ 
	check[1] = 0;
	qu.push(1);
	bfs();
	max_find();
	memset(check, -1, sizeof(check));//�ʱ�ȭ 
	check[idx] = 0;
	qu.push(idx);
	bfs();
	max_find();
	//���
	cout << maxv;
}