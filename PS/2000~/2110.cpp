#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
vector<int> v;
int d;
int n,c;
int mid;
void binarysearch(int start, int end)
{
	mid = (start+end)/2;

	int cnt=1;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(v[j]-v[i]>=mid)
			{
				++cnt;
				i=j-1;
				break;
			}
		}
	}

	if(mid>=end && cnt>=c)
	{
		cout<<mid;
		return;
	} 
	if(mid>=end && cnt<c){
		cout<<mid-1;
		return;
	} 

	if(cnt>=c) binarysearch(mid+1,end);
	else binarysearch(start,mid-1);
	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	 
	cin>>n>>c;
	int x;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	d=v[n-1]-v[0];
	binarysearch(1,d);
	
	return 0;
}
