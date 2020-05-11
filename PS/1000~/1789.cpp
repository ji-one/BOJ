#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long sum = 0;
	long long s;
	cin >> s;
	for (long long i = 1;; i++)
	{
		sum += i;
		if (s == sum)
		{
			cout << i;
			return 0;
		}
		if (s < sum)
		{
			cout << i - 1;
			return 0;
		}
	}
}
