

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
ll n;
ll large[110][110];
ll small[110][110];
ll visit[110][110];
ll par[110];

vector <ll > ve[110];

struct stu
{
    ll node1;
    ll node2;
    ll weight;
} arr[10100];

bool cmp(stu x, stu y)
{
    return x.weight < y.weight;
}

bool cmp2(stu x, stu y)
{
    return x.weight > y.weight;
}

ll check(ll node)
{
    if(par[node] == node) return node;
    return check(par[node]);
}

int main()
{
    ll p,q,r,s,t,i, j,x, y, min_weight, max_weight,cnt,  ans1, u,cs = 0, v, w, ans2;

    sc(t);

    while(t--)
    {
        sc(n);

        for(i=0;  i<=n; i++)
        {
            ve[i].clear();
            for(j=0; j<=n; j++)
            {
                large[i][j] = 0;
                small[i][j] = 100000;
                visit[i][j] = 0;
            }

        }
        while(scanf("%lld%lld%lld", &u, &v, &w) == 3)
        {
            if(u == 0 && v == 0 && w == 0) break;
            x = min(u,v);
            v = max(u,v);
            u = x;

            if(visit[u][v] == 0)
            {
                visit[u][v] = 1;
                small[u][v] = w;
                large[u][v] = w;
                ve[u].push_back(v);
            }
            else
            {
                large[u][v] = max(w, large[u][v]);

                small[u][v] = min(w, small[u][v]);
            }

        }




        p = 0;
        for(i=0; i<=n; i++)
        {
            for(j=0; j<ve[i].size(); j++)
            {
               // cout << "** " << i << " " << ve[i][j] << endl;
                arr[p].node1 = i;
                arr[p].node2 = ve[i][j];
                arr[p].weight = small[i][ve[i][j]];
                p++;
            }
        }

        sort(&arr[0], &arr[p], cmp);

        /*for(i=0; i<p; i++)
        {
            cout <<"check "<< arr[i].node1 << " " << arr[i].node2 << " " << arr[i].weight << endl;
        }*/

        cnt = 0;
        min_weight = 0;

        for(i=0; i<=n; i++) par[i] = i;
        for(i=0; i<p; i++)
        {
            x = arr[i].node1;
            y = arr[i].node2;
            w = arr[i].weight;
            u = check(x);
            v = check(y);
            if(u != v)
            {
                par[u] = v;
                cnt++;
                min_weight += w;
                if(cnt == n+1) break;
            }
        }


        p = 0;
        for(i=0; i<n; i++)
        {
            for(j=0; j<ve[i].size(); j++)
            {
                arr[p].node1 = i;
                arr[p].node2 = ve[i][j];
                arr[p].weight = large[i][ve[i][j]];
                p++;
            }
        }

        sort(&arr[0], &arr[p], cmp2);

        cnt = 0;
        max_weight = 0;

        for(i=0; i<=n; i++) par[i] = i;
        for(i=0; i<p; i++)
        {
            x = arr[i].node1;
            y = arr[i].node2;
            w = arr[i].weight;
            u = check(x);
            v = check(y);
            if(u != v)
            {
                //cout << "u v " << x << " " << y << " " << w<< endl;
                par[u] = v;
                cnt++;
                min_weight += w;
                if(cnt == n+1) break;
            }
        }

        //cout << min_weight << " min max " << max_weight << endl;
        ll ans = min_weight + max_weight;
        printf("Case %lld: ",++cs);
        if(ans&1)
        {
            printf("%lld/2\n", ans);
        }
        else
        {
            ans/=2;
            printf("%lld\n", ans);
        }


    }
}
