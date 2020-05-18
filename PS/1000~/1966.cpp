#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        queue<pair<int,int>> q;
        priority_queue<int> pq;

        for (int i = 0; i < n; i++)
        {
            int w;
            cin >> w;
            q.push({i,w});
            pq.push(w);
        }
        int rst = 0;

        while (!q.empty())
        {
            if (q.front().second == pq.top())
            {
                ++rst;
                if (q.front().first == m)
                {
                    break;
                }
                q.pop();
                pq.pop();
            }
            else
            {
                int i = q.front().first;
                int w = q.front().second;
                q.pop();
                q.push({i,w});
            }
        }
        cout << rst<<'\n';
    }
    return 0;
}
