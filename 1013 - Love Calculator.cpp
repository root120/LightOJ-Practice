
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
ll a[110];
ll b[110];

vector < ll > v;
map < string, ll > mp;
string str1, str2;
ll len, len1, len2;
ll dp1[31][31];
ll dp2[60][31][31];


ll LCS(ll l1, ll l2)
{
    if(len1 <= l1 || len2 <= l2) return 0;

    ll &ret = dp1[l1][l2];
    if(ret != -1) return ret;

    if(str1[l1] == str2[l2])
    {
        ret = 1 + LCS(l1+1, l2+1);
    }
    else{
        ret = max(LCS(l1+1, l2), LCS(l1, l2+1));
    }
    return ret;

}

ll wow(ll l, ll pos1, ll pos2)
{

    if(pos1 == len1 && pos2 == len2 && l == len) return 1;
    if(pos1 >= len1 && pos2 >= len2) return 0;

    ll &ret = dp2[l][pos1][pos2];
    if(ret != -1) return ret;

    if(pos1 == len1)
    {
        ret = wow(l+1, pos1, pos2+1);
    }
    else if(pos2 == len2)
    {
        ret = wow(l+1, pos1+1, pos2);
    }
    else if(str1[pos1] == str2[pos2])
    {
        ret = wow(l+1, pos1+1, pos2+1);
    }
    else{
        ret = wow(l+1, pos1, pos2+1) + wow(l+1, pos1+1, pos2);
    }
    return ret;
}

int main()
{
    FastRead;
    ll p,q,r,s,t,i, j,ii, x, jj, n, tc = 0;

    cin >> t;
    while(t--)
    {
        cin >> str1 >> str2;
        len1 = str1.size();
        len2 = str2.size();

        memset(dp1, -1, sizeof dp1);
        len = len1 + len2 - LCS(0, 0);

        memset(dp2, -1, sizeof dp2);
        ll ans2 = wow(0, 0, 0);

        cout << "Case " << ++tc << ": "<<len<< " "<< ans2 << endl;
    }
}
