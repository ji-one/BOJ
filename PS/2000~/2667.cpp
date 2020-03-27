#include <bits/stdc++.h>
using namespace std;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; //x,y
int main(void)
{
	int n;
	cin >> n;

	int a[25][25];
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%1d", &a[i][j]);
		}
	}

	int cnt[625] = {0,}; //단지내 집의 수
	int ny, nx;
	int num = 0; //총 단지수
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 1)
			{
				a[i][j] = 0;
				q.push(make_pair(i, j));

				pair<int, int> current;

				while (!q.empty())
				{
					current = q.front();
					++cnt[num];
					q.pop();

					for (int k = 0; k < 4; k++)
					{
						ny = current.first + dir[k][1];
						nx = current.second + dir[k][0];

						if (ny >= 0 && nx >= 0 && ny < n && nx < n && a[ny][nx] == 1)
						{
							q.push(make_pair(ny, nx));
							a[ny][nx] = 0;
						}
					}
				}
				++num;
			}
		}
	}
	sort(cnt, cnt + num);
	cout << num << '\n';
	for (int i = 0; i < num; i++)
	{
		cout << cnt[i] << '\n';
	}
}
