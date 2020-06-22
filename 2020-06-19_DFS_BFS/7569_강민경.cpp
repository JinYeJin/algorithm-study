// https://www.acmicpc.net/problem/7569
// 토마토 7569 (3차원)

// 참고 https://www.crocus.co.kr/979

/*
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<pair<int, int>, pair<int, int> > pii;

int arr[102][102][102];
bool visit[102][102][102];

int dz[6] = { 1, 0, 0, 0, 0, -1, };
int dy[6] = { 0, 1, 0, -1, 0, 0 };
int dx[6] = { 0, 0, 1, 0, -1, 0 };

int main()
{
	int m, n, h, tomato = 0;
	scanf("%d %d %d", &n, &m, &h);

	for (int i = 0; i < h; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < n; k++)
			{
				scanf("%d", &arr[i][j][k]);
				if (arr[i][j][k] == 0)
					tomato++;
			}

	// 1 : 익음, 0 : 안익음, -1 : 없음
	int day = 0;
	queue<pii> q;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < n; k++)
				if (arr[i][j][k] == 1)
					q.push({ { 0,i },{ j,k } });

	int tmpTomato = 0;
	while (!q.empty())
	{
		int tday = q.front().first.first;
		int z = q.front().first.second;
		int y = q.front().second.first;
		int x = q.front().second.second;

		q.pop();

		if (visit[z][y][x])
			continue;

		day = max(day, tday);

		if (arr[z][y][x] == 0)
			tmpTomato++;

		arr[z][y][x] = 1;
		visit[z][y][x] = true;

		for (int i = 0; i < 6; i++)
		{
			int dZ = dz[i] + z;
			int dY = dy[i] + y;
			int dX = dx[i] + x;

			// 범위를 벗어나면
			if (!(0 <= dZ && dZ < h && 0 <= dY && dY < m && 0 <= dX && dX < n))
				continue;

			// 해당 구역이 0이 아니면
			if (arr[dZ][dY][dX] != 0)
				continue;

			q.push({ {tday + 1,dZ}, {dY, dX} });
		}
	}

	if (tmpTomato == tomato)
		printf("%d", day);
	else
		printf("-1");
	return 0;
}

*/
