#include <iostream>  
#include <iomanip>  
#include <string>  
#include <cstring>  
#include <cstdio>  
#include <queue>  
#include <stack>  
#include <algorithm>  
#include <cmath>  
#include <ctime>

using namespace std;

const double PI = acos(-1.0);
const int maxn = 10000+10;

int n, f;
double A[maxn];

int judge(double area)
{
	int sum = 0, i = 0;
	for (i = 0; i < n; i++)
		sum += floor(A[i]/area);
	return sum >= f+1;
}

int main() 
{
#ifdef Local    
	freopen("a.in", "r", stdin);    
#endif
	int t = 0, kase = 0;
	cin >> t;
	for (kase = 1; kase <= t; kase++)
	{
		int i = 0, j = 0;
		double _max = 0;
		cin >> n >> f;
		for (i = 0; i < n; i++)
		{
			int r = 0;
			cin >> r;
			A[i] = PI * r * r;
			_max = max(_max, A[i]);
		}
		double L = 0, R = _max;
		while(fabs(R-L) > 1e-5)
		{
			double M = (L+R)/2;
			if (judge(M))
				L = M;
			else
				R = M;
		}
		cout << fixed << setprecision(4) << L << endl;
	}
}