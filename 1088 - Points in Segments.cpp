

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
#define sc(n) scanf("%lld", &n);
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
ll a[1000010];
ll b[110];

vector < ll > v;
vector < ll > :: iterator low, high;


int main()
{
//    FastRead;
    ll p,q,r,s,t,i, j,ii, x, jj, n, ans, cnt = 0, st,tc = 0, len, m, y;
    string str;

    sc(t);

    while(t--)
    {
        sc(n);
        sc(m);

        for(i=0; i<n; i++)
        {
//           cin >> a[i];
            sc(x);
            v.pb(x);
        }

//       sort(a, a+n);
        sort(v.begin(), v.end());
        printf("Case %lld:\n", ++tc);

        while(m--)
        {
            sc(x);
            sc(y);

            low = lower_bound (v.begin(), v.end(), x);
            high = upper_bound (v.begin(), v.end(),y);

            ll ans  = (high-v.begin())-(low-v.begin());
            printf("%lld\n",ans);
//            cout << (high-v.begin())-(low-v.begin()) << endl;
        }
        v.clear();
    }

}


