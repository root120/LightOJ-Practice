
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


using namespace std;
ll a[1000], cnt = 0;
ll mx = 46350;
//ll mx = 2147483648;
ll pr[50000];

vector < ll > v;

void seive()
{
    ll i, j;
    for(i=3; i<=mx; i+= 2) pr[i] = 1;
    for(i=3; i<= sqrt(mx); i+=2)
    {
        if(pr[i])
            for(j = i*i; j<mx; j+= i+i) pr[j] = 0;
    }
    v.pb(2);
    for(i=3; i<=mx; i+=2)
        if(pr[i]) v.pb(i);

    //cout << v.size() << endl;
}

ll segmentet_seive(ll a, ll b)
{


    if(a == 1) a++;
    int arr[b-a+1];
    memset(arr, 0, sizeof(arr));
    ll sqr = sqrt(b) + 1;
    ll cnt = 0, i, st;
    for(i = 0; i<v.size() && v[i]<= sqr; i++)
    {
       // cout << v[i] << endl;

        st = v[i]*v[i];

        if(st< a) st = ((a+v[i]-1)/v[i]) * v[i];
        for(; st<=b; st+=v[i])
            arr[st-a] = 1;


    }
    if(a <= 2 && b >=2 ) cnt++;
    ll j = a;
    if(a%2 == 0) j++;
    for(; j<=b; j+=2)
    {
        if(arr[j-a] == 0)
        {
            //cout << j << endl;
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    seive();
    ll len= v.size();
    ll p,q,r,s,t,i, j,ii,x, y, cs=0, ans, cnt, m, jj, n;
    string str;
    sc(n);
    while(n--)
    {
        sc(x);
        sc(y);
        ans = 0;
        if(x == 1 && y == 1)
        {
            printf("Case %lld: %lld\n",++cs, ans);
            continue;
        }
        ans =  segmentet_seive(x,y);
        printf("Case %lld: %lld\n",++cs, ans);

    }
}


