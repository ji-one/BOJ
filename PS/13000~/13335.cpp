#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	queue<int> q;
	int n, w, l;
	cin >> n >> w >> l;
	int ans = 0;
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (q.size() == w)
		{
			while (1)
			{
				total -= q.front();
				q.pop();
				if (total + a <= l)
				{
					q.push(a);
					total += a;
					++ans;
					break;
				}
				else
				{
					q.push(0);
					++ans;
				}
			}
		}
		else if (total + a <= l)
		{
			q.push(a);
			total += a;
			++ans;
		}
		else
		{
			while (q.size() < w)
			{
				q.push(0);
				++ans;
			}
			while (1)
			{
				total -= q.front();
				q.pop();
				if (total + a <= l)
				{
					q.push(a);
					total += a;
					++ans;
					break;
				}
				else
				{
					q.push(0);
					++ans;
				}
			}
		}
	}
	ans += w;
	cout << ans << '\n';

	return 0;
}
