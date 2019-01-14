#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

ll visit[10010];
ll ti = 0;
vector < ll > v[10010];
set < ll > st;

struct my
{
    ll visitTime;
    ll lowTime;
    ll parent;
    ll child;
    bool aPoint;
} a[10010];


void dfs(ll node)
{
   // cout << "node " << node << endl;
    visit[node] = 1;
    a[node].visitTime = ti;
    a[node].lowTime = ti;
    ti++;

    a[node].child = 0;
    a[node].aPoint = false;
    //cout << "yss  " << node << "  " << v[node].size()<< endl;

    for(ll i = 0; i<v[node].size(); i++)
    {
       // cout << "noooo " << endl;

        if(v[node][i] == a[node].parent) continue;

        if(visit[v[node][i]] == 0)
        {
            a[v[node][i]].parent = node;
            a[node].child++;

            dfs(v[node][i]);

           //cout << "current node " << node << " adj node " << v[node][i] << endl;
            if(a[node].visitTime <= a[v[node][i]].lowTime)
            {
                //cout << "okay1 " << node << endl;
                a[node].aPoint = true;
            }
            else
            {
                if(a[node].lowTime > a[v[node][i]].lowTime)
                {
                    a[node].lowTime =  a[v[node][i]].lowTime;
                }
            }
        }
        else
        {
           // cout << "okay2 " << node << endl;
            if(a[node].lowTime > a[v[node][i]].visitTime)
            {
                a[node].lowTime =  a[v[node][i]].visitTime;
            }

        }
    }

    if(a[node].parent == 0 && a[node].child>=2 || a[node].parent != 0 && a[node].aPoint == true)
    {
        //cout << "okay " << endl;
        st.insert(node);
    }

}

int main()
{
    ll tc, n, m, i, x, ans,cs = 0, y;
    cin >> tc;
    while(tc--)
    {
        //cout << " time "<<tc  << endl;
        cin >> n >> m;


        for(i=0; i<=10010; i++)
        {
            visit[i] = 0;
            a[i].visitTime = 0;
            a[i].lowTime = 0;
            a[i].parent = 0;
            a[i].child = 0;
            v[i].clear();
        }
        ti = 0;
        st.clear();

        for(i=0; i<m; i++)
        {
            cin >> x >> y;
            v[x].pb(y);
            v[y].pb(x);
        }

        for(i=1; i<=n; i++)
        {
            if(visit[i] == 0)
            {
                a[i].parent = 0;
                dfs(i);
                //cout << "okay " << endl;
            }
        }

        ans = st.size();
        printf("Case %lld: %lld\n", ++cs, ans);

    }
    return 0;
}
/*1
4 4
1 2
1 3
2 3
3 4*/
