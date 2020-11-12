/*
적록색약 문제

적록색약이 아닌 사람이 봤을 때의 구역의 개수와 적록색약인 사람이 봤을 때의 구역의 수를 공백으로 구분해 출력
*/
#include <iostream>
#include <queue>

using namespace std;

int N;
char ary1[100][100];
char ary2[100][100];
int dist[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
bool check1[100][100];
bool check2[100][100];
int cnt1 = 0;
int cnt2 = 0;
void In() {
	cin >> N;
	char a;
	for( int i=0; i<N ; i++ )
		for (int j = 0; j < N; j++)
		{
			cin >> a;
			ary1[i][j] = a;
			if (a == 'G')//G를 전부 R로 통일
				ary2[i][j] = 'R';
			else
				ary2[i][j] = a;
		}
}
bool isinside(int i, int j)
{
	if (i >= 0 && i < N && j >= 0 && j < N)
		return true;
	else
		return false;
}
void bfs(int i ,int j,char ary[][100],bool check[][100]) {
	queue<pair<int, int>> qu;
	qu.push(pair<int, int>(i, j));
	check[i][j] = true;//방문 했음으로 표시

	while (!qu.empty()) {
		int curi = qu.front().first;
		int curj = qu.front().second;
		qu.pop();
		for (int tp = 0; tp < 4; tp++) {
			int nexti = curi + dist[tp][0];
			int nextj = curj + dist[tp][1];

			//범위안에 있는가, 처음방문하는 곳인가 ,  (curi,curj)에 속해있는 값과 같은 값인가
			if (isinside(nexti, nextj) && check[nexti][nextj] == false && ary[curi][curj] == ary[nexti][nextj]) {
				check[nexti][nextj] = true;//이미 방문 했음으로 표시
				qu.push(pair<int,int>(nexti,nextj));
			}
			
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	In();
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {

			if (check1[i][j] == false) {
				bfs(i,j,ary1,check1);
				cnt1++;
			}

			if (check2[i][j] == false) {
				bfs(i, j,ary2,check2);
				cnt2++;
			}
		}

	cout << cnt1 << ' ' << cnt2;
}
