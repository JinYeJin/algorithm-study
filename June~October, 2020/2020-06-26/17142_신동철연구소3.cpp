//dfs, bfs로 해결
// dfs 잘짜야 한다는 것을 한번더 느낌.
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int map[50][50];
int wall_num;
vector<pair<int, int>> pos_virus_vec;
vector<pair<int, int>> selected_virus;
int dist[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int check[50][50];
int min_day = 2500;

//테스트용
int cntx = 0;
//
void In() {
	cin >> N >> M;

	for(int i=0; i<N ; i++)
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				pos_virus_vec.push_back(pair<int,int>(i,j));
			else if (map[i][j] == 1)
				wall_num++;
		}
}
bool isinside(int i, int j) {
	if (i >= 0 && i < N && j >= 0 && j < N)
		return true;
	else
		return false;
}
int bfs() {
	int accumulated_virus = 0;
	int maxv = 0;
	queue<pair<int, int>> qu;
	vector<pair<int, int>>::iterator iter;
	for (iter = selected_virus.begin(); iter != selected_virus.end(); iter++) {
		qu.push(pair<int, int>((*iter).first, (*iter).second));
		check[(*iter).first][(*iter).second] = 0;//선택된 바이러스는 0 을 삽입       선택안된바이러스는 그대로 -1 임.       map에서는 둘다 2임.
	}
	
	while (!qu.empty()) {
		int curi = qu.front().first;
		int curj = qu.front().second;
		qu.pop();

		//중간탈출문  시간단축
		if (min_day < maxv)
			return 0;

		for (int tp = 0; tp < 4; tp++) {
			int nexti = curi + dist[tp][0];
			int nextj = curj + dist[tp][1];

			//범위 안에 있는가 , 처음 방문하는 곳인가 , 벽이아닌가
			if (isinside(nexti, nextj) && check[nexti][nextj] == -1 && map[nexti][nextj] != 1) {
				
				//빈칸 or 비활성화된 바이러스 일경우
				check[nexti][nextj] = check[curi][curj] + 1;

				if (map[nexti][nextj] == 0)
				{
					accumulated_virus++; //빈칸일 때만 바이러스 축적
					if (maxv < check[nexti][nextj]) //바이러스 퍼지는 날짜 갱신    비활성바이러스는 갱신에서 예외함.
						maxv = check[nexti][nextj];
				}
				qu.push(pair<int, int>(nexti,nextj ));
			
			}

		}
	}

	int b = N * N - (wall_num + (int)pos_virus_vec.size() + accumulated_virus);
	if (b != 0)//바이러스가 퍼졌는데도 불구하고 빈칸이 존재한다는 말임
		return -1;
	else
		return maxv;
}
void dfs(int index) {
	//검사
	if ((int)selected_virus.size() == M)
	{
		int value;
		value= bfs();
		//최적값갱신     value==0 인 것의 의미는 중간탈출문에 의해서 탈출된 것임
		if (value != 0 && value != -1) {
			if (min_day > value)
				min_day = value;
		}

		//초기화  check
		memset(check, -1, sizeof(check));
		return;
	}

	//진행
	for (int tp = 0 + index; tp < (int)pos_virus_vec.size(); tp++) {
		selected_virus.push_back(pos_virus_vec[tp]);
		dfs(tp+1);   // 역시 dfs 처리과정을  잘처리해야함. 이것 때문에 한번 틀렸었음.
		//복원
		selected_virus.pop_back();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);// 12ms
	cin.tie(NULL);
	cout.tie(NULL);

	memset(check, -1, sizeof(check));
	In();
	//예외처리
	if ((N * N - (wall_num + (int)pos_virus_vec.size())) == 0) {
		cout << '0';
		return 0;
	}
	dfs(0);

	if (min_day == 2500)
		cout << -1;
	else
		cout << min_day;
}