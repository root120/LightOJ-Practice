
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
#define sc(n) scanf("%I64d", &n);
#define pr(n) printf("%I64d\n", n);
#define prr(n, m) printf("%I64d %I64d\n", n, m);
#define prrr(n, m, p) printf("%I64d %I64d %I64d\n", n, m, p);
#define lp(i,s,n) for(long long  i = s; i<n; i++)
#define pl(n) for(long long i=n-1; i>=0; i--)
#define  ars(arr,s,e) sort(arr+s,arr+n);
long long int mx = 1e18;
long long int mn = -1e18;
using namespace std;
ll visit[30], val ;

string str, str2;
void wow(ll pos, ll n, ll k)
{
    if(val == k) return;
    if(pos==n)
    {
        val++;
        for(ll j=0; j<n; j++)
        {
            printf("%c", str2[j]);
        }
       printf("\n");
       return;
    }

    for(int i=0; i<n; i++)
    {
        if(visit[str[i] - 'A'] == 0)
        {
            visit[str[i] - 'A'] = 1;
            str2[pos] = str[i];
            wow(pos+1, n, k);
            visit[str[i] - 'A'] = 0;
        }
    }
}


int main()
{
    ll p,q,r,s,t,n, k, i, cs = 0;

    sc(t);
    while(t--)
    {
        sc(n);
        sc(k);
        str.clear();
        for(i=0; i<n; i++)
        {
            str += 'A'+i;
        }
        memset(visit, 0, sizeof(visit));
        val = 0;
        printf("Case %lld:\n", ++cs);
        wow(0, n, k);
    }

}


