#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n;
int inorder[100001];
int postorder[100001];
int idx[1000001];
void preOrder(int is, int ie, int ps, int pe)
{
	if(is>ie || ps>pe)
	{
		return;
	}
	int root = postorder[pe];
	cout<<root<<' ';
	int ir = idx[root];
	int l = ir-is; //루트의 왼쪽에 해당하는 길이
	preOrder(is, ir-1,ps,ps+l-1);
	preOrder(ir+1,ie,ps+l,pe-1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	 
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>inorder[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>postorder[i];
	}
	for(int i=0;i<n;i++)
	{
		idx[inorder[i]]=i;
	}
	preOrder(0,n-1,0,n-1);
	
	return 0;
}
