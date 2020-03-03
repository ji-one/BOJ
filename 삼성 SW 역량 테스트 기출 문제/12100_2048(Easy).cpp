#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
#include<algorithm>
using namespace std;

int rst=0;
int n;

class Board
{
public:
	int a[20][20] = { 0, };

	int getMax(void)
	{
		int max = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (max < a[i][j])
				{
					max = a[i][j];
				}
			}
		}
		return max;
	}

	void rotate() //90도 돌리기
	{
		int tmp[20][20] = { 0, };
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				tmp[i][j] = a[n - j - 1][i];
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				a[i][j] = tmp[i][j];
			}
		}

	}

	void left()//왼쪽으로 밀기
	{
		int tmp[20][20] = { 0, };
		for (int i = 0; i < n; i++)
		{
			int idx = 0;
			bool flag = false;
			for (int j = 0; j < n; j++)
			{
				if (a[i][j] == 0)
				{
					continue;
				}

				if (idx != 0 && !flag && tmp[i][idx - 1] == a[i][j])
				{
					tmp[i][idx - 1] *= 2;
					flag = true;
				}

				else
				{
					tmp[i][idx] = a[i][j];
					++idx;
					flag = false;
				}
			}
		}


		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				a[i][j] = tmp[i][j];
			}
		}
	}
};

void dfs(int depth, Board current)
{
	if (depth == 5)
	{
		int max = current.getMax();

		if (max > rst)
		{
			rst = max;
		}
		return;
	}

	for (int i = 0; i < 4; i++)
	{		
		Board next = current;
		next.left();
		dfs(depth + 1, next);
		current.rotate();
	}



}
int main()
{
	cin >> n;
	Board board;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board.a[i][j];
		}
	}

	dfs(0, board);
	cout << rst;
	return 0;
}
