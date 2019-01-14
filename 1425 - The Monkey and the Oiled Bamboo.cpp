
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll a[100010], b[100010];

int main()
{
    ll t, i, j, k, m, n, cs = 0, mx, p, q;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld", &n);
        for(i=0; i<n; i++)
            scanf("%lld", &b[i]);
        a[0] = b[0];
        for(i=1; i<n;  i++)
        {
            a[i] = b[i] - b[i-1];
        }
        mx = 0;
        p = 0;
        for(i=0; i<n; i++)
        {
            if(mx<a[i])
            {
                mx = a[i];
                p = i;
            }
        }
        q = 0;
        k = mx;
        for(i = p; i<n; i++)
        {
            if(a[i]>k || k == 0)
            {
                q = 1;
                break;
            }
            else if(a[i] == k) k--;
        }
        if(q == 0) printf("Case %lld: %lld\n", ++cs, mx);
        else printf("Case %lld: %lld\n", ++cs, mx+1);
    }
}

