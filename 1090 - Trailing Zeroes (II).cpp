
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


ll wow(ll n, ll val)
{
    int cnt = 0;

    while(n%val == 0)
    {
        cnt++;
        n/=val;
    }
    return cnt;
}

ll cnt0(ll n, ll val)
{
    int cnt = 0;

    while(n/val>=1)
    {
        cnt += n/val;
        n/=val;
    }
    return cnt;
}


int main()
{
    FastRead;
    ll p,q,r,s,t,i, j,ii, x, jj, n, ans, sum, cnt = 0, st,cs = 0, len ;
    string str;

    cin >> t;

    while(t--)
    {
        cin >> n >> r >> p >> q;

        ans  = cnt0(n, 2) - (cnt0(r,2) + cnt0(n-r,2)) + (wow(p,2)*q);
        ans  = min(ans, cnt0(n, 5) - (cnt0(r,5) + cnt0(n-r,5)) + (wow(p,5)*q) );
        cout << "Case " << ++cs << ": " << ans << endl;
    }

}


