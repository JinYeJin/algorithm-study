//못풀어서 오른쪽주소에서 힌트봄 https://velog.io/@skyepodium/%EB%B0%B1%EC%A4%80-2617-%EA%B5%AC%EC%8A%AC-%EC%B0%BE%EA%B8%B0
/*
구슬찾기

//핵심개념.  어떤 구슬을 선택했을 때, 그 구슬보다 가벼운것의 갯수 or 그 구슬보다 무거운 것의 개수가   (N+1)/2 보다 크면 ,  그 구슬은 절대 중간 무게가 될수 없다.

무게가 중간인 구슬이 될 수 없는 구슬의 개수를 구하는 프로그램을 작성하시오.
*/
#include <iostream>
#include <vector>
using namespace std;
vector<int> vec[101];//인덱스는 가벼운것, 인덱스에 해당하는 값을 무거운것
vector<int> rvec[101];//인덱스는 무거운것, 인덱스에 해당하는 값을 가벼운것
bool check1[101];
bool check2[101];
int N, M;
int cnt, cnt2;
int answer=0;
int base;
void In() {
	cin >> N >> M;
	int a, b;
	for (int tp = 1; tp <= M; tp++) {
		cin >> a >> b;
		vec[b].push_back(a);
		rvec[a].push_back(b);
	}
}
void dfs(int node) {//node보다 무거운 것의 갯수를 cnt로 구함
	//진행
	for (int tp = 0; tp < vec[node].size(); tp++) {
		int next = vec[node][tp];
		if (check1[next] == true)
			continue;
		check1[next] = true;//방문함으로 표시
		cnt++;
		dfs(next);
	}
}
void rdfs(int node) {// node보다 가벼운 것의 갯수를 cnt2로 구함
	//진행
	for (int tp = 0; tp < rvec[node].size(); tp++) {
		int next = rvec[node][tp];
		if (check2[next] == true)
			continue;
		check2[next] = true;//방문함으로 표시
		cnt2++;
		rdfs(next);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	In();
	base = (N + 1) / 2; //중간 번호
	for (int tp = 1; tp <= N; tp++) {
		//초기화
		cnt = 0;
		cnt2 = 0;
		for (int tp2 = 1; tp2 <= N; tp2++) {
			check1[tp2] = false;
			check2[tp2] = false;
		}


		dfs(tp);
		if (cnt >= base) {
			answer++;
			continue;
		}
		rdfs(tp);
		if (cnt2 >= base) 
			answer++;		
	}

	cout << answer;
}
