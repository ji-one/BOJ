#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int memo[101];
int cost[101];
int dp[101][10001];
int ans=2000000000;
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>memo[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>cost[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=10000;j++)
        {
            if(j-cost[i]>=0)
            {
                dp[i][j]=max(dp[i][j],dp[i-1][j-cost[i]]+memo[i]);
            }//i번째 앱 비활성화

            dp[i][j]=max(dp[i][j],dp[i-1][j]);//i번째 앱 활성화

            if(dp[i][j]>=m)
            {
                ans = min(ans, j);
            }
        }
    }

    cout<<ans;
    return 0;
}
