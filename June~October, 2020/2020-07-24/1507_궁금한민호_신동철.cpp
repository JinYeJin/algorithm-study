#include <iostream>
using namespace std;
int N;
int dist[20][20],subst_dist[20][20];
int dist_or_subs(int i, int j) {
	if (dist[i][j] == 0)
		return subst_dist[i][j];
	else
		return dist[i][j];
}
int main() {
	//입력
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> dist[i][j];	subst_dist[i][j] = dist[i][j];
		}
	//계산
	for (int k = 0; k < N; k++)//경유
		for (int i = 0; i < N; i++)//시작점
			for (int j = 0; j < N; j++) {//도착점
				if (k != i && k != j && i != j ) {
					if(dist_or_subs(i,j) == (dist_or_subs(i,k) + dist_or_subs(k,j))) {
						dist[i][j] = 0; dist[j][i] = 0;
					}
					else if (dist_or_subs(i, j) > (dist_or_subs(i, k) + dist_or_subs(k, j))) {//불가능한 경우
						cout << -1;
						return 0;
					}
				}
			}
	int dist_sum = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			dist_sum += dist[i][j];
		}
	cout << (dist_sum / 2);
		
}