#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn=2e5+10;
struct node{
	double left;
	double right; 
}a[maxn];
int n,length,width;
bool cmp1(struct node x,struct node y)
{
	return x.right>y.right;
}
int main()
{
	while(cin>>n>>length>>width)
	{
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			double pos,r;
			cin>>pos>>r;
			if(r*2<=width)
				continue;
			double t;
			t=sqrt((double)(2*r*2*r)-width*width)/2;
			a[cnt].left=(double)pos-t;
			a[cnt].right=double(pos)+t;
			cnt++;
		}
		sort(a,a+cnt,cmp1);

		
		int num=0;
		double left=0.0,right=(double)length;
		while(left<right)
		{
			int i=0;
		//	cout<<"s"<<endl;
			for( i=0;i<cnt;i++)
			{
				if(a[i].left<=left&&a[i].right>left)
				{
					num++;
					left=a[i].right;
					break;
				}
			}
			if(i==cnt)
			{
				break;
			}
		}
		if(left<right)
			cout<<"-1"<<endl;
		else
			cout<<num<<endl;
	}
}