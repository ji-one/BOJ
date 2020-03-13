#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
long long mat[2][2]={{1,1},{1,0}};
long long mat2[2][2]={{1,1},{1,0}};
long long tmp[2][2];
void divide(long long x)
{
	if(x==1) return;
	divide(x/2);
	fill(&tmp[0][0],&tmp[1][2],0);
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<2;k++)
			{
				tmp[i][j]+=(mat2[k][j]*mat2[i][k]);
			}
			tmp[i][j]%=1000000;
		}
	}
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			mat2[i][j]=tmp[i][j];
		}
	}
	if(x%2)
	{
		fill(&mat2[0][0],&mat2[1][2],0);
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
			{
				for(int k=0;k<2;k++)
				{
					mat2[i][j]+=(tmp[i][k]*mat[k][j]);
				}
				mat2[i][j]%=1000000;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	 
	long long n;
	cin>>n;
	divide(n);
	cout<<mat2[1][0]%1000000;
	return 0;
}
