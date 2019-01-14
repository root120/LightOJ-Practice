

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
#define mod 1000000007
#define FastRead        ios_base::sync_with_stdio(0);cin.tie(0)

long long int mx = 1e18;
long long int mn = -1e18;
using namespace std;

ll tree[1000010];

vector < ll > v;
map < string, ll > mp;

struct my
{
    int ind;
    int val;

} a[100010];

bool cmp(my x, my y)
{
    if(x.val == y.val)
    {
        return x.ind > y.ind;
    }
    return x.val < y.val;
}

ll findd(ll st, ll en, ll qst, ll qen, ll pos)
{

//    cout << st << " st en " << en <<" qst " << qst << " qen " << qen << endl;
//    cout << "okay " << endl;
    if(qst>en || qen<st) return 0;
    if(st>=qst && en<=qen) return tree[pos];

    ll mid = (st+en)/2;

    ll ans = ((findd(st, mid, qst, qen, (pos*2)+1)%mod) + (findd(mid+1, en, qst, qen, (pos*2)+2) %mod))%mod;
    return ans;
}

void update(ll st, ll en, ll qpos,ll val, ll pos)
{
    ll mid = (st +en) /2;
    if(st == en)
    {
        tree[pos] += val;
        return;
    }
    else if(mid<qpos)
    {
        tree[pos] += val;
        update(mid+1, en, qpos, val, (pos*2)+2);
    }
    else
    {
        tree[pos] += val;
        update(st, mid, qpos, val, (pos*2)+1);
    }
}

int main()
{
    ll p,q,r,s,t,i, j,ii, x,len, cs = 0,res,  main_res, jj, n;
    string str, str2;
    sc(t);
    while(t--)
    {
        sc(n);
        for(i=0; i<n; i++)
        {
            sc(a[i].val);
            a[i].ind = i;
        }

        sort(&a[0], &a[n], cmp);
        memset(tree, 0, sizeof tree);

        main_res = 0;

//        for(i=0; i<n; i++)
//        {
//            cout << a[i].ind << " main array " << a[i].val << endl;
//        }
        for(i=0; i<n; i++)
        {
             res = 1 + findd(0, n-1, 0, a[i].ind, 0);
//             cout << i << " i res " << res << " a[i] " << a[i].ind << endl;
            main_res += res;
            main_res %= mod;
            res %= mod;
            update(0, n-1, a[i].ind, res, 0);
//            cout << "tree ";
//            for(j=0; j<10; j++)
//            {
//                cout << tree[j] << " ";
//            }
//            cout << endl;

        }

        printf("Case %lld: %lld\n", ++cs, main_res);
    }
}

