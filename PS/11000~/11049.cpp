#include <iostream>
#include <algorithm>
using namespace std;
#define INF 2000000000
int mat[501][2];// r c
int dp[501][501];
int main(void)
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>mat[i][j];
        }
    }

    for(int d=1;d<n;d++)
    {
        for(int s=1;s+d<=n;s++)
        {
            int e=s+d;
            dp[s][e]=INF;

            for(int m=s;m<e;m++)
            {
                dp[s][e]=min(dp[s][e],dp[s][m]+dp[m+1][e]+mat[s][0]*mat[m][1]*mat[e][1]);
            }
        }
    }

    cout<<dp[1][n];

    return 0;
}
