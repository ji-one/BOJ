#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v[501];
long long dist[501];
long long INF = 1e18;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    int a, b, c;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }
    bool minusCycle = false;
    fill(dist, dist + n + 1, INF);
    dist[1] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (auto &it : v[j])
            {
                if (dist[j] != INF && dist[it.first] > it.second + dist[j])
                {
                    dist[it.first] = it.second + dist[j];
                    if (i == n)
                        minusCycle = true;
                }
            }
        }
    }
    if (minusCycle)
        cout << -1;
    else
    {
        for (int i = 2; i <= n; i++)
        {
            dist[i] != INF ? cout << dist[i] <<'\n' : cout << -1 << '\n';
        }
    }

    return 0;
}
