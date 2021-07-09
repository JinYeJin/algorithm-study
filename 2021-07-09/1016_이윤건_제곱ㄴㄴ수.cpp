#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

int main()
{
	long long MIN, MAX;
	bool not_prime[999998]={1,1};
	vector<long long> sq_prime;

	for (int i = 2; i < 1001; i++) {
		if(not_prime[i]) continue;
		sq_prime.push_back((long long)i*i);
		for (int j = i * i; j < 999998; j += i) {
			not_prime[j]=1;
		}
	}
	for (int i = 1001; i < 999998; i++) {
		if(!not_prime[i]) sq_prime.push_back((long long)i*i);
	}
	set<long long> 제곱ㅇㅇ수;
	cin>>MIN>>MAX;
	for (auto temp:sq_prime){
		for (long long i = (MIN - 1) / temp + 1; i <= MAX / temp; i++) {
			제곱ㅇㅇ수.insert(i*temp);
		}
	}
	cout<<MAX-MIN+1-제곱ㅇㅇ수.size();
}

