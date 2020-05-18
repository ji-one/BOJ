#include <bits/stdc++.h>
using namespace std;
int a[201][201];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            if (i == j || x == 1)
            {
                a[i][j] = 1;
            }
        }
    }
    int path[1001];

    for (int i = 0; i < m; i++)
    {
        cin >> path[i];
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (a[i][k] && a[k][j])
                {
                    a[i][j] = 1;
                }
            }
        }
    }

    for (int i = 0; i < m - 1; i++)
    {
        if (!a[path[i]][path[i + 1]])
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}
