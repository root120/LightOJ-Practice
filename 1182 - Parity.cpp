
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll i,j,k,t,n, cnt, cs = 1;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld", &n);
        cnt = 0;
        while(n)
        {
            if(n%2 == 1) cnt++;
            n /= 2;
        }
        printf("Case %lld: ", cs++);
        if(cnt%2 == 0)
            printf("even\n");
        else printf("odd\n");
    }
}
