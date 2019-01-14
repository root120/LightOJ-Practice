

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

long long int mx = 1e18;
long long int mn = -1e18;
using namespace std;
double a[1000010];
ll lft[1000010];
ll rgt[1000010];

vector < ll > v;

ll gcd(ll a,ll b)
{
    ll tmp;
    while(b)
    {
        tmp=b;
        b=a%tmp;
        a=tmp;
    }
    return a;
}

void wow()
{
    double ans = 0.0;
    for(int i = 1; i<= 1000000; i++)
    {
        ans += 1.0/ (i+0.0);
        a[i] = ans;
    }
}

int main()
{
//    FastRead;
    ll p,q,r,s,t,i, j,ii, jj, n, sum, cnt = 0, st,cs = 0, len ;
    string str;

    cin >> t;

    wow();

    while(t--)
    {
        cin >> n;
        if(n<=1000000)
        {
            printf("Case %lld: %.10lf\n", ++cs, a[n]);
        }
        else
        {
            double x = n+0.0;

            double ans  = (log(x) + 0.57721566490 + (1.0/(2.0*x)) - (1.0/(12.0*x*x)));

            printf("Case %lld: %.10lf\n", ++cs, ans);
        }
    }

}


