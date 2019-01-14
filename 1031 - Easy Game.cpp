
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll a[110];
ll dp[110][110];

ll wow(ll st, ll en)
{

    if(st>en) return 0;
    if(st == en) return a[st];

    ll &ret = dp[st][en];

    if(ret != -1) return ret;
//    ll val = -1000000000;
    ll val = 0, val2 =0;
    ll ans1 = -10000000000;
    ll ans2 = -10000000000;
    for(int i = st; i<=en; i++)
    {
        val += a[i];
        ans1 =max(ans1, val - wow(i+1, en));
    }

   for(int i = en; i>=st; i--)
    {
        val2 += a[i];
        ans2 =max(ans2, val2 - wow(st, i-1));
    }
    return ret = max(ans1, ans2);
}


int main()
{
    ll t, n, i, tc = 0;
    cin >> t;

    while(t--)
    {
        cin >> n;

        for(i=0; i<n; i++)
        {
            cin >> a[i];
        }

        memset(dp, -1, sizeof dp);
        ll ans  = wow(0, n-1);

        cout << "Case " << ++tc << ": " << ans << endl;
    }
    return 0;
}

