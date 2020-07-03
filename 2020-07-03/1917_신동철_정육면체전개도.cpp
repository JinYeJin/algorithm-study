//메모리초과  실패.
//알고리즘이 도저히 떠오르지 않아서 https://blog.naver.com/newprog/221863627726 여기에서 힌트를 얻음
//어떤 면이 있을때 같은 방향으로 두번 접힐때의 면이  마주보는 면이다. <- 이걸이용
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

class coord {
public:
	int i, j;
	coord(int i_,int j_) :i(i_),j(j_) {}
};

int map1[6][6];
int map2[6][6];
int map3[6][6];
int dist[4][2] = { {0,1},{0,-1},{1,0},{-1,0} }; //우 , 좌 , 하 , 상
bool check[6][6];//음
bool bcheck[6][6];//음
queue<coord> qu1,qu2,qu3;


void In() {
	for(int i=0; i<=5 ; i++)
		for (int j = 0; j <= 5; j++) {
			cin >> map1[i][j];
			if (map1[i][j] == 1)
				qu1.push(coord(i,j));
		}
		
	for (int i = 0; i <= 5; i++)
		for (int j = 0; j <= 5; j++) {
			cin >> map2[i][j];
			if (map2[i][j] == 1)
				qu2.push(coord(i, j));
		}

	for (int i = 0; i <= 5; i++)
		for (int j = 0; j <= 5; j++) {
			cin >> map3[i][j];
			if (map3[i][j] == 1)
				qu3.push(coord(i, j));
		}
}
bool isinside(int i, int j) {
	if (i >= 0 && i <= 5 && j >= 0 && j <= 5)
		return true;
	else
		return false;
}
int bfs(int i,int j,int map_[][6]) {

	int cnt = 0;

	//bcheck검사
	if (bcheck[i][j] == true)
		return 0;

	//첫부분은 방문함으로 표시
	check[i][j] = true;//이미 방문함으로 표시
	bcheck[i][j] = true;

	//bfs 진행을 위한 qu
	queue<coord> qu;

	//시작하는 면의 접히는 방향검사 및 초기화
	int way[4] = {0,};

	for (int tp = 0; tp < 4; tp++) {  //시작하는 면에서 접히는 방향 알아내기
		int nexti = i + dist[tp][0];
		int nextj = j + dist[tp][1];

		//범위 에있는가 , 값이 있는가
		if (isinside(nexti,nextj) &&map_[nexti][nextj] == 1) {
			way[tp]++; //접히는 방향은 1으로 처리됨.
			qu.push(coord(nexti, nextj));
			check[nexti][nextj] = true;
		}
	}

	
	//bfs로 퍼지되, way[?] 값이 0인 것은 큐에 담고, wav[?]값이 1인경우 또 그 방향으로 만났을때 그게 접혀지는것임.
	while (!qu.empty()) {
		int curi = qu.front().i;
		int curj = qu.front().j;
		qu.pop();

		for (int tp = 0; tp < 4; tp++) {
			int nexti = curi + dist[tp][0];
			int nextj = curj + dist[tp][1];


			//범위 안인가, 처음 방문하는 곳인가, 값이 있는가
			if (isinside(nexti, nextj) && check[nexti][nextj] == false && map_[nexti][nextj] == 1)
			{
				//tp 방향에서 way[tp]값이1 인경우 
				if (way[tp] == 1) {
					cnt++;
					check[nexti][nextj] = true;//방문함으로 표시
					//way[tp]가 1 인  nexti,nextj 값이 bcheck에서 처음방문 하는 값이라면
					if (bcheck[nexti][nextj]==false) {
						bcheck[nexti][nextj] = true;
					}
					//면이 겹쳐 지는 경우임.
					else if (bcheck[nexti][nextj] == true) {
						cout << "no" << '\n';
						return 1;//정육면체가 아닐때 1출력
					}
					
					qu.push(coord(nexti, nextj)); 
				}
				else
					//else 라면 , 단순히 큐첨가후 방문했음표시
				{
					qu.push(coord(nexti, nextj));
					check[nexti][nextj] = true;
				}
			}
		}

	}
	if (cnt != 1) {
		cout << "no" << '\n';
		return 1;//정육면체가 아닐때 1출력
	}
	else
		return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	In();
	int i;
	int j;
	while (!qu1.empty()) {
		int a=bfs(qu1.front().i, qu1.front().j, map1);
		qu1.pop();

		if (a == 1)
			break;
		if (qu1.size() == 0)
			cout << "yes"<<'\n';
	}
	memset(bcheck, 0, sizeof(bcheck));//check초기화


	while (!qu2.empty()) {
		memset(check, 0, sizeof(check));//check초기화
		int a = bfs(qu2.front().i, qu2.front().j, map2);
		qu2.pop();

		if (a == 1)
			break;
		if (qu2.size() == 0)
			cout << "yes" << '\n';
	}
	memset(bcheck, 0, sizeof(bcheck));//check초기화

	while (!qu3.empty()) {
		memset(check, 0, sizeof(check));//check초기화
		int a = bfs(qu3.front().i, qu3.front().j, map3);
		qu3.pop();

		if (a == 1)
			break;
		if (qu3.size() == 0)
			cout << "yes" << '\n';
	}
}

