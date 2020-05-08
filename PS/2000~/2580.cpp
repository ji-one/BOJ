#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;
int a[9][9];
vector<pair<int, int>> v;

bool check(int x, int y, int val)
{
	for (int i = 0; i < 9; i++)
	{
		if (a[y][i] == val)//row check
		{
			return false;
		}
		else if (a[i][x] == val)//column check
		{
			return false;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (a[3 * (y / 3) + i][3 * (x / 3) + j] == val)//square check
			{
				return false;
			}
		}
	}
	return true;
}

void dfs(int idx)
{
	if (idx == v.size())
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << a[i][j] << ' ';
			}
			cout << '\n';
		}
		exit(0); //방법이 여럿인 경우는 그 중 하나만 출력
				 // 0 : 프로그램 수행이 정상적으로 종료
				 // 1 or 0이 아닌 기타 정수 : 프로그램 수행이 비정상적
	}

	for (int i = 1; i <= 9; i++)
	{
		int x = v[idx].first;
		int y = v[idx].second;

		if (check(x, y, i))
		{
			a[y][x] = i;
			dfs(idx + 1);
			a[y][x] = 0; //다 채우지 못했을 경우 대비 
		}
	}

}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 0)
			{
				v.push_back({ j,i });
			}
		}
	}
	dfs(0);
	return 0;
}
