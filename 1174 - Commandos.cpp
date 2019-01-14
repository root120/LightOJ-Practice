
#include <bits/stdc++.h>

using namespace std;
vector < int > v[120];
int n, arr[120], vis[120], lvl[120], tlvl[120];
queue < int > qu;

void dfs(int st)
{
    memset(vis, 0, sizeof(vis));
    memset(tlvl, 0, sizeof(tlvl));

    qu.push(st);
    vis[st] = 1;
    tlvl[st]  = lvl[st];

    while(!qu.empty())
    {
        int x = qu.front();
        for(int i= 0; i<v[x].size(); i++)
        {
            if(vis[v[x][i]] == 0)
            {
                tlvl[v[x][i]] = tlvl[x] + 1;
                vis[v[x][i]] = 1;
                qu.push(v[x][i]);
            }
        }
        qu.pop();
    }

}
int main()
{
    int i,j,k,m,t,x,y,r, st,en, mx , cs = 0;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cin >> r;
        for(i=0; i<r; i++)
        {
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        cin >> st >> en;
        dfs(st);

        for(i=0; i<n; i++)
        {
            lvl[i] = tlvl[i];
        }
        mx =0;
        for(i=0; i<n; i++)
        {
            while(!qu.empty())
            {
                qu.pop();
            }
            dfs(i);
            mx = max(mx, tlvl[en]);
        }
        printf("Case %d: %d\n", ++cs, mx);
        memset(lvl, 0, sizeof(lvl));
        memset(arr, 0, sizeof(arr));
        for(i=0; i<=n; i++)
        {
            v[i].clear();
        }
    }
    return 0;
}
