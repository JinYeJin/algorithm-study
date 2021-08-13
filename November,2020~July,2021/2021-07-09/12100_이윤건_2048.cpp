#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int N,board[20][20],answer=0;

void left() {
	for (int i = 0; i < N; i++) {
		int sp = 0;
		for (int j = 1; j < N; j++) {
			if (board[i][j] == 0) {
				sp++;
				continue;
			}
			if (board[i][j-1-sp] == 0) {
				swap(board[i][j], board[i][j-1-sp]);
				sp++; //다음께 합쳐질 가능성이 있기 때문에
				continue;
			}
			if (board[i][j] == board[i][j-1-sp]) {
				board[i][j-1-sp]*=2;
				board[i][j]=0;
				answer = max(answer, board[i][j - 1 - sp]);
			}
			else{
				swap(board[i][j],board[i][j-sp]);
			}
		}
	}
}
void right() {
	for (int i = 0; i < N; i++) {
		int sp = 0;
		for (int j = N-2; j >=0; j--) {
			if (board[i][j] == 0) {
				sp++;
				continue;
			}
			if (board[i][j + 1 + sp] == 0) {
				swap(board[i][j], board[i][j + 1 + sp]);
				sp++; //다음께 합쳐질 가능성이 있기 때문에
				continue;
			}
			if (board[i][j] == board[i][j + 1 + sp]) {
				board[i][j + 1 + sp] *= 2;
				board[i][j] = 0;
				answer = max(answer, board[i][j + 1 + sp]);
			}
			else {
				swap(board[i][j], board[i][j + sp]);
			}
		}
	}
}
void up() {
	for (int i = 0; i < N; i++) {
		int sp = 0;
		for (int j = 1; j < N; j++) {
			if (board[j][i] == 0) {
				sp++;
				continue;
			}
			if (board[j - 1 - sp][i] == 0) {
				swap(board[j][i], board[j - 1 - sp][i]);
				sp++;
				continue;
			}
			if (board[j][i] == board[j - 1 - sp][i]) {
				board[j - 1 - sp][i] *= 2;
				board[j][i] = 0;
				answer = max(answer, board[j - 1 - sp][i]);
			}
			else {
				swap(board[j][i], board[j - sp][i]);
			}
		}
	}
}
void down() {
	for (int i = 0; i < N; i++) {
		int sp = 0;
		for (int j = N - 2; j >= 0; j--) {
			if (board[j][i] == 0) {
				sp++;
				continue;
			}
			if (board[j + 1 + sp][i] == 0) {
				swap(board[j][i], board[j + 1 + sp][i]);
				sp++; //다음께 합쳐질 가능성이 있기 때문에
				continue;
			}
			if (board[j][i] == board[j + 1 + sp][i]) {
				board[j + 1 + sp][i] *= 2;
				board[j][i] = 0;
				answer = max(answer, board[j + 1 + sp][i]);
			}
			else {
				swap(board[j][i], board[j + sp][i]);
			}
		}
	}
}
void print_board() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout<<board[i][j];
		}cout<<'\n';
	}
}

void dfs(int n) {
	if(n==0) return;
	int board_copy[20][20];
	memcpy(board_copy,board, sizeof(board));
	left(); dfs(n - 1); memcpy(board, board_copy, sizeof(board));
	right(); dfs(n - 1); memcpy(board, board_copy, sizeof(board));
	up(); dfs(n - 1); memcpy(board, board_copy, sizeof(board));
	down(); dfs(n - 1); memcpy(board, board_copy, sizeof(board));
}

int main()
{
	cin>>N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin>>board[i][j];
            answer=max(answer,board[i][j]);
		}
	}
	dfs(5);
	cout<<answer;
}

