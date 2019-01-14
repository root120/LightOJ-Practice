

/*
                         -------------Shuvo's code-----_______
                        /''''''''''(______O] ----------____  \______/]_
     __...---'"""\_ --''        Metropolitan university     ___________@ -> ->  -> - --  - -- - ---- ->>
 |'''                   ._   _______________=---------"""""""
 |                ..--''|   l L |_l   |
 |          ..--''      .  /-___j '   '
 |    ..--''           /  ,       '   '
 |--''                /           `    \
                      L__'         \    -
                                    -    '-.
                                     '.    /
                                       '-./
*/

///   ------------ Bismillah hirrahman nirrahim ----------   ///

#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long
#define sc(n) scanf("%I64d", &n);
#define pr(n) printf("%I64d\n", n);
#define prr(n, m) printf("%I64d %I64d\n", n, m);
#define prrr(n, m, p) printf("%I64d %I64d %I64d\n", n, m, p);
#define lp(i,s,n) for(long long  i = s; i<n; i++)
#define pl(n) for(long long i=n-1; i>=0; i--)
#define  ars(arr,s,e) sort(arr+s,arr+n);
#define pb push_back
#define FastRead        ios_base::sync_with_stdio(0);cin.tie(0)

long long int mx = 1e18;
long long int mn = -1e18;
using namespace std;
ll a[110];
ll b[110];

ll dp[110][110][110];

vector < ll > v;

ll wow(ll k, ll st, ll en)
{

    if(st>en) return 0;
    if(k == 1) return a[en] - a[st-1];

    ll &ret = dp[k][st][en];

    if(ret != -1) return ret;

    ret = mx;
    for(ll i=st; i<=en; i++)
    {
        ret = min(ret, i +max(wow(k-1, st,i-1), wow(k, i+1, en)));
    }

    return ret;
}


int main()
{
    FastRead;
    ll p,q,r,s,t,i, j,ii, x, jj, n, ans, cnt = 0, st,k,m,tc = 0, len ;
    string str;

    a[0] = 0;
    for(i=1; i<=100; i++)
    {
        a[i] = a[i-1] + i;
    }
    memset(dp, -1, sizeof dp);
    cin >> n;
    while(n--)
    {
        cin >> k >> m;

        ll ans = wow(k, 1, m);

        cout << "Case " << ++tc << ": " << ans << endl;

    }



}
