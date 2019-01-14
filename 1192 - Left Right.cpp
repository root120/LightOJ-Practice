
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll a[110];
ll b[110];

vector < ll > v;

int main()
{
    ll n, t, i, j, k, sum, cs = 0;
    cin >> t;
    while(t--)
    {
        v.clear();
        cin >> n;
        for(i=0; i<n; i++)
        {
            cin >> a[i] >> b[i];
        }

        b[n] = 1000000000;
        sort(a, a+n);
        sort(b, b+n+1);

        for(i=0; i<n; i++)
        {
            if(a[i] == b[n]) continue;
            for(j=0; j<=n; j++)
            {
                if(a[i] < b[i])
                {
                    v.push_back(b[i]-a[i]-1);
                    break;
                }
            }
        }

        sum = 0;
        for(i=0; i<v.size(); i++)
        {
            sum = sum ^ v[i];
        }
        if(sum == 0)
        {
            printf("Case %lld: Bob\n", ++cs);
        }
        else printf("Case %lld: Alice\n", ++cs);
    }
}

