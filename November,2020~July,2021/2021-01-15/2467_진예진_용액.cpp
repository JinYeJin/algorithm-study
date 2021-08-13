#include <iostream>
using namespace std;

int N;
int solution[100002];
int acid, alkali;

int main() {
    FILE *stream = freopen("S2//28//input//2467.txt", "r", stdin);
    if(!stream) perror("freopen");
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> solution[i];
	}

	int left = 0;
	int right = N - 1;

	int answer = abs(solution[left] + solution[right]);
	acid = solution[left];
	alkali = solution[right];

	while (left < right) {
		int temp = solution[left] + solution[right];
        int temp_answer = abs(temp);
        
		if (temp_answer < answer) {
			answer = temp_answer;
			acid = solution[left];
			alkali = solution[right];
		}

		if (temp < 0) left++;
		else right--;
	}

	cout << acid << " " << alkali << "\n";
}
