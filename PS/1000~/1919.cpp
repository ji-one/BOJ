#include <bits/stdc++.h>
using namespace std;
int a['z'+1];
int b['z'+1];
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	
	for(int i=0;i<s1.length();i++)
	{
		++a[s1[i]];
	}
	for(int i=0;i<s2.length();i++)
	{
		++b[s2[i]];
	}
	int rst=0;
	for(int i='a';i<='z';i++)
	{
		if(a[i]!=b[i])
		{
			rst+=abs(a[i]-b[i]);
		}
	}
	cout<<rst;
}
