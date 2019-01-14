
/*
                        --------------- Shuvo 's code-_______
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
ll a[1000010];
ll g[10010];
ll rgt[1000010];

vector < ll > v;

ll gcd(ll a,ll b){
    ll tmp;
    while(b){
        tmp=b;
        b=a%tmp;
        a=tmp;
    }
    return a;
}

ll wow(ll val)
{
    set < ll > st;
    set < ll > :: iterator it;

    for(ll i=1; i<=val/2; i++)
    {
        ll j = val - i;

        if(i != j)
        {
            ll tmp = g[j] ^ g[i];
            st.insert(tmp);
        }
    }
    ll i = 0;
    for(it=st.begin(); it != st.end() ; it++)
    {
        if(*it != i)
            return i;
        i++;
    }
    return i;
}

int main()
{
    FastRead;
    ll p,q,r,s,t,i, j,ii, x, jj, n, ans, sum, cnt = 0, st,tc = 0, len ;
    string str;
    g[0] = 0;
    g[1] = 0;
    g[2] = 0;

    for(i=3; i<=10000; i++)
    {
        g[i] = wow(i);

//        cout << i << " " << g[i] << endl;
    }

//    cout << "ok" <<endl;

    cin >> t;

    while(t--)
    {
        cin >> n;
        ll xxor  = 0;

        for(i=0; i<n; i++)
        {
            cin >> x;
            xxor = xxor ^ g[x];
        }

        if(xxor != 0)
        {
            cout << "Case " << ++tc << ": Alice" << endl;
        }
        else cout << "Case " << ++tc << ": Bob" << endl;
    }

}


