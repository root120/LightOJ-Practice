#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll a[25][4];
ll dp[25][5];


ll rec(ll n, ll cur, ll pre)
{

    if(cur == n) return 0;

    ll &ret =dp[cur][pre];
    if(ret != -1) return ret;
    ret = (1<<28);

    for(ll i=0; i<3; i++)
    {
        if(i != pre)
        {
            ret = min(ret, a[cur][i] +rec(n,cur+1, i));
        }
    }
    return ret;
}


int main()
{
    ll t, i, ans, j, cs = 0,n;
    cin >> t;

    while(t--)
    {
        cin >> n;
        for(i=0; i<n; i++)
        {
            for( j=0; j<3; j++)
            {
                cin >> a[i][j];
            }
        }

        memset(dp, -1, sizeof(dp));

        rec(n, 0,4);

       ans = dp[0][4];
        cout << "Case " << ++cs << ": " << ans << endl;
    }
}

