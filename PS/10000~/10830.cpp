#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int mat[6][6];
int mat2[6][6];
int tmp[6][6];
int n;
long long b;
void divide(long long x)
{
	if(x==1)
	{
		return;
	}

	divide(x/2);

	fill(&tmp[0][0],&tmp[5][6],0);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				tmp[i][j]+=mat2[i][k]*mat2[k][j];
				tmp[i][j]%=1000;
			}
		}
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			mat2[i][j]=tmp[i][j];
		}
	}

	if(x%2)
	{
		fill(&mat2[0][0],&mat2[5][6],0);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				for(int k=0;k<n;k++)
				{
					mat2[i][j]+=(mat[i][k]*tmp[k][j]);
					mat2[i][j]%=1000;
				}
			}
		}
	}
	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	 

	cin>>n>>b;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>mat[i][j];
			mat2[i][j]=mat[i][j];
		}
	}

	divide(b);


	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<mat2[i][j]%1000<<' ';
		}
		cout<<'\n';
	}

	return 0;
}
