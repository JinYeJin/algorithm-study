/*
연결요소의 갯수

연결요소의 갯수를 출력하는 문제
*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int N, M;
vector<int> vec[1001];//실사용 인덱스는 1~N
bool check[1001];//실사용 인덱스는 1~N
bool check_buf[1001];//실사용 인덱스는 1~N
int cnt = 0;
void In() {
	cin >> N >> M;
	int a,b;
	for (int tp = 1; tp <= M; tp++) {
		cin >> a >> b;
		vec[a].push_back(b);
	}
}
void dfs(int node) {
	//진행
	for (int tp = 0; tp < vec[node].size(); tp++) {
		int next = vec[node][tp];
		if (check_buf[next] == true)//사이클방지
			continue;
		check_buf[next] = true;
		dfs(next);
	}
}
int main() {
	ios_base::sync_with_stdio(false);//284ms->88ms
	In();

	//예외경우
	if (M == 0) { 
		cout << N;
		return 0;
	}

	for (int tp = 1; tp <= N; tp++) {
		vector<int> buf;

		if (check[tp] == false) {
			check_buf[tp] = true;//방문했음으로 표시
			dfs(tp);  //check_buf에서  tp에 속해있는 연결요소를 전부 true로 바꿔줌
			
			bool flag = false;
			for (int tp2 = 1; tp2 <= N; tp2++) {
				if (check_buf[tp2] == true && check[tp2] == true) 
					flag = true;
				else if(check_buf[tp2] == true)
					buf.push_back(tp2);
			}
			
			if (flag == false)  //겹치는게 없을경우에
				cnt++;

		
			vector<int>::iterator iter;
			for (iter = buf.begin(); iter != buf.end(); iter++) //check 값이 renewal됨
				check[(*iter)] = true;
			

			//초기화
			memset(check_buf, 0, sizeof(check_buf));
		}
		
	}

	cout << cnt;

	return 0;
}
