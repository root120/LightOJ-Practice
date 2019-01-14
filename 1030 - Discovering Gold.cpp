

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
ll a[110];
double E[110];


vector < ll > v;

ll gcd(ll a,ll b)
{
    ll tmp;
    while(b)
    {
        tmp=b;
        b=a%tmp;
        a=tmp;
    }
    return a;
}


int main()
{
//    FastRead;
    ll p,q,r,s,t,i, j,ii, x, jj, n, cnt = 0, st,cs = 0, len ;
    string str;

    cin >> t;

    while(t--)
    {
        cin >> n;
        cnt = 0;

        for(i=1; i<=n; i++)
        {
            cin >> a[i];
        }
        E[n] = (double)a[n];
        double sum;

        for(i=n-1; i>0; i--)
        {
            sum = 0.0;

            if(n-i<6)
            {
//                cout << i << " less " <<endl;

                for(j=i+1; j<=n; j++)
                {
                    sum += E[j];
                }
                E[i] = (sum/(n-i+0.0));
//                cout << (n-i+0.0)  << " sum " << sum<< endl;

            }
            else
            {
                for(j=i+1; j<=i+6; j++)
                {
                    sum += E[j];
                }
                E[i] = (sum/(6.0));
            }

            E[i] += (double)a[i];

//            cout << E[i] << endl;

        }

//        for(i=1; i<=n; i++)
//        {
//            cout << i << " i E[i] " << E[i] << endl;
//        }

        cout << "Case " << ++cs <<": ";
        printf("%.7f\n", E[1]);
    }

}

