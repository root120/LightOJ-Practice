

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
ll dp[35][35];

vector < ll > v;

ll wow(ll n, ll k)
{
    if(k == 1) return n;
    if(n == k) return 1;

    ll &ret = dp[n][k];
    if(ret != -1) return ret;

    ret = wow(n-1, k) + wow(n-1, k-1);
    return ret;
}


int main()
{
    FastRead;
    ll p,q,r,s,t,i, j,ii, x, jj, n, k, ans, cnt = 0, st, len, tc = 0 ;
    string str;

    cin >> t;

    while(t--)
    {
        cin >> n >> k;
        if(k == 0)
        {
            ans  = 1;
            cout << "Case "<< ++tc << ": " << ans << endl;
            continue;
        }
        if(n<k)
        {
            ans  = 0;
            cout << "Case "<< ++tc << ": " << ans << endl;
            continue;
        }
        memset(dp, -1, sizeof dp);
        ans  = wow(n, k);

        for(i=0; i<k; i++)
        {
            ans*=n;
            n--;
        }
        cout << "Case "<< ++tc << ": " << ans << endl;
    }
}

