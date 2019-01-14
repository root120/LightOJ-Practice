
#include <bits/stdc++.h>
#define ll long long int
#define mod 10000007

using namespace std;
ll dp[10010];

ll wow(ll n)
{
    ll &ret = dp[n];
    if(ret != -1) return ret;
    ll ans = ((wow(n-1) %mod) +(wow(n-2) %mod)+(wow(n-3) %mod)+(wow(n-4) %mod)+(wow(n-5) %mod)+(wow(n-6) %mod) ) %mod;
    return ret = ans;
}

int main()
{
    ll i,j,m,n, a1,a2,a3,a4,a5,a6, cs = 0;
    int t;
    scanf("%d", &t);
    while(t--)
    {
        memset(dp, -1, sizeof(dp));
        scanf("%lld %lld %lld %lld %lld %lld %lld", &dp[0], &dp[1], &dp[2],&dp[3], &dp[4], &dp[5], &n);
        m =  (wow(n) %mod);
        printf("Case %lld: %lld\n",++cs, m);

    }
    return 0;
}
