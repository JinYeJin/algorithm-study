//�׷��� - ���ͽ�Ʈ�� ����
/*
�׷����ʱⱸ���� 10001*10001�� �ҽ� �뷫3200mb�� �޸��ʰ���. �׷��� ��Ƽ������ ����.
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <limits.h>
#include <map>
using namespace std;
class info{
public:
	int a;
	int s;
	info(int a_,int s_):a(a_),s(s_){}
};
int T, n, d, c, time[10001];//�׽�Ʈ���̽�, ��ǻ�Ͱ���,����������,��ŷ���� ��ǻ�͹�ȣ ,�ּҽð�
multimap<int,info> mmap;//�׷��� ��
bool Node[10001];//���ͽ�Ʈ�� �̿�
void In() {
	cin >> n >> d >> c;
	int a, b, s;
	for (int count = 1; count<= d; count++) {
		cin >> a >> b >> s;
		mmap.insert(pair<int, info>(b,info(a,s)));
	}
}
int min_time() {
	int index=0, min_tm=INT_MAX;
	for (int tp = 1; tp <= n; tp++)
		if (Node[tp] == false && time[tp] < min_tm) {
			index = tp;
			min_tm = time[tp];
		}
	return index;
}
void answer_print() {
	int cnt = 0, maximum_tm = 0;
	for(int tp=1;tp<=n;tp++)
		if (time[tp] != INT_MAX) {
			cnt++;
			maximum_tm = (time[tp] > maximum_tm) ? time[tp] : maximum_tm;
		}
	cout << cnt <<' '<< maximum_tm<<'\n';
}
int main() {
	ios_base::sync_with_stdio(false);//1000ms
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		mmap.clear();
		In();
		for (int tp = 1; tp <= n; tp++)
			time[tp] = INT_MAX;
		time[c] = 0;
		for (int count = 1; count <= n - 1; count++) {
			int u = min_time();
			if (u == 0) break;
			for(multimap<int, info>::iterator iter=mmap.equal_range(u).first; iter!=mmap.equal_range(u).second; iter++)
			{
				iter->second.a;
					if (  Node[iter->second.a] == false &&  (time[iter->second.a] > time[u] + iter->second.s))
						time[iter->second.a] = time[u] + iter->second.s;//����
			}
				Node[u] = true;
		}
		answer_print();
		memset(Node, 0, sizeof(Node));//�׽�Ʈ���̽����� �ʱ�ȭ
	}
}