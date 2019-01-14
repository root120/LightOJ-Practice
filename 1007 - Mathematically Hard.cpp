

/*
                        --------------- Shuvo 's code-_______
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

long long int mx = 5000010;
long long int mn = -1e18;
using namespace std;
ll ans[5000100];
bool prime[5000100];

vector < ull > v;

void wow()
{
    ll i, j;

    for(i=3; i<mx; i+= 2)
        prime[i] = true;

    for(i=3; i<=sqrt(mx); i+=2)
    {
        if(prime[i])
        {
            for(j = i*i; j<=mx; j+= i+i)
            {
                prime[j] = false;
            }
        }
    }

    v.pb(2);
    for(i=3; i<=mx; i+=2)
    {
        if(prime[i]) v.pb(i);
    }

}

int main()
{
    ll p,q,r,s,t,i, j,ii, x, y,jj, n, sum, val,cnt = 0, st,tc = 0, len ;

    wow();

    for(i=0; i<=mx; i++)
    {
        ans[i] = i;
    }

    for(i = 0; i<v.size(); i++)
    {
        for(j=v[i]; j<=mx; j= j+ v[i])
        {
            ans[j] = ((ans[j] * (v[i] - (ull)1) )/v[i]);
        }
    }

    ans[0] = (ull)0;

    for(i=1; i<=mx; i++)
    {
        ans[i]= ans[i] * ans[i];
        ans[i] += ans[i-1];
    }

    scanf("%lld", &t);

    while(t--)
    {
        scanf("%lld%lld", &x, &y);
        ull res = ans[y] - ans[x-1];
        printf("Case %lld: %llu\n", ++tc, res);
    }

}
