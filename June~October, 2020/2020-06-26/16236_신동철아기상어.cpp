//최단거리 탐색문제여서 BFS로 해결.
#include <iostream>
#include <queue>
#include <deque>
#include <cstring>
using namespace std;
int N;
int map[20][20];
int fish = 0;
queue<pair<int, int>> qu;
deque<pair<int, int>> fish_dq;
int dist[4][2] = { {-1,0},{0,-1},{0,1},{1,0} };//상 , 좌 , 우, 하    이걸로 조건을 만족시켰을까.  의혹
int check[20][20];
int cnt_sum = 0;
void In() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 9) {
				fish++;
				fish_dq.push_back(pair<int, int>(i, j));
			}
			if (map[i][j] == 9) {
				map[i][j] = 0;// 여기서 계속틀렸음. 
				qu.push(pair<int, int>(i, j));
			}
		}
}
bool isinside(int i, int j) {
	if (i >= 0 && i < N && j >= 0 && j < N)
		return true;
	else
		return false;
}
void bfs() {
	int shark_i = qu.front().first;
	int shark_j = qu.front().second;
	int shark_size = 2;
	int cnt = 2;
	int min_dist = 400;
	check[shark_i][shark_j] = 0;


	do {
		min_dist = 400;

		//예외처리) 남은 물고기수가 0일때 종료
		if (fish == 0)
			return;

		while (!qu.empty()) {
			int curi = qu.front().first;
			int curj = qu.front().second;
			qu.pop();

			for (int tp = 0; tp < 4; tp++) {
				int nexti = curi + dist[tp][0];
				int nextj = curj + dist[tp][1];

				//범위 안에 있는지, 처음방문 하는곳인지 , 아기상어의 크기가 물고기이상일 경우
				if (isinside(nexti, nextj) && check[nexti][nextj] == -1 && shark_size >= map[nexti][nextj]) {
					//물고기를 먹을 수도 있는 경우
					if ((map[nexti][nextj] != 0) && (shark_size > map[nexti][nextj])) {

						check[nexti][nextj] = check[curi][curj] + 1;
						qu.push(pair<int, int>(nexti, nextj));
						if (min_dist > check[nexti][nextj])//최소값 갱신
							min_dist = check[nexti][nextj];
					}

					//물고기를 안먹을 경우 , 빈칸일 경우
					else {
						check[nexti][nextj] = check[curi][curj] + 1;
						qu.push(pair<int, int>(nexti, nextj));
					}
				}
			}
		}
		//거리가 가장가까운게 동일 할경우를 처리하기위해서 가장왼쪽 가장위부터 검사한다.
		deque<pair<int, int>>::iterator iter;
		for (iter = fish_dq.begin(); iter != fish_dq.end(); iter++) {
			int i = (*iter).first;
			int j = (*iter).second;
			if (min_dist == check[i][j] && map[i][j] < shark_size) {
				cnt--;
				fish--;
				cnt_sum += min_dist;
				if (cnt == 0) {
					shark_size++;
					cnt = shark_size;
				}

				map[i][j] = 0;
				memset(check, -1, sizeof(check));
				check[i][j] = 0;
				qu.push(pair<int, int>(i, j));
				fish_dq.erase(iter);//, fish_dq에 해당좌표지우기

				break;

			}
		}

	} while (min_dist != 400);

}
int main()
{
	ios_base::sync_with_stdio(false);
	In();
	//초기화
	memset(check, -1, sizeof(check));
	bfs();
	cout << cnt_sum;
}