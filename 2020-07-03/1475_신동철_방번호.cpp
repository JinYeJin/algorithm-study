/*
Ǯ�̰���

012345 78 ���� ���� ����ŭ �迭�� �־����  �װ��� ary[?] ��� �Ҷ�
ary[?]  >=    max(6�� ���� Ƚ�� OR 9�� ���� Ƚ��) ;  ary[?] �� ����.

ary[?] < max(6�� ���� Ƚ�� OR 9�� ���� Ƚ��);
����)

��ȣ	6   9
Ƚ��	2   5   ;  3) 3  3    4)4  4
					  2  4      2  6  <= ������ 4��Ʈ.
������ X��Ʈ��� �ϴ� �ΰ�, ��������.
Y(����) = X��Ʈ -������(2)
Y(����)+������(2) = X��Ʈ
X��Ʈ + Y(����) >= (ū��)5?
X��Ʈ + (X��Ʈ- ������(2) ) >=(ū��)5?
2X > = (ū��)5+ ������(2)
X >= ((ū��)5+ ������(2)) / 2  �� ���� X�� ã��.


*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int ary[10];//�ε����� 0~ 9
int elsemaxv;
void In() {
	int a;

	while (~scanf("%1d", &a)) {
		ary[a]++;
		if (a != 6 && a != 9 &&  elsemaxv < ary[a]) { // 6,9 �� ������ ���߿��� �ִ� ����
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