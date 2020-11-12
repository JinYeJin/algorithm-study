//���������� ����.�Ѥ�;
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, k;
int minv= 10001;
vector<int> value_vec;

bool check[10001];//������ġ ���翩��
int dp[101][10001];//ù���� �ε����� �ڸ����� �ǹ�(1~100)  , �ι�° �ε����� ��ǥ���� �ǹ�(1~10000)  ���� ���� �����ǰ���
void In() {
	cin >> n >> k;
	int a;
	for (int tp = 1; tp <= n; tp++) {
		cin >> a;
		if (a <= k  && check[a]==false) //�޴°��� k���� ������� ,  �׸���  check�� ó�� �����°��     //��Ȥ ����� ������ ������ ������, ������ �ٸ� ���� ���� ����̴�.
		{
			value_vec.push_back(a);
			check[a] = true;
		}
	}
}
void func() {
	
	for (int tp2 = 1; tp2 <= k; tp2++) {
		int a = tp2 / value_vec[0];
		int b = tp2 % value_vec[0];

		if (b == 0 && a >= 1)
			dp[1][tp2] = a;
		else
			dp[1][tp2] = -1;
	}

	//�ּҰ�����
	if (dp[1][k] != -1)
		minv = dp[1][k];

	//�ڸ���
	for (int tp1 = 2; tp1 <= value_vec.size(); tp1++) {
		//��ǥ
		for (int goal = 1; goal <= k; goal++) {
			int tp2 = goal / value_vec[tp1 - 1];
			int local_min = 10001;
			//temp���ؼ� �ݺ�
			for (int temp = 0; temp <= tp2; temp++) {
				int spare = goal - temp * value_vec[tp1 - 1];

				if (spare!=0 && dp[tp1 - 1][spare] == -1)
					continue;
				
				if(spare==0)
					local_min = ((temp + 0) < local_min) ? (temp + 0) : local_min;
				else
					local_min = (  (temp + dp[tp1 - 1][spare]) < local_min) ? (temp + dp[tp1 - 1][spare]) : local_min;
			}
			//����ó��
			if (local_min == 10001)
				dp[tp1][goal] = -1;
			else {
				dp[tp1][goal] = local_min;
				//���ÿ� ���� �ּڰ� ����
				if (goal == k) 
					minv = (dp[tp1][goal] < minv) ? dp[tp1][goal] : minv;
	
			}
		}
	}

	
}
int main()
{
	ios_base::sync_with_stdio(false);//144ms ����
	In();

	//�Է¹������� ������ (�����������������ؼ�) 0�ΰ�� -1���
	if ((int)value_vec.size() == 0) {
		cout << -1;
	}
	else {
		sort(value_vec.begin(), value_vec.end(), less<int>());

		memset(dp, -1, sizeof(dp));//-1�� �ʱ�ȭ

		func();

		if (minv == 10001)
			cout << -1;
		else
			cout << minv;
	}

}