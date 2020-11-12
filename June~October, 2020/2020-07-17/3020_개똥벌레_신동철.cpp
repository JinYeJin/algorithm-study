//시뮬레이션으로 해결
#include <iostream>
using namespace std;
int N, H;//크기,높이

int main() {
	ios_base::sync_with_stdio(false);
	cin >> N >> H;
	int bundle = (N / 2);
	int *bot=new int[H];
	int *top = new int[H];
	for (int h = 0; h < H; h++) {//초기화
		bot[h] = 0; top[h] = 0;
	}

	int b, t;
	long long bsum = 0;
	long long tsum = 0;
	for (int n = 1; n <= bundle; n++) {
		cin >> b >> t;
		bot[b]++;
		top[t]++;
		bsum ++;
		tsum ++;
	}
	long long * Sbot= new long long[H];
	long long * Stop= new long long[H];
	Sbot[1] = bsum, Stop[1] = tsum;
	for (int h = 2; h < H; h++) {
		Sbot[h] = Sbot[h - 1] - bot[h - 1];
		Stop[h] = Stop[h - 1] - top[h - 1];
	}
	delete[] bot; delete[] top;//bot,top초기화
	int mn_num = 200000;
	int count = 0;
	for (int h = 1; h <= H; h++) {
		int temp;
		if (h == 1 || h == H)
			temp=bundle;
		else
			temp=Stop[H - h + 1] + Sbot[h];
		if (temp < mn_num) {
			mn_num = temp;
			count = 1;
		}
		else if (temp == mn_num)
			count++;
	}
	cout << mn_num <<' '<< count;
}