

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
ll a[100];

ll dp[11][11];

vector < ll > v;
ll n, m;

ll wow(ll prev, ll len)
{

//    cout << " st prev " << prev << " len " << len << " n " << n<< endl;


    if(len == n)
    {
        return 1;
    }

    ll &ret = dp[prev][len];
    if(ret != -1) return ret;
    ll val = 0;

    for(ll i=0; i<m; i++)
    {
        if(abs(prev- a[i])<=2)
        {
            val += wow(a[i], len+1);
        }

    }

    return ret = val;
}


int main()
{
    FastRead;
    ll p,q,r,s,t,i, j,ii, x, jj, ans, cnt = 0, st, len, tc= 0;
    string str;

    cin >> t;

    while(t--)
    {
        cin >> m >> n;

        for(i=0; i<m; i++)
        {
            cin >> a[i];
        }

        memset(dp, -1, sizeof(dp));

//        cout << dp[0][0][0]<< " dp "  << endl;

        ans = 0;

        for(i=0; i<m; i++)
        {
            ans += wow( a[i], 1);
        }

        cout << "Case " << ++tc<< ": " << ans << endl;
    }


}

