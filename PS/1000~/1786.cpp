
#include <bits/stdc++.h>
using namespace std;
vector<int> rst;
vector<int> makeTable(string pattern)
{
	int patternSize = pattern.size();
	vector<int> table(patternSize, 0);

	int j = 0;
	for (int i = 1; i < patternSize; i++)
	{
		while (j > 0 && pattern[j] != pattern[i])
		{
			j = table[j - 1];
		}
		if (pattern[j] == pattern[i])
		{
			table[i] = ++j;
		}
	}

	return table;
}
void KMP(string parent, string pattern)
{
	int parentSize = parent.size();
	int patternSize = pattern.size();
	vector<int> table = makeTable(pattern);
	int j = 0;
	for (int i = 0; i < parentSize; i++)
	{
		while (j > 0 && pattern[j] != parent[i])
		{
			j = table[j - 1];
		}
		if (pattern[j] == parent[i])
		{
			if (j == patternSize - 1)
			{
				rst.push_back(i - patternSize + 2);
				j = table[j];
			}
			else
				++j;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string parent;
	string pattern;
	getline(cin,parent);
	getline(cin,pattern);
	KMP(parent, pattern);
	cout << rst.size() << '\n';
	for (int i = 0; i < rst.size(); i++)
	{
		cout << rst[i]<<' ';
	}
	return 0;
}
