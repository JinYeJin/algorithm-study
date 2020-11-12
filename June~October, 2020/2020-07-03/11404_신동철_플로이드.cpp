#include <iostream>

using namespace std;

int n,m;//도시의 갯수, 버스의 개수
int dist[101][101];
void In() {
	cin >> n >> m;
	int a, b, c;
	for (int tp = 1; tp <= m; tp++) {
		cin >> a >> b >> c;
		//map[a][b]값이 0 or c<map[a][b]
		if(dist[a][b]==0 || c< dist[a][b])
			dist[a][b] = c;
	}
}
bool no_repeat(int tp1,int tp2, int tp3) {
	if (tp1 == tp2 || tp1 == tp3 || tp2 == tp3)
		return false;
	else
		return true;
}
bool exist(int tp1,int tp2,int tp3) {
	if (dist[tp2][tp1] != 0 && dist[tp1][tp3] != 0 )
		return true;
	else
		return false;
}
void floid() {
	//거쳐가는 곳
	for(int tp1=1; tp1<=n  ; tp1++)
		//x에서 출발 하여
		for (int tp2 = 1; tp2 <= n; tp2++)
			//y에 도착
			for (int tp3 = 1; tp3 <= n; tp3++) {
				//중복 제외 , 값이 존재하는가 
				if (no_repeat(tp1, tp2, tp3) && exist(tp1,tp2,tp3) ) {
					if (dist[tp2][tp3] == 0)//다이렉트로 가는게 0이라면
					{
						dist[tp2][tp3] = dist[tp2][tp1] + dist[tp1][tp3];
						continue;
					}
					if (dist[tp2][tp1] + dist[tp1][tp3] < dist[tp2][tp3])
						dist[tp2][tp3]=dist[tp2][tp1] + dist[tp1][tp3];
				}
			}
}
int main() {
	ios_base::sync_with_stdio(false);//92->24ms
	In();
	floid();

	//출력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}
}