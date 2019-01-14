
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

double dp[100010];


map < string, ll > mp;

double wow(ll n)
{
    vector < ll > v;
    if(n == 1) return 0.0;

//    double &ret = dp[n];
    if(dp[n] != -1) return dp[n];

//    cout << "oka" << endl;

    v.clear();
    v.pb(1);
    for(ll i=2; i<=sqrt(n); i++)
    {
        if(n%i == 0)
        {
            v.pb(i);
            if(i != n/i) v.pb(n/i);
        }
    }

    ll sz = v.size()+1;
    double val = 0.0;
    for(ll i=0; i<v.size(); i++)
    {
        val += (double)((1.0/(sz+0.0)) *(wow(v[i]) + 1.0));
    }
//    cout << n << " n val " << val << endl;
    double tmp = (sz-1.0)/(sz+0.0);

//    cout << tmp << " tm " << endl;
    val += (1.0/(sz+0.0));
    return  dp[n] = (val/tmp);

}

int main()
{
//    FastRead;
    ll p,q,r,s,t,i, j,ii, x,len,  jj, n, tc= 0;
    string str, str2;

    cin >> t;
    for(i=0; i<=100009; i++) dp[i] = -1;
//    for(i=0; i<10; i++)
//    {
//        cout << dp[i] << " ";
//    }
//    cout << endl;

    while(t--)
    {
        cin >> n;

        double ans = wow(n);
//        printf("%.10f\n", ans);

//        cout << "Case " << ++tc << ": " << ans << endl;
        printf("Case %lld: %.10f\n", ++tc, ans);

    }
}

