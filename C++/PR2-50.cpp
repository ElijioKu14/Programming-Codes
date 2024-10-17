#include <cstdio>
#include <algorithm>
using namespace std;

#define ll long long //declares 11 as a new name to define type long long
const int maxn = 1e5 + 10; //constant variable
struct node{ //struct declaration
	int dex;
	ll sm; //sm of type long long
} tree[maxn*8];
int e[maxn], n; //array and variable declaration
int rl, rr; //variable declaration
ll res; //res of type long long

void build(int l, int r, int dex) //function declaration
{
	if(l == r) //if the number of test cases is 1
        tree[dex].dex = l, tree[dex].sm = (ll)e[l]; //sets the values to 1
	else{
		int mid = (l+r) >> 1; //function declaration and sets it will a value
		build(l, mid, dex*2), build(mid+1, r, dex*2+1); //recalls the function build, recursive
		if(e[tree[2*dex].dex] > e[tree[2*dex+1].dex]) //if loop to check if the current value in the array e[] is less than the one to its right
            tree[dex].dex = tree[2*dex+1].dex; //if true, updates its value
		else tree[dex].dex = tree[dex*2].dex; //if not true
		tree[dex].sm = tree[dex*2].sm + tree[dex*2+1].sm;
	}
}
ll sm_query(int l, int r, int dex, int x, int y) //function declaration that returns value of type long long
{
	if(l >= x && r <= y) return tree[dex].sm; //if true, return value to query function() to use to determine the value to tmp
	else if(l > y || r < x) return 0; //if true, return 0 and exit function
	else{ //condition wasnt true
		int mid = (l+r) >> 1;
		return sm_query(l, mid, dex*2, x, y)+sm_query(mid+1, r, dex*2+1, x, y); //recursive, recalls itself
	}
}
int m_query(int l, int r, int dex, int x, int y) //function declaration that returns value of type int
{
	if(l >= x && r <= y) return tree[dex].dex; //if true, return value of tree[dex].dex to determine the value of m, and exit
	else if(l > y || r < x) return 0; //if true, just return 0 and exit function
	else{ //if both condition were false
		int mid = (l+r) >> 1; //variable declaration
		int a = m_query(l, mid, dex*2, x, y), b = m_query(mid+1, r, dex*2+1, x, y); //value to determine the value of m in the function query()
		if(e[a] > e[b]) return b; //if value of a is less than be, return b
		else return a; //else return a
	}
}
void query(int l, int r) //function declaration
{
	int m = m_query(1, n, 1, l, r); //declares no variable of type int with calling the function m_query()
	ll tmp = (ll)e[m]*sm_query(1, n, 1, l, r); //declares new variable of type long long with calling the function sm_query()
	if(tmp > res) rl = l, rr = r, res = tmp; //if true, update the values
	if(l < m) query(l, m-1);
	if(r > m) query(m+1, r);
}

int main()
{
	int cnt = 0; //variable declaration
	while(scanf("%d", &n) != EOF){ //inputs value to be stored in n // number of test cases
		for(int i = 1; i <= n; i++) scanf("%d", &e[i]); //inputs and stores values into array e[]
		build(1, n, 1); //calls function
		e[0] = 1e9, res = 0, rl = rr = 1; //sets values into already declared variables and arrays.
		query(1, n); //calls function
		if(cnt++) printf("\n"); //always prints a new line while adding 1 to cnt
		printf("%lld\n%d %d\n", res, rl, rr); //prints out the number of weekends
	}
}