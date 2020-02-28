#include<iostream>
#include<algorithm>
using namespace std;
int five = 0, two = 0;


int fiveCnt(int num) {
	int cnt = 0;
	for (long long i = 5; num/i > 0;i*=5) {	
			cnt += num / i;
	}
	return cnt;
}

int twoCnt(int num) {
	int cnt = 0;
	for (long long i = 2; num/i > 0; i *= 2) {
			cnt += num / i;
	}
	return cnt;
}
int main(void)
{
	int n, r;
	cin >> n >> r;

	five += fiveCnt(n);
	if(n!=r) five -= fiveCnt(n - r);
	if(r!=0) five -= fiveCnt(r);

	two += twoCnt(n);
	if (n != r) two -= twoCnt(n - r);
	if (r != 0) two -= twoCnt(r);

	cout << min(five,two) << '\n';
	return 0;
}
