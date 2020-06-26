#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;
int N, M;
int cnt;
map<string, int> info_map;
void func() {
	cin >> N >> M;
	string k;
	for (int tp = 1; tp <= N; tp++)
	{
		cin >> k;
		info_map[k] = 1;
	}

	for (int tp = 1; tp <= M; tp++)
	{
		cin >> k;
		if (info_map[k] == 1) {
			cnt++;
			info_map[k] = 2;
		}
	}

	cout << cnt<< '\n';
	
	map<string, int>::iterator iter;
	for (iter = info_map.begin(); iter != info_map.end(); iter++) {
		if ((*iter).second == 2)
			cout << (*iter).first << '\n';
	}

}
int main()
{
	ios_base::sync_with_stdio(false);// 120ms -> 60ms
	func();
}