
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, i, j, k, cs = 0, ans, n, m;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        ans = 19;
        if(n>m) ans += (n-m)*4;
        ans += (max(n,m) * 4);
        printf("Case %d: %d\n", ++cs, ans);
    }
}
