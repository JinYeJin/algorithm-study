//ŵ
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

string password;
int dp[5000];
int tb[5000];
void In() {
	cin >> password;
}
bool range_check(int value) {
	if (1 <= value && value <= 26)
		return true;
	else
		return false;
}
bool two_range_check(int value) {
	if (10 <= value && value <= 26)
		return true;
	else
		return false;
}
void func() {
	int size = password.length();//��ȣ�� ����
	int num = 0;
	for (int tp = 0; tp < size; tp++) {
		int a=0;
		//1ĭ�˻�  
		//1~26������ �� ���   ��� 1~9������ �ص� ����
		if (range_check(password[tp] - '0')) {
			dp[tp]++;
			
			if (tp > 0) {
				if(tp==1)
					num = dp[tp - 1];
				num = num * dp[tp] + tb[tp];
			}
			
		}
		else//0 �� ���   tb[tp]������ 
		{
			if (tb[tp] == 0) {
				cout << 0;
				return;
			}
			num = tb[tp];
			/*a = tb[tp];
			*/
		}
		
	
		//2ĭ�˻�
		if (two_range_check(atoi((password.substr(tp, 2)).c_str())))
		{
			tb[tp]++;
		}
		else // 00 ~ 09   , 27~ �ΰ��   
		{
			tb[tp] = 0;
		}
	}

}
int main() {
	In();

	func();
}