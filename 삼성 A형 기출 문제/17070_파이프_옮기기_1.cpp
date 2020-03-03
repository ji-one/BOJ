#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
int n;
int cnt = 0;
int map[16][16];
int dx[3] = { 1,1,0 };
int dy[3] = { 0,1,1 };
class INFO
{
public:
	int x, y, stat;
};
void bfs()
{
	INFO start;
	start.x = 1;
	start.y = 0;
	start.stat = 0; //0 가로 1 대각선 2 세로
	queue<INFO> q;
	q.push(start);
	while (!q.empty())
	{
		INFO cur;
		cur = q.front();
		q.pop();

		if (cur.x == n - 1 && cur.y == n - 1)
		{
			++cnt;
		}

		for (int i = 0; i < 3; i++)
		{
			INFO next;
			next.x = cur.x + dx[i];
			next.y = cur.y + dy[i];
			if (next.x < n && next.y < n && map[next.y][next.x] != 1) {
				if (cur.stat == 0 )
				{
					if (i == 0)
					{
						next.stat = 0;
						q.push(next);
					}
					if (i == 1)
					{
						if (map[next.y - 1][next.x] != 1 && map[next.y][next.x - 1] != 1)
						{
							next.stat = 1;
							q.push(next);
						}
					}
				}

				if (cur.stat == 1)
				{
					if (i == 1)
					{
						if (map[next.y - 1][next.x] != 1 && map[next.y][next.x - 1] != 1)
						{
							next.stat = 1;
							q.push(next);
						}
					}
					else
					{
						next.stat = i; 
						q.push(next);
					}									
				}

				if (cur.stat == 2)
				{
					if (i == 1)
					{
						if (map[next.y - 1][next.x] != 1 && map[next.y][next.x - 1] != 1) {
							next.stat = 1;
							q.push(next);
						}
					}
					if (i == 2)
					{
						next.stat = 2;
						q.push(next);
					}
				}
			}
		}
	}
}

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	bfs();
	cout << cnt;

}
