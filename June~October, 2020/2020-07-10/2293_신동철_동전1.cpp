//�˰���ٽúм��ʿ�����. �ѹ�����
/*
�����ּ� - >https://debuglog.tistory.com/78
Dynamic Programming���� �����Ѵ�.

ù ��° ������ ����Ͽ� �� k�� ���� ������ ����� ���� ã�´�.

ù ��°~�� ��° ������ ����Ͽ��� ��, ��k �� ���� ������ ����� ���� ã�´�.�� ��, ù ��° ������ ����ؼ� ���ߴ� ����� ���� Ȱ���Ѵ�.

ù ��°~n ��° ������ ����Ͽ��� ������ �ݺ��Ѵ�.
*/
//����
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, k;
int x;
vector<int> value_vec;

int dp_before[10001]; //�ι�° �ε����� ��ǥ��
int dp_now[10001];// �ι�° �ε����� ��ǥ��
void In() {
	cin >> n >> k;
	int a;
	int temp = n;
	for (int tp = 1; tp <= temp; tp++) {
		cin >> a;
		if (a <= k) //�޴°��� k���� ū���� �Ÿ���.
			value_vec.push_back(a);
		else
			n--;
	}
}
void func() {
	//1�ڸ����ϰ��
	for (int tp = value_vec[0]; tp <= k; tp++) {
		if (tp%value_vec[0] == 0)
			dp_before[tp] = 1;
	}

	//���ڸ��� �ϰ�� ����ó��
	if (value_vec.size() == 1) {
		if (k%value_vec[0] == 0)
			cout << 1;
		else
			cout << 0;
		return;
	}


	//2�ڸ��� �̻��ϰ��
	for (int num = 1; num <= n-1; num++) //num�� �ڸ��� �ε� value_vec������ num�� 1���� ������
	{

		int tp1 = (num==n-1)? k :1;
		for (; tp1 <= k; tp1++)//Dp[num][tp1]�뵵
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

	//�Է¹������� ������ (�����������������ؼ�) 0�ΰ�� 0���
	if ( (int)value_vec.size() == 0) {
		cout << 0;
	}
	else {
		sort(value_vec.begin(), value_vec.end(), less<int>());

		func();

	}

}