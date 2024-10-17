#include <bits/stdc++.h>
using namespace std;


int dp[2005][10005], cars[2005], sum[2005];
int pre[2005][10005], ans[2005];

int main()
{
    int cases, i, j, k, V, n, vj;
    cin >> cases;
    while (cases--)
    {
        cin >> V;
        V *= 100;
        memset (dp, 0, sizeof(dp));
        dp[0][0] = 1;
        n = 0;
        sum[0] = 0;
        while(cin >> k, k)
        {
            ++n;
            cars[n] = k;
            sum[n] = sum[n-1] + k;
        }
        vj = -1;
        for (i = 1; i <= n; i++)
        {
            for (j = 0; j <= V; j++)
            {
                if (j >= cars[i] && dp[i-1][j-cars[i]]) {
                    k = i;
                    vj = j;
                    dp[i][j] = 1;
                    pre[i][j] = j-cars[i];
                } else if (sum[i]-j <= V && dp[i-1][j]) {
                    k = i;
                    vj = j;
                    dp[i][j] = 1;
                    pre[i][j] = j;
                }
            }
        }
        i = k;
        while (i--)
        {
            j = pre[i+1][vj];
            if (j == vj) ans[i] = 1;
            else ans[i] = 0;
            vj = j;
        }
        cout << k << endl;
        for (i = 0; i < k; i++)
        {
            if (ans[i])
                cout <<"starboard"<<endl;
            else cout<<"port"<<endl;
        }
        if (cases) cout<<endl;
    }
    return 0;
}