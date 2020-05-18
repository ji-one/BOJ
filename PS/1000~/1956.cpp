#include <bits/stdc++.h>
using namespace std;
int d[401][401];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int v, e;
    cin >> v >> e;
    fill(&d[0][0], &d[400][401], 200000000);
    for (int i = 0; i < v; i++)
    {
        d[i][i] = 0;
    }
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        d[a-1][b-1] = c;
    }
    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (d[i][k] + d[k][j] < d[i][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    int rst = 200000000;

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
           if (i != j)
            {
                if (d[i][j] + d[j][i] < rst)
                {
                    rst = d[i][j] + d[j][i];
                }
            }
        }
    }
    if(rst==200000000) cout<<-1;
    else cout << rst;
    return 0;
}
