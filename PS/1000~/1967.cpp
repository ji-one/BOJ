#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
vector<pair<int,int>> tree[1000001];
int dist[1000001];
//1. 루트(1번정점)에서 제일 거리가 먼 정점을 찾는다.
//2. 찾은 그 정점에서 다시 제일 먼 정점을 찾는다.
void bfs(int start)
{
	queue<int> q;
	bool visited[1000001]={false,};
	memset(dist,0,sizeof(dist));
	q.push(start);
	visited[start]= true;
	while(!q.empty())
	{
		int x = q.front();

		q.pop();
		for(int i=0;i<tree[x].size();i++)
		{
			int nx = tree[x][i].first;
			int nd = tree[x][i].second;
			if(!visited[nx])
			{			
				q.push(nx);
				dist[nx]=dist[x]+nd;
				visited[nx]=true;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	 
	int n;
	cin>>n;

	for(int i=0;i<n-1;i++)
	{
		int a,b,d;
		cin>>a>>b>>d;
		tree[a].push_back({b,d});
		tree[b].push_back({a,d});
	}

	bfs(1);
	int start = 1;
	for(int i=2;i<=n;i++)
	{
		if(dist[i]>dist[start])
		{
			start = i;
		}
	}
	bfs(start);
	int rst=0;

	for(int i=1;i<=n;i++)
	{
		if(rst<dist[i])
		{
			rst = dist[i];
		}
	}
	cout<<rst;

	return 0;
}
