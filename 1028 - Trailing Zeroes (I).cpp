
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
#define sc(n) scanf("%lld", &n);
#define pr(n) printf("%I64d\n", n);
//#define prr(n, m) printf("%I64d %I64d\n", n, m);
#define prr(n, m, p) printf("%I64d %I64d %I64d\n", n, m, p);
#define lp(i,s,n) for(long long  i = s; i<n; i++)
#define pl(n) for(long long i=n-1; i>=0; i--)
#define  ars(arr,s,e) sort(arr+s,arr+n);
//long long int mx = 1e18;
long long int mn = -1e18;
using namespace std;

ll mx = 1000001, prime[1000100];
vector < ll > v;

void seive()
{
    lp(i,0, mx) prime[i] = 1;
    prime[0] = 0;
    prime[1] = 0;
    ll i, j;
    for( i=2; i<=sqrt(mx); i++)
        if(prime[i])
            for(j=i*i; j<=mx; j+= i)
            {
                prime[j] = 0;
            }
    v.push_back(2);
    for(i=3; i<=mx; i+= 2)
    {
        if(prime[i]) v.push_back(i);
    }
}
int main()
{
    ll p,q,r,s,t,n, ans, i, cnt, cs = 0, x;
    seive();
    p = v.size();
    sc(t);
    while(t--)
    {
        sc(n);
        ans  = 1;
        for(i=0; v[i]*v[i] <= n and p >i; i++)
        {
            cnt = 0;
            while(n %v[i] == 0)
            {
                n /= v[i];
                cnt++;
            }

            ans  *= (cnt+1);

        }
        if(n!= 1) ans *= 2;
        ans--;
        printf("Case %lld: %lld\n", ++cs, ans);
    }
}

