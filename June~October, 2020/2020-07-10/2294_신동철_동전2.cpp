//고군분투끝에 성공.ㅡㅡ;
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, k;
int minv= 10001;
vector<int> value_vec;

bool check[10001];//동전가치 존재여부
int dp[101][10001];//첫번재 인덱스는 자릿수를 의미(1~100)  , 두번째 인덱스는 목표값을 의미(1~10000)  값은 사용된 동전의갯수
void In() {
	cin >> n >> k;
	int a;
	for (int tp = 1; tp <= n; tp++) {
		cin >> a;
		if (a <= k  && check[a]==false) //받는값이 k보다 작은경우 ,  그리고  check에 처음 들어오는경우     //의혹 사용한 동전의 구성이 같은데, 순서만 다른 것은 같은 경우이다.
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

	//최소값갱신
	if (dp[1][k] != -1)
		minv = dp[1][k];

	//자릿수
	for (int tp1 = 2; tp1 <= value_vec.size(); tp1++) {
		//목표
		for (int goal = 1; goal <= k; goal++) {
			int tp2 = goal / value_vec[tp1 - 1];
			int local_min = 10001;
			//temp정해서 반복
			for (int temp = 0; temp <= tp2; temp++) {
				int spare = goal - temp * value_vec[tp1 - 1];

				if (spare!=0 && dp[tp1 - 1][spare] == -1)
					continue;
				
				if(spare==0)
					local_min = ((temp + 0) < local_min) ? (temp + 0) : local_min;
				else
					local_min = (  (temp + dp[tp1 - 1][spare]) < local_min) ? (temp + dp[tp1 - 1][spare]) : local_min;
			}
			//예외처리
			if (local_min == 10001)
				dp[tp1][goal] = -1;
			else {
				dp[tp1][goal] = local_min;
				//동시에 정답 최솟값 갱신
				if (goal == k) 
					minv = (dp[tp1][goal] < minv) ? dp[tp1][goal] : minv;
	
			}
		}
	}

	
}
int main()
{
	ios_base::sync_with_stdio(false);//144ms 나옴
	In();

	//입력받은것의 갯수가 (조건을만족하지못해서) 0인경우 -1출력
	if ((int)value_vec.size() == 0) {
		cout << -1;
	}
	else {
		sort(value_vec.begin(), value_vec.end(), less<int>());

		memset(dp, -1, sizeof(dp));//-1로 초기화

		func();

		if (minv == 10001)
			cout << -1;
		else
			cout << minv;
	}

}