

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


long long int mx = 1e18;
long long int mn = -1e18;
using namespace std;
ll a[100010];
ll dp[110][110];
string str;

ll wow(ll left, ll right)
{
    if(left>=right) return 0;
    if(dp[left][right] != -1) return dp[left][right];
    if(str[left] == str[right]) dp[left][right] = wow(left+1, right-1);
    else dp[left][right] = 1 + min(wow(left, right-1), wow(left+1, right));
    return dp[left][right];

}

int main()
{
    ll p,q,r,s,t,i, j,ii,len, n, cs = 0, ans;

    cin >> t;
    while(t--)
    {
        cin >> str;
        len = str.size();
        memset(dp,-1,sizeof(dp));
        ll ans = wow(0, len-1);
        printf("Case %lld: %lld\n", ++cs, ans);
    }

}
