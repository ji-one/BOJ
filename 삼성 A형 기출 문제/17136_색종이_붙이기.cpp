#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int a[10][10];
bool c[10][10];
int num = 0;
int ans = 2000000000;
int paper[5] = { 5,5,5,5,5 };

int count()
{
	int cnt = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (c[i][j]) ++cnt;
		}
	}
	return cnt;
}

void dfs(int x, int y, int cnt)
{

	if (count() == num)
	{
		if (ans > cnt) ans = cnt;
		return;
	}

	int tmp[10][10];
	bool flag = false;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (a[i][j] == 1 && !c[i][j])
			{
				x = j;
				y = i;
				flag = true;
				break;
			}
		}
		if (flag) break;
	}


	bool flag2;
	//dfs 시작
	for (int k = 0; k < 5; k++)
	{
		flag2 = false;
		for (int i = y; i <= y + k; i++)
		{
			for (int j = x; j <= x + k; j++)
			{
				if (!(a[i][j] == 1 && c[i][j] == false && i >= 0 && j >= 0 && i < 10 && j < 10))
				{
					flag2 = true;
					break;
				}
			}
			if (flag2) break;
		}

		if (flag2) continue;

		if (paper[k] > 0)//종이가 남아있다면
		{
			memcpy(tmp, c, sizeof(c));
			paper[k]--;
			for (int i = y; i <= y + k; i++)
			{
				for (int j = x; j <= x + k; j++)
				{
					c[i][j] = true;
				}
			}
			dfs(x, y, cnt + 1);
			paper[k]++;
			memcpy(c, tmp, sizeof(c));
		}
	}

	}




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> a[i][j];

			if (a[i][j] == 1) ++num;
		}
	}

	dfs(0, 0, 0);

	if (ans == 2000000000) cout << -1;
	else cout << ans;

	return 0;
}
