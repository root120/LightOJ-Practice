
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define pb push_back

using namespace std;

vector < ll > v[1010];

int  par[1010];

ll n;

ll dp[1010];

ll BigMod(ll base, ll pwr)
{
    if(pwr == 0) return 1;

    if(pwr%2 == 1)
        return ((base%mod) * (BigMod(base, pwr-1)%mod))%mod;

    ll val = BigMod(base, pwr/2) %mod;;
    return (val*val) % mod;
}

ll fec(ll n)
{
    if(n == 1 || n == 0) return 1;
    ll &ret = dp[n];

    if(ret != -1) return ret;

    return ret = (n*fec(n-1)) %mod;
}

pair <ll, ll> wow(ll st)
{
    if(v[st].size() ==0) return make_pair(1,1);
    ll ans  = 1;
    ll man = 0;
    ll down = 1;

    for(ll i=0; i<v[st].size(); i++)
    {
        pair < ll, ll> p =  wow(v[st][i]);
        man += p.first;
        ans *= p.second;
        down *= fec(p.first);
        ans %= mod;
        down %= mod;
    }

    ans *= ((fec(man) %mod) * (BigMod(down, mod-2)%mod))%mod;
    ans%=mod;
    return make_pair(man+1, ans);
}

int main()
{
    memset(dp, -1, sizeof dp);

    ll t, i, j, k, m, n, x, tc = 0, y;

    cin >> t;

    while(t--)
    {
        cin >> n;
        memset(par, 0, sizeof par);
        for(i=1; i<n; i++)
        {
            cin >> x >> y;
            v[x].pb(y);
            par[y] = 1;
        }

        ll root;

        for(i=1; i<=n; i++)
        {
            if(par[i] == 0)
            {
                root = i;
                break;
            }
        }


        pair < ll, ll> p = wow(root);

        cout << "Case " << ++tc << ": " << p.second << endl;

        for(i=1; i<=n; i++)
        {
            v[i].clear();
        }
    }
    return 0;
}
