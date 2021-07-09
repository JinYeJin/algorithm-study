#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int N,K,arr[100],answer=0;
	set<int> con;
	cin>>N>>K;
	for (int k = 0; k < K; k++) {
		cin>>arr[k];
	}
	for (int k = 0; k < K; k++) {
		if (con.size() < N) {
			con.insert(arr[k]);
			continue;
		}
		if(con.find(arr[k])!=con.end()) continue;
		set<int> con_copy(con);
		for (int i = k; i < K; i++) {
			con_copy.erase(arr[i]);
			if(con_copy.size()==1) break;
		}
		answer++;
		con.erase(*con_copy.begin());
		con.insert(arr[k]);
	}
	cout<<answer;
}

