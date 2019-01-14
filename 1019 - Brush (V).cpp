
#include <bits/stdc++.h>
#define ll long long int

using namespace std;
ll arr[110], vis[110], n, w[110][110];
vector < ll > v[110];

void bfs()
{
    ll i;
    for(i=0; i<=n; i++)
    {
        vis[i] = 0;
        arr[i] = 0;
    }
    queue <ll> qu;
    qu.push(1);
    vis[1] = 1;
    while(!qu.empty())
    {
        ll x = qu.front();
        for(i=0; i<v[x].size(); i++)
        {
            if(vis[v[x][i]] == 0)
            {
                vis[v[x][i]] = 1;
                arr[v[x][i]] = arr[x] + w[x][v[x][i]];
                qu.push(v[x][i]);
            }
            else
            {
                if(arr[v[x][i]] > arr[x] + w[x][v[x][i]])
                {
                    arr[v[x][i]] = arr[x] + w[x][v[x][i]];
                    qu.push(v[x][i]);
                }
            }

        }
        qu.pop();
    }
}

int main()
{
    ll t, i,j,k,m, cs = 0, wi, x, y;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        memset(w, 0, sizeof(w));
        while(m--)
        {
            cin >> x >> y >> wi;
            v[x].push_back(y);
            v[y].push_back(x);
            if(w[x][y] == 0){
            w[x][y] = wi;
            w[y][x] = wi;
            }
            else{
                w[x][y] = min(w[x][y],wi);
                w[y][x] = min(w[y][x],wi);
            }
        }
        bfs();
        if(vis[n] == 0)
        {
            printf("Case %lld: Impossible\n", ++cs);

        }
        else{
             printf("Case %lld: %lld\n", ++cs, arr[n]);
        }
        for(i=0; i<=n; i++)
        {
            v[i].clear();
        }
    }
    return 0;
}
