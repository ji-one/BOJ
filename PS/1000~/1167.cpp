#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
vector<pair<int,int>> tree[100001];
bool visited[100001];
int nx=0;
int ans=0;
void dfs(int x, int d)
{
	if(visited[x]) return;
	else visited[x]=true;

	if(d>ans)
	{
		ans=d;
		nx=x;
	}

	for(int i=0;i<tree[x].size();i++)
	{
		dfs(tree[x][i].first,d+tree[x][i].second);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	 

	int v;
	cin>>v;
	int a,b,d;
	for(int i=0;i<v;i++)
	{
		cin>>a;
		while(1)
		{
			cin>>b;
			if(b==-1) break;
			cin>>d;
			tree[a].push_back({b,d});
		}
	}

	dfs(1,0);
	ans=0;
	memset(visited,false,sizeof(visited));
	dfs(nx,0);
	cout<<ans;

	return 0;
}
