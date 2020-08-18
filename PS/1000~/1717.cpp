#include<iostream>
using namespace std;

int parent[1000001];
int n, m;

int getParent(int x)
{
	if (parent[x] == x) return x;
	else return parent[x] = getParent(parent[x]);
}

void unionParent(int x, int y)
{
	x = getParent(x);
	y = getParent(y);

	if (x < y) parent[y] = x;
	else parent[x] = y;


}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);//입출력 번갈아 나타날 경우에 필수
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}
	int u, a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> a >> b;
		if (!u)
		{
			unionParent(a, b);
		}
		else
		{
			if (getParent(a) == getParent(b))
			{
				cout << "yes\n";
			}
			else
			{
				cout << "no\n";
			}
		}
	}
	return 0;
}