/*
42퍼
//알고리즘이 도저히 떠오르지 않아서 https://blog.naver.com/newprog/221863627726 여기에서 힌트를 얻음
//어떤 면이 있을때 같은 방향으로 두번 접힐때의 면이  마주보는 면이다. <- 이걸이용
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

class coord {
public:
	int i, j;
	coord(int i_,int j_) :i(i_),j(j_) {}
};

int map1[6][6];
int map2[6][6];
int map3[6][6];
int dist[4][2] = { {0,1},{0,-1},{1,0},{-1,0} }; //우 , 좌 , 하 , 상
int check[6][6];//음
bool bcheck[6][6];//음
queue<coord> qu1,qu2,qu3;

/*
class square_side {
public:
	int top, bottom, left, right;
	bool used;
	square_side(int top_, int bottom_, int left_, int right_): top(top_), bottom(bottom_), left(left_), right(right_),used(false){}
};
void create_side() {
	//top

	//bottom
	//left-side
	//right-side
	//top-side
	//bottom-side
}

void In() {
	for (int i = 0; i <= 5; i++)
		for (int j = 0; j <= 5; j++) {
			cin >> map1[i][j];
			if (map1[i][j] == 1)
				qu1.push(coord(i, j));
		}

	for (int i = 0; i <= 5; i++)
		for (int j = 0; j <= 5; j++) {
			cin >> map2[i][j];
			if (map2[i][j] == 1)
				qu2.push(coord(i, j));
		}

	for (int i = 0; i <= 5; i++)
		for (int j = 0; j <= 5; j++) {
			cin >> map3[i][j];
			if (map3[i][j] == 1)
				qu3.push(coord(i, j));
		}
}
bool isinside(int i, int j) {
	if (i >= 0 && i <= 5 && j >= 0 && j <= 5)
		return true;
	else
		return false;
}
int bfs(int i, int j, int map_[][6]) {

	//bcheck검사
	if (bcheck[i][j] == true)
		return 0;

	//bfs 진행을 위한 qu
	queue<coord> qu;
	qu.push(coord(i, j));
	check[i][j] = 2;//이미 방문함으로 표시
	bcheck[i][j] = true;

	//시작하는 면의 접히는 방향검사
	int way[4];
	memset(way, -1, sizeof(way));
	for (int tp = 0; tp < 4; tp++) {  //시작하는 면에서 접히는 방향 알아내기
		int nexti = i + dist[tp][0];
		int nextj = j + dist[tp][1];

		if (map_[nexti][nextj] == 1)
			way[tp]++; //접히는 방향은 0으로 처리됨.
	}

	bool flag = false;

	//bfs로 퍼지되, way[?] 값이 -1인 것은 무시하고, 접히는것을 만날때 마다 하나씩 증가하여 , 최초로 2가 되는 값이 접히는 값임.
	while (!qu.empty()) {
		int curi = qu.front().i;
		int curj = qu.front().j;
		qu.pop();

		for (int tp = 0; tp < 4; tp++) {
			int nexti = curi + dist[tp][0];
			int nextj = curj + dist[tp][1];


			//범위 안인가, 처음 방문하는 곳인가, 값이 있는가
			if (isinside(nexti, nextj) && check[nexti][nextj] == 0 && map_[nexti][nextj] == 1)
			{
				//way[tp]값이 -1이 아닌가 -> way증가 및 큐첨가
				if (way[tp] != -1) {
					way[tp]++;
					check[nexti][nextj] = 1;
					//way검사  flag포함 bcheck포함
					if (way[tp] == 2 && flag == false && bcheck[nexti][nextj] == false) {
						check[nexti][nextj] = 2;
						flag = true;
						bcheck[nexti][nextj] = true;
					}
					else if (way[tp] == 2 && flag == false && bcheck[nexti][nextj] == true) {
						cout << "no" << '\n';
						return 1;//정육면체가 아닐때 1출력
					}
					else if (way[tp] == 2 && flag == true) {
						cout << "no" << '\n';
						return 1;//정육면체가 아닐때 1출력
					}
					qu.push(coord(nexti, nextj));
				}
				else
					//else 라면 , 단순히 큐첨가후 방문했음표시
				{
					qu.push(coord(nexti, nextj));
					check[nexti][nextj] = 1;
				}
			}
		}

	}
	return 0;//정상적일때는 0출력
}
int main()
{
	ios_base::sync_with_stdio(false);
	In();
	int i;
	int j;
	while (!qu1.empty()) {

		int a = bfs(qu1.front().i, qu1.front().j, map1);
		qu1.pop();

		if (a == 1)
			break;
		memset(check, 0, sizeof(check));//check초기화
		if (qu1.size() == 0)
			cout << "yes" << '\n';
	}
	memset(bcheck, 0, sizeof(bcheck));//check초기화


	while (!qu2.empty()) {
		int a = bfs(qu2.front().i, qu2.front().j, map2);
		qu2.pop();

		if (a == 1)
			break;
		memset(check, 0, sizeof(check));//check초기화
		if (qu2.size() == 0)
			cout << "yes" << '\n';
	}
	memset(bcheck, 0, sizeof(bcheck));//check초기화

	while (!qu3.empty()) {
		int a = bfs(qu3.front().i, qu3.front().j, map3);
		qu3.pop();

		if (a == 1)
			break;
		memset(check, 0, sizeof(check));//check초기화
		if (qu3.size() == 0)
			cout << "yes" << '\n';
	}
}
*/