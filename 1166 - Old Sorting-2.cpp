#include <bits/stdc++.h>

using namespace std;

int a[110], vis[110], cnt;

int rec(int x, int i)
{
    cnt++;
    vis[a[x]] = 1;
    if(a[a[x]] != i)
        rec(a[x], i);
    return cnt;
}

int main()
{
    int t, l, i, j, n, ans, cs = 0;
    scanf("%d", &t);
    while(t--)
    {
        memset(vis, 0, sizeof(vis));
       scanf("%d", &n);
        for(i=1; i<=n; i++)
        {
            scanf("%d", &a[i]);
            if(i == a[i]) vis[i] = 1;
        }
        ans = 0;
        for(i=1; i<=n; i++)
        {
            if(vis[i] == 0)
            {
                vis[i] = 1;
                cnt = 0;
                rec(i, i);
                ans += cnt;
            }
        }
       printf("Case %d: %d\n", ++cs, ans);
    }
    return 0;
}
