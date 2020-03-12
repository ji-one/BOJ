#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double rst = 2000000000;
double x,y,z;
void binarysearch(double x1, double y1, double z1, double x2, double y2, double z2)
{
	double mx = (x1 + x2)/2;
	double my = (y1 + y2)/2;
	double mz = (z1 + z2)/2;

	double md = sqrt((mx-x)*(mx-x)+(my-y)*(my-y)+(mz-z)*(mz-z));
	double ld = sqrt((x1-x)*(x1-x)+(y1-y)*(y1-y)+(z1-z)*(z1-z));
	double rd = sqrt((x2-x)*(x2-x)+(y2-y)*(y2-y)+(z2-z)*(z2-z));

	if(abs(rst-md)<=0.00000000001)
	{
		return;
	}
	if(md<rst)
	{
		rst = md;
	}
	if(ld<rd)
	{
		binarysearch(x1,y1,z1,mx,my,mz);
	}
	else
	{
		binarysearch(mx,my,mz,x2,y2,z2);
	}
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	double x1, y1, z1, x2, y2, z2;
	cin>>x1>>y1>>z1>>x2>>y2>>z2>>x>>y>>z;

	binarysearch(x1,y1,z1,x2,y2,z2);
	cout<<fixed<<setprecision(10)<<rst;

	return 0;
}
