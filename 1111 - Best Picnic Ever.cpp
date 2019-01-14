
#include <bits/stdc++.h>

using namespace std;
int arr[120],vis[1009], marr[1010];
vector < int > v[1009];
queue <int> qu;

void bfs(int val)
{
    vis[val] = 1;
    qu.push(val);
    marr[val]++;
    while(!qu.empty())
    {
        int x = qu.front();
        for(int i=0; i<v[x].size(); i++)
        {
            if(vis[v[x][i]] == 0)
            {
                vis[v[x][i]] = 1;
                qu.push(v[x][i]);
                marr[v[x][i]]++;
            }
        }
        qu.pop();
    }
}

int main()
{
    int k,n,m,i,t,cs = 0, x, y;
    cin >> t;
    while(t--)
    {
        memset(marr, 0, sizeof(marr));

        cin >> k >> n >> m;
        for(i=0; i<k; i++)
        {
            cin >> arr[i];
        }

        for(i=0; i<m; i++)
        {
            cin >> x >> y;
            v[x].push_back(y);
        }
        for(i=0; i<k; i++)
        {
            memset(vis, 0, sizeof(vis));
            while(!qu.empty())
            {
                qu.pop();
            }
            bfs(arr[i]);
        }
        int cnt = 0;
        for(i=1; i<=n; i++)
        {
            if(marr[i] == k) cnt++;
        }
        printf("Case %d: %d\n", ++cs, cnt);
        for(i=0; i<n; i++)
        {
            v[i].clear();
        }
    }
}
