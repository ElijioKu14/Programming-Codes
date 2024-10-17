#include<iostream>
using namespace std;

struct edge
{
	int a,b,v;
};

int n,m;

edge E[2005];
long long dis[1005];

bool BmFr()
{
	dis[0] = 0;
	for (int i=1;i<n;i++)
		dis[i]=1000000000000000LL;
	
	for (int i=0;i<n-1;i++)
	{
		for (int i=0;i<m;i++)
		{
			if (dis[E[i].a]>dis[E[i].b]+E[i].v)
				dis[E[i].a]=dis[E[i].b]+E[i].v;
		}
	}
	
	bool negcyc = 0;
	
	for (int i=0;i<m;i++)
	{
		if (dis[E[i].a]>dis[E[i].b]+E[i].v)
		{
			negcyc=1;break;
		}
	}
	return !negcyc;
	
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t,a,b,vv;
	cin>>t;
	while (t--)
	{
		cin>>n>>m;
		
		for (int i=0;i<m;i++)
		{
			cin>>a>>b>>vv;
			E[i].a=a, E[i].b = b, E[i].v = vv;
		}
		
		if (BmFr())cout<<"not possible\n";
		else cout<<"possible\n";
		
	}
}