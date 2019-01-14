
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

ll wow(ll n)
{
    ll low = 1, mid, val, ans;
    ll high = 100000000;
    while(low <= high)
    {
        mid = (low + high)/2;
        val = mid, ans = 0;
        val *= 5;
        while(val>1)
        {
            ans  += val / 5;
            val /=5;
        }
//        cout << mid << " ans "<<  ans << endl;

        if(ans == n)
        {
            return mid*5;
        }
        else if(ans >n)
        {
            high = mid-1;
        }
        else low = mid+1;
    }

    return -1;
}

int main()
{
    FastRead;
    ll p,q,r,s,t,i, j,ii, x, jj, n, tc = 0, ans;
    string str;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ans = wow(n);

        if(ans == -1)
        {
            cout << "Case " << ++tc << ": impossible" << endl;
        }
        else{
            cout << "Case " << ++tc << ": " << ans<< endl;
        }
    }
}


