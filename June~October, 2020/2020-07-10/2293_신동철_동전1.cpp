//알고리즘다시분석필요있음. 한번실패
/*
참고주소 - >https://debuglog.tistory.com/78
Dynamic Programming으로 접근한다.

첫 번째 동전만 사용하여 각 k값 마다 가능한 경우의 수를 찾는다.

첫 번째~두 번째 동전만 사용하였을 때, 각k 값 마다 가능한 경우의 수를 찾는다.이 때, 첫 번째 동전만 사용해서 구했던 경우의 수를 활용한다.

첫 번째~n 번째 동전을 사용하였을 때까지 반복한다.
*/
//성공
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, k;
int x;
vector<int> value_vec;

int dp_before[10001]; //두번째 인덱스는 목표값
int dp_now[10001];// 두번째 인덱스는 목표값
void In() {
	cin >> n >> k;
	int a;
	int temp = n;
	for (int tp = 1; tp <= temp; tp++) {
		cin >> a;
		if (a <= k) //받는값이 k보다 큰경우는 거른다.
			value_vec.push_back(a);
		else
			n--;
	}
}
void func() {
	//1자리수일경우
	for (int tp = value_vec[0]; tp <= k; tp++) {
		if (tp%value_vec[0] == 0)
			dp_before[tp] = 1;
	}

	//한자리수 일경우 예외처리
	if (value_vec.size() == 1) {
		if (k%value_vec[0] == 0)
			cout << 1;
		else
			cout << 0;
		return;
	}


	//2자리수 이상일경우
	for (int num = 1; num <= n-1; num++) //num은 자릿수 인데 value_vec때문에 num을 1부터 시작함
	{

		int tp1 = (num==n-1)? k :1;
		for (; tp1 <= k; tp1++)//Dp[num][tp1]용도
		{
			int temp = tp1 / value_vec[num];
			int local_value = 0;
			for (int tp2=0; tp2<= temp; tp2++ )
			{
				int left_value = tp1 - tp2 * value_vec[num];
				if (left_value == 0)
					local_value++;
				else 
					local_value += dp_before[left_value];
			}
			dp_now[tp1] = local_value;

		}
		if (num == n - 1)
			cout << dp_now[k];
		copy(dp_now, dp_now + 10001, dp_before);
		memset(dp_now, 0, sizeof(dp_now));
		
	}

}
int main()
{
	In();

	//입력받은것의 갯수가 (조건을만족하지못해서) 0인경우 0출력
	if ( (int)value_vec.size() == 0) {
		cout << 0;
	}
	else {
		sort(value_vec.begin(), value_vec.end(), less<int>());

		func();

	}

}