

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
ll a[1000010];
ll lft[1000010];
ll rgt[1000010];

vector < ll > v;

ll gcd(ll a,ll b){
    ll tmp;
    while(b){
        tmp=b;
        b=a%tmp;
        a=tmp;
    }
    return a;
}


int main()
{
    FastRead;
    ll p,q,r,s,t,i, j,ii, x, jj, n,val, sum, cnt = 0, st,tc = 0, len ;
    string str;

    cin >> t;
    ull ans;
    while(t--)
    {
        cin >> n;
        ans = 0;
        val = n;
        for(i=2; i<=sqrt(n); i++)
        {
            x = n/i;
            ans += (x - 1)*i;

            ull N = (ull)val;
            ull ANS = (N*(N+1)) / (ull)2;

            N = (ull)(x);
            ANS = ANS - ((N*(N+1)) / (ull)2);

            ans += ANS * (i-2);
            val = x;
        }

        x = sqrt(n);
        if(x!=val)
        {
            ull N = (ull)val;
            ull ANS = (N*(N+1)) / (ull)2;

            N = (ull)(x);
            ANS = ANS - ((N*(N+1)) / (ull)2);

            ans += ANS * (i-2);
        }

         cout << "Case " << ++tc << ": " << ans << endl;
    }

}
