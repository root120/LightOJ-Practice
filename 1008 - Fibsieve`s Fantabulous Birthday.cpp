
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int i,d=0,k,ans=1, n, t, sqr, rem,ro,co;
    scanf("%lld", &t);
    while(t--)
    {
        d++;
        scanf("%lld", &n);
        sqr = sqrt(n);
        k = sqr*sqr;
        if(n-k != 0) sqr += 1;
        k = sqr*sqr;
        if((k-n) + 1<= sqr)
        {
            ro = sqr;
            co = (k-n) + 1;
        }
        else
        {
            ro = sqr -((k-(sqr-1)) - n);
            co = sqr;
        }
        if(sqr%2 == 1)
        {
            k = ro;
            ro = co;
            co = k;
        }
        printf("Case %lld: %lld %lld\n",d, ro, co);
    }
}
