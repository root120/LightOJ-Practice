
#include <bits/stdc++.h>

using namespace std;
int arr[50];
int cnt[1000010];
int vis[1000010];

int main()
{
    int i,j,k,m,n, cs = 0, mn, t, ans, div;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(i=0; i<n; i++)
        {
            scanf("%d", &arr[i]);
            cnt[arr[i]]++;
            vis[arr[i]] = 0;
        }

        ans = 0;
        for(i=0; i<n; i++)
        {
            if(vis[arr[i]] == 0)
            {
                vis[arr[i]] = 1;
                m = arr[i]+1;
                div = (cnt[arr[i]] / m);
                ans += (div* m);
                if(cnt[arr[i]] % m != 0)
                    ans += m;
            }
        }

        printf("Case %d: %d\n",++cs, ans);

        for(i=0; i<n; i++)
        {
            cnt[arr[i]]=0;
            vis[arr[i]]=0;
        }
    }
}
