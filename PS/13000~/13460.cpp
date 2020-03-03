#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
string map[10];

int rst = -1;
class INFO
{
public:
	int rx, ry, bx, by, cnt;
};
INFO start;
int bfs()
{
	int visited[10][10][10][10] = { 0, };
	queue <INFO> q;
	q.push(start);

	visited[start.ry][start.rx][start.by][start.bx] = 1;

	while (!q.empty())
	{
		INFO cur = q.front();
		q.pop();
		if (cur.cnt > 10) break;
		if (map[cur.ry][cur.rx] == 'O' && map[cur.by][cur.bx] != 'O')
		{
			rst = cur.cnt;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int next_ry = cur.ry;
			int next_rx = cur.rx;
			int next_by = cur.by;
			int next_bx = cur.bx;

			while (1)
			{
				if (map[next_ry][next_rx] != '#' && map[next_ry][next_rx] != 'O')
				{
					next_ry += dy[i];
					next_rx += dx[i];
				}
				else
				{
					if (map[next_ry][next_rx] == '#')
					{
						next_ry -= dy[i];
						next_rx -= dx[i];
					}
					break;
				}
			}

			while (1)
			{
				if (map[next_by][next_bx] != '#' && map[next_by][next_bx] != 'O')
				{
					next_by += dy[i];
					next_bx += dx[i];
				}
				else
				{
					if (map[next_by][next_bx] == '#')
					{
						next_by -= dy[i];
						next_bx -= dx[i];
					}
					break;
				}
			}

			if (next_ry == next_by && next_rx == next_bx)
			{
				if (map[next_ry][next_rx] != 'O')
				{
					int red_dis = abs(next_ry - cur.ry) + abs(next_rx - cur.rx);
					int blue_dis = abs(next_by - cur.by) + abs(next_bx - cur.bx);
					if (red_dis > blue_dis)
					{
						next_ry -= dy[i], next_rx -= dx[i];
					}
					else
					{
						next_by -= dy[i], next_bx -= dx[i];
					}
				}
			}

			if (visited[next_ry][next_rx][next_by][next_bx] == 0)
			{
				visited[next_ry][next_rx][next_by][next_bx] = 1;
				INFO next;
				next.ry = next_ry;
				next.rx = next_rx;
				next.by = next_by;
				next.bx = next_bx;
				next.cnt = cur.cnt + 1;
				q.push(next);
			}
		}
	}
	return rst;
}


int main(void)
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> map[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 'R')
			{
				start.ry = i;
				start.rx = j;
			}
			if (map[i][j] == 'B')
			{
				start.by = i;
				start.bx = j;
			}
		}
	}

	start.cnt = 0;

	cout << bfs();
	return 0;

}
