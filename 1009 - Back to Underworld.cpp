
#include <bits/stdc++.h>
#define ll long long int

using namespace std;
vector <int> v[20010];
int arr[100010][3], vis[20010], l, r;
queue < int > ql;
queue < int > qr;

void bfs(int x, int y)
{
    ql.push(x);
    qr.push(y);
    vis[x] = 1;
    vis[y] = 1;
    l++;
    r++;
    while( ql.size() != 0 || qr.size() != 0)
    {
        while(!ql.empty())
        {
            int x = ql.front();
            for(int i=0; i<v[x].size(); i++)
            {
                if(vis[v[x][i]] == 0)
                {
                    vis[v[x][i]] = 1;
                    qr.push(v[x][i]);
                    r++;
                }
            }
            ql.pop();
        }

        while(!qr.empty())
        {
            int x = qr.front();
            for(int i=0; i<v[x].size(); i++)
            {
                if(vis[v[x][i]] == 0)
                {
                    vis[v[x][i]] = 1;
                    ql.push(v[x][i]);
                    l++;
                }
            }
            qr.pop();
        }
    }
}

int main()
{
    int i,n,t, cs = 0, mx, x,y;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(i=0; i<n; i++)
        {
            scanf("%d%d", &x, &y);
            arr[i][0] = x;
            arr[i][1] = y;

            v[x].push_back(y);
            v[y].push_back(x);
        }

        mx = 0;
        for(i=0; i<n; i++)
        {
            if(vis[arr[i][0]] == 0)
            {
                l = 0;
                r = 0;
                bfs(arr[i][0], arr[i][1]);
                mx += max(l, r);
            }

        }

        printf("Case %d: %d\n", ++cs, mx);
        for(i=0; i<=20000; i++)
        {
            v[i].clear();

        }
        memset(vis, 0, sizeof(vis));
        memset(arr, 0, sizeof(arr));
    }
    return 0;
}

