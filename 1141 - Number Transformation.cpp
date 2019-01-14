
#include <bits/stdc++.h>
#define pb push_back

using namespace std;
vector <int > prime;
vector <int > grid[1010];
int a[1010];
int level[1010];
int vis[1010];


void seive()
{
    int i, j;
    for(i=3; i<1010; i+= 2) a[i] = 1;

    for(i=3; i<=sqrt(1010); i+=2)
        if(a[i])
            for(j=i*i; j<=1010; j+= i+i) a[j] = 0;

    prime.pb(2);
    a[1] = 1;
    a[2] = 1;
    for(i=3; i<=1000; i+= 2)
        if(a[i]) prime.pb(i);
}

void wow( int x )
{
    int val = x;
    for(int i=0; i<prime.size() && prime[i]<=x; i++)
    {
        if(x%prime[i] == 0)
        {
            grid[val].pb(val+prime[i]);
            while(x%prime[i] == 0)
            {
                x /= prime[i];
            }
        }
    }
}

void bfs(int st, int en)
{
    memset(level, 0, sizeof(level));
    memset(vis, 0, sizeof(vis));
    queue < int > qu;
    qu.push(st);
    level[st] = 0;
    while(!qu.empty())
    {
        int u = qu.front();
        qu.pop();
        for(int i=0; i<grid[u].size(); i++)
        {
            if(grid[u][i] <= en && vis[grid[u][i]] == 0)
            {
                vis[grid[u][i]] = 1;
                qu.push(grid[u][i]);
                level[grid[u][i]] = level[u] + 1;
            }
        }
    }
}


int main()
{
    seive();
    int t, s, val,c, cs = 0, p, ans, i, v, j;
    for(i=4; i<=1000; i++)
    {
        if(!a[i])
        wow(i);
    }
    scanf("%d", &c);

    while(c--)
    {
        scanf("%d%d", &s, &t);
        if(s == t)
        {
            printf("Case %d: 0\n", ++cs);
            continue;
        }
        if(s>t)
        {
            printf("Case %d: -1\n", ++cs);
            continue;
        }
        if(a[s] || t-s == 1)
        {
            printf("Case %d: -1\n", ++cs);
            continue;
        }

        bfs(s, t);

        if(level[t]==0)
        {
            printf("Case %d: -1\n", ++cs);
        }
        else
            printf("Case %d: %d\n", ++cs, level[t]);
    }
    return 0;
}
