#include<bits/stdc++.h>

using namespace std;
vector< int> v[50010];
int a[50010], vis[50010];
queue<int > qu;
int bfs(int x, int cnt)
{
    qu.push(x);
    vis[x] = 1;
    a[x] = 1;
    while(!qu.empty())
    {
        x = qu.front();
        for(int i=0; i<v[x].size(); i++)
        {
            if(vis[v[x][i]] == 0)
            {
                vis[v[x][i]] = 1;
                qu.push(v[x][i]);
                a[v[x][i]] = 1;
                cnt++;
            }
        }
        qu.pop();
    }
    return cnt;
}

int main()
{
    int t, i,j,n, cs = 0, x, y, ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=0; i<n; i++)
        {
            cin >> x >> y;
            v[x].push_back(y);
        }

        memset(a, 0, sizeof(a));
        for(i=1; i<=n; i++)
        {
            if(a[i] == 0)
            {
                memset(vis, 0, sizeof(vis));
                a[i] = bfs(i, 1);
            }
        }

        int mx = 0;
        for(i=1; i<=n; i++)
        {
           // cout << " *** " << i << " "<< a[i] << endl;
            if(mx<a[i]){
                mx = a[i];
                ans = i;
            }
        }
       // cout << ans << "   " << mx<< endl;
       printf("Case %d: %d\n", ++cs, ans);
        for(i=0; i<=n; i++)
        {
            v[i].clear();
        }
    }
    return 0;
}
