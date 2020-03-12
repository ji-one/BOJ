#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <deque>
using namespace std;
typedef long long ll;
ll a,b,c;
ll power(ll n, ll k) //n^k 구하는 함수
{
	if(k==0) return 1;
	ll tmp = power(n,k/2);
	ll rst = (tmp%c)*(tmp%c)%c;
	if(k%2) rst = rst*n%c;//홀수이면 n 한번 더 곱해야 함
	return rst;
}
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin>>a>>b>>c;

	cout<<power(a,b);
	return 0;
}
