/*
풀이과정

012345 78 에서 사용된 수만큼 배열에 넣어놓고  그것을 ary[?] 라고 할때
ary[?]  >=    max(6이 사용된 횟수 OR 9가 사용된 횟수) ;  ary[?] 가 정갑.

ary[?] < max(6이 사용된 횟수 OR 9가 사용된 횟수);
예시)

번호	6   9
횟수	2   5   ;  3) 3  3    4)4  4
					  2  4      2  6  <= 정답은 4세트.
정답을 X세트라고 일단 두고, 유도과정.
Y(차액) = X세트 -작은값(2)
Y(차액)+작은값(2) = X세트
X세트 + Y(차액) >= (큰값)5?
X세트 + (X세트- 작은값(2) ) >=(큰값)5?
2X > = (큰값)5+ 작은값(2)
X >= ((큰값)5+ 작은값(2)) / 2  인 정수 X를 찾기.


*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int ary[10];//인덱스는 0~ 9
int elsemaxv;
void In() {
	int a;

	while (~scanf("%1d", &a)) {
		ary[a]++;
		if (a != 6 && a != 9 &&  elsemaxv < ary[a]) { // 6,9 를 제외한 수중에서 최댓값 갱신
			elsemaxv = ary[a];
		}
	}
}
void func() {
	if (elsemaxv >= max(ary[6], ary[9])) {
		cout << elsemaxv;
		return;
	}
	else
	{
		double value = (ary[6] + ary[9]) / (double)2;
			((int)ceil(value) > elsemaxv) ?cout<< (int)ceil(value) : cout <<elsemaxv;
		return;
	}
}
int main(void)
{
	In();
	
	func();
}