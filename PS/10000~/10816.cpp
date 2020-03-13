#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
vector<int> v;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	 
	int n;
	cin>>n;
	int x;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		cout<<upper_bound(v.begin(),v.end(),x)-lower_bound(v.begin(),v.end(),x)<<' ';
	}
	return 0;
}
