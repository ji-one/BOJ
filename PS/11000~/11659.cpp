#include <bits/stdc++.h>
using namespace std;
int a[100001];
int d[100001];
int s, e;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        d[i + 1] = d[i] + a[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> s >> e;
        cout << d[e] - d[s] + a[s - 1] << '\n';
    }
    return 0;
}
