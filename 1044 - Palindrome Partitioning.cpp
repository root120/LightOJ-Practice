

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


ll dp[1010];

vector < ll > v;
string str;

bool check_pelindrom(ll st, ll en)
{
    if(st >= en) return true;

    if(str[st] != str[en])
    {
        return false;
    }
    else check_pelindrom(st+1, en-1);
}



ll wow(ll st, ll n)
{
    if(st==n)
    {
        return 0;
    }

    ll &ret = dp[st];

    if(ret != -1) return ret;

    ll ans = mx;

    for(ll i=st; i<n; i++)
    {
//        cout << "OK" << endl;
        if(check_pelindrom(st, i)){
//                cout << st << " out " << i << endl;
        ans = min(ans, 1+wow(i+1, n));
        }
    }
//    cout << "lft " << lft << " rgt " << rgt<< " ret " << ret << endl ;

    return ret = ans;

}

int main()
{
    FastRead;
    ll p,q,r,s,t,i, j,ii, x, jj, n, ans, cnt = 0, st,tc = 0, len ;


    cin >> t;

    while(t--)
    {
        cin >> str;
        len = str.size();

        memset(dp, -1, sizeof dp);
        ans = wow(0, len);

        cout << "Case " << ++tc<< ": " << ans << endl;
    }

}

