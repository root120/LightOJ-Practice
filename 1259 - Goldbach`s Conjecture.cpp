


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
#define ll int
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

vector < ll > v;

bool prime[10000010];

void seive()
{
    ll i, j;
    for(i=3; i<=10000000; i+= 2) prime[i] = true;

    for(i=2; i*i<= 10000000; i++)
    {
        if(prime[i])
        {
            for(j=i*i; j<=10000000; j+= i+i)
            {
                prime[j] = false;
            }
        }
    }
    prime[2] = true;

    v.pb(2);
    for(i=3; i<=10000000; i+=2)
    {
        if(prime[i])
        {
            v.pb(i);
        }
    }
}


int main()
{
    FastRead;
    seive();

    ll t,i, n, cnt, val, tc = 0;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cnt  = 0;
        for(i=0; v[i]<= n/2; i++)
        {
            val = n-v[i];
            if(prime[val]) cnt++;
        }
        cout << "Case " << ++tc << ": " << cnt << endl;
    }
    return 0;
}

