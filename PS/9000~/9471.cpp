#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
//피사노 주기 (pisano periods)
//피보나치 수열을 m으로 나눈 나머지가 주기를 이룸
int pisano_periods(int m)
{
	int cnt=0;
	int m1=0,m2=1;
	while(1)
	{
		++cnt;
		int tmp=m1;
		m1=m2;
		m2+=tmp;
		m2%=m;	
		if(m1==0 && m2==1) break;
	}
	return cnt;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	 

	int p;
	cin>>p;
	while(p--)
	{
		int n,m;
		cin>>n>>m; //k(m)=?

		cout<<n<<' '<<pisano_periods(m)<<'\n';
	}

	return 0;
}
