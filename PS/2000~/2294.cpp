#include <bits/stdc++.h>
using namespace std;

int d[100001];
int a[101];

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        d[a[i]] = 1;
    }

    sort(a,a+n);

    for (int i = 0; i < n; i++)
    {
        for (int j = a[i]; j <= k; j++)
        {
            if (d[j] == 0 && d[j - a[i]] > 0)
            {
                d[j] = d[j - a[i]] + 1;
            }
            else if (d[j - a[i]] > 0)
            {
                d[j] = min(d[j], d[j - a[i]] + 1);
            }
        }
    }

    if (d[k] == 0)
        cout << -1;
    else
        cout << d[k];
}
