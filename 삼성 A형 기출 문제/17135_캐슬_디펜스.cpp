#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int a[15][15];
int init[15][15];
int n, m, d;
int rst = 0;
vector<int> v;//궁수의 위치

void move() //적 아래로 한 칸 이동
{
	int tmp[15][15];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == 0) tmp[i][j] = 0;
			else
			{
				tmp[i][j] = a[i - 1][j];
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			a[i][j] = tmp[i][j];
		}
	}


/*	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << a[i][j];
		}
		cout << '\n';
	}*/

}

//공격
int attack()
{

	int num = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			a[i][j] = init[i][j];
		}
	}

	while (1)
	{
		vector<pair<int, int>> pos;//적의 위치

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] == 1)
				{
					pos.push_back({ j,i });
				}
			}
		}

		if (pos.empty())
		{
			return num;
		}

		//	stable_sort(pos.begin(), pos.end());

		for (int i = 0; i < 3; i++)
		{
			bool flag = false;
			int dis;
			int posX = 0, posY = 0;
			int min = 2000000000;
			for (int j = 0; j < pos.size(); j++)
			{
				dis = abs(pos[j].first - v[i]) + abs(pos[j].second - n);
				if (min >= dis && dis <= d)
				{
					if (min == dis)
					{
						if (posX > pos[j].first) //지금 적의 위치가 더 왼쪽에 있다면
						{
							posX = pos[j].first;
							posY = pos[j].second;
						}
					}
					else
					{
						flag = true;
						min = dis;
						posX = pos[j].first;
						posY = pos[j].second;
					}

				}
			}
			if (flag)
			{
				a[posY][posX] = 2;
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] == 2)
				{
					++num;
					a[i][j] = 3;
				}
			}
		}
		move(); //아래로 이동
	}
}

//궁수 배치
void dfs(int idx)
{
	if (v.size() == 3) //궁수 자리 배치 끝
	{
		//cout << "*****************\n";
		int num = attack();
		if (rst < num)
		{
			rst = num;
		}
	}

	if (idx >= m) return;

	v.push_back(idx);
	dfs(idx + 1);
	v.pop_back();
	dfs(idx + 1);
}


int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> m >> d;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			init[i][j] = a[i][j];
		}
	}

	dfs(0);
	cout << rst;
	return 0;
}
