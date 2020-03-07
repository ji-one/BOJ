#include <iostream>
#include <algorithm>
using namespace std;
int map[501][501];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int dp[501][501];
int m, n;
int dfs(int x, int y)
{
    if (x == n-1 && y == m-1)
        return 1;
    if (dp[y][x] == -1)
    {
        dp[y][x]=0;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[y][x] > map[ny][nx])
            {
                dp[y][x] += dfs(nx, ny);
            }
        }
    }

    return dp[y][x];
}

int main(void)
{
    fill(&dp[0][0], &dp[500][501], -1);
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }
    cout<<dfs(0, 0);

    return 0;
}
