#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	int rst = 0;
	int cnt = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (i + 1 < s.length() && s[i] == '(' && s[i + 1] == ')')
		{
			rst += cnt;
			i += 1;
			continue;
		}
		else
		{
			if (s[i] == '(')
			{
				++cnt;
			}
			else
			{
				cnt -= 1;
				rst += 1;
			}
		}
	}
	cout<<rst<<'\n';

}
