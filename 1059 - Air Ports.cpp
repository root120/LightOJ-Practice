

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
#define sc(n) scanf("%lld", &n);
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
ll par[10010];
ll visit[10010];

struct stu
{
    ll node1;
    ll node2;
    ll weight;
} arr[100010];

bool cmp(stu x, stu y)
{
    return x.weight < y.weight;
}

ll check(ll node)
{
    if(par[node] == node) return node;
    return check(par[node]);
}

ll MST(ll len, ll cost)
{
    int i, u, v, w, ret= 0;
    for(i=0; i<=10010; i++) par[i] = i;

    for(i=0; i<len; i++)
    {
        u = arr[i].node1;
        v = arr[i].node2;
        w = arr[i].weight;

        u = check(u);
        v = check(v);

        if(u != v)
        {
            if(cost> w)
            {
                par[u] = v;
                ret += w;
            }
        }

    }
    return ret;
}

int main()
{
    ll p,q,r,s,t,i, j,sum,cs = 0, w, u, v, ans,m, cost,cnt, n;
    string str;

    sc(t);

    while(t--)
    {
        memset(visit,0, sizeof(visit));
        sc(n);
        sc(m);
        sc(cost);

        cnt = 0;

        for(i=0; i<m; i++)
        {
            sc(u);
            sc(v);
            sc(w);

            if(u<v)
            {
                arr[i].node1 = u;
                arr[i].node2 = v;
                arr[i].weight = w;
            }
            else
            {
                arr[i].node1 = v;
                arr[i].node2 = u;
                arr[i].weight = w;
            }
        }
        printf("Case %lld: ", ++cs);
       /* if(m == 0 || n == 1)
        {
            printf("%lld 1\n", cost);
            continue;
        }*/

        sort(&arr[0], &arr[m], cmp);

        ans = MST(m, cost);

        for(i=1; i<=n; i++)
        {
            u = check(i);
            // cout << " u " << u << endl;
            if(visit[u] == 0)
            {
                visit[u] = 1;
                cnt++;
            }
        }
        cost = cnt*cost;
        ans += cost;

        printf("%lld %lld\n", ans, cnt);
    }
    return 0;
}
