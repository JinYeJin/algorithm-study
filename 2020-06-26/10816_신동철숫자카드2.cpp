#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, M;
vector<int> vec;
vector<pair<int,int>> mycard_vec;
queue<int> M_qu;
void In() {
	cin >> N;
	int a;
	for (int tp = 1; tp <= N; tp++) {
		cin >> a;
		vec.push_back(a);
	}

	cin >> M;
	for (int tp = 1; tp <= M; tp++) {
		cin >> a;
		M_qu.push(a);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	In();
	sort(vec.begin(), vec.end(), less<int>());
	
	//mycard_vec 의 첫번재 인자는 카드번호, 두번째 인자는 해당 카드번호의 갯수
	int cntv = 1;
	int temp = 0;
	vector<int>::iterator iter;
	for (iter = vec.begin(); iter != vec.end(); iter++) {
		if (temp == (*iter))
			cntv++;
		else {
			if(iter != vec.begin())
				mycard_vec.push_back(pair<int,int>(temp,cntv));
			temp = (*iter);
			cntv = 1;
		}
	}
	mycard_vec.push_back(pair<int, int>(temp, cntv));
	//

	while (!M_qu.empty()) {
		int val = M_qu.front();
		M_qu.pop();

		int left = 0, right = (int)mycard_vec.size() - 1, mid;
		bool flag = false;
		while (left <= right) {
			mid = (left + right) / 2;
			if (val == mycard_vec[mid].first) {
				cout << mycard_vec[mid].second << ' ';
				flag = true;
				break;
			}
			else if (val < mycard_vec[mid].first) right = mid - 1;
			else
				left = mid + 1;
		}
		if (flag == false)
			cout << '0'<<' ';

		//flag 초기화
		flag = false;
	}
		
}