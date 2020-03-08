#include <iostream>
#include <algorithm>
using namespace std;
int pal[2001];
int dp[2001][2001];
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>pal[i];
    }

    for(int d=0;d<n;d++)
    {
        for(int i=1;i<=n-d;i++)
        {
            if(d==0) dp[i][i+d]=1;
            else if(d==1 && pal[i]==pal[i+d]) dp[i][i+d]=1;
            else if(pal[i]==pal[i+d] && dp[i+1][i+d-1]) 
            {
                dp[i][i+d]=1;
            }
        }
    }

    int m,s,e;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>s>>e;
        cout<<dp[s][e]<<'\n';
    }

    return 0;
}
