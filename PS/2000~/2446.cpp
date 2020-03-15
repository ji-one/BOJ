#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	 
	int n;
	cin>>n;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			cout<<' ';
		}
		for(int j=0;j<2*n-2*i-1;j++)
		{
			cout<<"*";
		}
		cout<<'\n';
	}
	for(int i=0;i<n-1;i++)
	{
		for(int j=(2*n-1)/2-i-1;j>0;j--)
		{
			cout<<' ';
		}
		for(int j=0;j<3+2*i;j++)
		{
			cout<<"*";
		}
		cout<<'\n';
	}

	return 0;
}
