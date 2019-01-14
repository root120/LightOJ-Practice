

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
ll lft[1000010];
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


int main()
{
//    FastRead;
    ll p,q,r,s,t,i, j,ii, x, jj, n, ans, sum, cnt = 0, st,cs = 0, len ;
    string str;

    cin >> t;

    while(t--)
    {
        cin >> n;
        cnt = 0;
        sum = 0;

        for(i=0; i<n; i++)
        {
            cin >> x;
            if(x<0)
            {
                cnt++;
            }
            sum += abs(x);
        }

        printf("Case %lld: ", ++cs);
        if(cnt == n)
        {
            cout << "inf" << endl;
        }

        else
        {
            n -= cnt;
            ans = gcd(n, sum);
            n/=ans;
            sum/= ans;

            printf("%lld/%lld\n", sum, n);
        }
    }

}

