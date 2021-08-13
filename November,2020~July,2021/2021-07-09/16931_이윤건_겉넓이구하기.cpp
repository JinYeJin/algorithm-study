#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int board[101][101]={0},N,M,answer=0;
	cin>>N>>M;
	for (int i = 0; i < N; i++) {
        int pre=0;
		for (int j = 0; j < M; j++) {
			cin>>board[j][i];
            answer+=abs(board[j][i]-pre);
			pre=board[j][i];
		}
        answer+=pre;
	}
	for (int i = 0; i < M; i++) {
		int pre = 0;
		for (int j = 0; j <= N; j++) {
			answer+=abs(board[i][j]-pre);
			pre=board[i][j];
		}
	}
	answer+=N*M*2;
	cout<<answer;
}

