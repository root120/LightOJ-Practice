
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
map < string, ll > mp;

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
    int i, u, v, w, cnt = 0, ret= 0, x, y;
    for(i=0; i<=54; i++) par[i] = i;

    for(i=0; i<len; i++)
    {
        u = arr[i].node1;
        v = arr[i].node2;
        w = arr[i].weight;
        x = u;
        y = v;

        u = check(u);
        v = check(v);

        if(u != v)
        {
             //cout << "okay" <<endl;

             //cout << x << "  " << y << endl;
            par[u] = v;
            ret += w;
            cnt++;
            if(n-1 == cnt) return ret;
        }

    }
   // cout << "cnt " << cnt << endl;
    return ret= -1;
}

int main()
{
    ll p,q,r,s,t,i, j,sum,cs = 0, w, u, v, ans, n;
    string str1, str2;

    cin >> t;

    while(t--)
    {
        mp.clear();
        cin >> n;
        p  = 0;

        for(i=0; i<n; i++)
        {

            cin >> str1 >> str2 >> w;

            if(mp[str1]== 0)
            {
                mp[str1] = ++p;
            }

            if(mp[str2]== 0)
            {
                mp[str2] = ++p;
            }

            u = mp[str1];
            v = mp[str2];

            //cout << " u " << u << " v " << v << endl;
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
        if(n== 1)
        {
            cout << w << endl;
            continue;
        }

        sort(&arr[0], &arr[n], cmp);

        //cout << " p " << p << endl;

        ans = MST(n, p);

        if(ans == -1)
        {
            cout << "Impossible" << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
    return 0;
}

