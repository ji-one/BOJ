#include <iostream>
#include <algorithm>
using namespace std;
#define INF 200000000
int cost[101][101];
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    fill(&cost[0][0], &cost[100][101],INF);
 
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cost[i][i]=0;
    }

    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(cost[a][b]>c) cost[a][b]=c;
    }
    
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(cost[i][k]+cost[k][j]<cost[i][j])
                {
                    cost[i][j]=cost[i][k]+cost[k][j];
                }
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(cost[i][j]==INF) cost[i][j]=0;
            cout<<cost[i][j]<<' ';
        }
        cout<<'\n';
    }

    return 0;
}
