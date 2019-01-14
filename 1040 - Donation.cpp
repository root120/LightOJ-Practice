

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
ll par[55];

struct stu
{
    ll node1;
    ll node2;
    ll weight;
} arr[3000];

bool cmp(stu x, stu y)
{
    return x.weight < y.weight;
}

ll check(ll node)
{
    if(par[node] == node) return node;
    return check(par[node]);
}

ll MST(ll len, ll n)
{
    int i, u, v, w, cnt = 0, ret= 0;
    for(i=0; i<=54; i++) par[i] = i;

    for(i=0; i<len; i++)
    {
        u = arr[i].node1;
        v = arr[i].node2;
        w = arr[i].weight;

        u = check(u);
        v = check(v);

        if(u != v)
        {
           // cout << "okay" <<endl;
            par[u] = v;
            ret += w;
            cnt++;
            if(n-1 == cnt) return ret;
        }

    }
    return ret= 0;
}

int main()
{
    ll p,q,r,s,t,i, j,sum,cs = 0, w, ans, n;
    string str;

    cin >> t;

    while(t--)
    {
        cin >> n;

        sum  = p = 0;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                cin >> w;
                sum += w;
                if(w> 0)
                {
                    if(i<j)
                    {
                        arr[p].node1 = i;
                        arr[p].node2 = j;
                        arr[p].weight = w;
                        p++;
                    }
                    else{
                        arr[p].node1 = j;
                        arr[p].node2 = i;
                        arr[p].weight = w;
                        p++;
                    }
                }
            }
        }
        printf("Case %lld: ", ++cs);
        if(n== 1)
        {
            cout << sum << endl;
            continue;
        }

        sort(&arr[0], &arr[p], cmp);

        ans = MST(p, n);

        if(ans == 0)
        {
            cout << "-1" << endl;
        }
        else{
            ans  = sum - ans;
            cout << ans << endl;
        }
    }
    return 0;
}

