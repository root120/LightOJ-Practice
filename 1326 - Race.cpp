
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

ll mod = 10056;

ll dp1[1010][1010];
ll dp2[1010];

vector < ll > v;
map < string, ll > mp;

ll nCr(ll n, ll r)
{
    if(r == 1) return n;
    if(n == r) return 1;

    ll &ret = dp1[n][r];
    if(ret != -1) return ret;

    return ret = ((nCr(n-1, r-1)%mod) + (nCr(n-1, r)%mod))%mod;
}

ll wow(ll n)
{
    if(n == 0) return 1;

    ll &ret = dp2[n];
    if(ret != -1) return ret;

    ret = 0;
    for(int i = 1; i<=n; i++)
    {
        ret += nCr(n, i) * (wow(n-i))%mod;
        ret %= mod;
    }

    return ret;
}

int main()
{
    FastRead;
    ll p,q,r,s,t,i, j,ii, x,len,  jj,ans, n, tc = 0;
    string str, str2;

    cin >> t;
    memset(dp1, -1, sizeof dp1);
    memset(dp2, -1, sizeof dp2);

    while(t--)
    {
        cin >> n;

        ans  = wow(n)%mod;

        cout << "Case " << ++tc << ": " << ans << endl;
    }
    return 0;
}


