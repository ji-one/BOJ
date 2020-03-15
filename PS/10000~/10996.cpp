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
		for(int j=0;j<(n+1)/2;j++)
		{
			cout<<"* ";
		}
		cout<<'\n';
		for(int j=0;j<n/2;j++)
		{
			cout<<" *";
		}
		cout<<'\n';

	}
	return 0;
}
