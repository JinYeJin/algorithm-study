#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
class ABC {
public:
	int A, B, C;
	ABC(int A_,int B_,int C_) :A(A_),B(B_),C(C_){}
};
int N, M, AB[501][501];
long long time[501];
vector<ABC> ABC_vec;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		time[i] = INT_MAX;
		for (int j = 1; j <= N; j++) {
			AB[i][j] = INT_MAX;
		}
	}
	int a, b,c;
	for (int m = 0; m < M; m++) {
		cin >> a >> b;
		cin >> c;
		if (c < AB[a][b])
			AB[a][b] = c;
	}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			if (AB[i][j] == INT_MAX) continue;
			else ABC_vec.push_back(ABC(i, j, AB[i][j]));
		}
	time[1] = 0;
	vector<ABC>::iterator iter;
	for (int count = 1; count < N; count++) {
		for (iter = ABC_vec.begin(); iter != ABC_vec.end(); iter++) {
			int a_ = (*iter).A;  int b_ = (*iter).B; int c_ = (*iter).C;
			if (time[a_]!=INT_MAX &&  time[b_] > (time[a_] + c_)) time[b_] = (time[a_] + c_);
		}
	}
	for (iter = ABC_vec.begin(); iter != ABC_vec.end(); iter++) {
		int a_ = (*iter).A;  int b_ = (*iter).B; int c_ = (*iter).C;
		if (time[a_] != INT_MAX &&  time[b_] > (time[a_] + c_)) {
			cout << -1;
			return 0;
		}
	}
	for (int n = 2; n <= N; n++) {
		if (time[n] == INT_MAX)
			cout << -1 << '\n';
		else
			cout << time[n] << '\n';
	}
}