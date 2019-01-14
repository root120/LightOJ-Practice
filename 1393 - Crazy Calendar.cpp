
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll t, n, m, x,i,j, r,c, cs= 0;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld%lld", &r, &c);
        ll val = 0;
        for(i=1; i<=r; i++)
        {
            for(j=1; j<=c; j++)
            {
                scanf("%lld", &x);

                if((r-i + c-j) % 2)
                    val = val ^ x;
            }
        }

        if(val)
        {
            printf("Case %lld: win\n", ++cs);
        }
        else printf("Case %lld: lose\n", ++cs);
    }
}
 s
