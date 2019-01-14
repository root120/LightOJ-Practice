
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,c,lc,rc,m,n,val,cs = 1,t, u,v;
    int a[110], b[110];
    cin >> t;
    while(t--)
    {
        cin >> n;
        lc= 0;
        rc = 0;
        memset(a,0, sizeof(a));
        memset(b,0, sizeof(b));
        while(n--)
        {
            cin >> u >> v >> c;
            if(a[u] == 0 && b[v] == 0)
            {
                a[u] = b[v] = 1;
                rc += c;

            }
            else{
                a[v] = b[u] = 1;
                lc += c;
            }
        }
        val= min(lc,rc);
        printf("Case %d: %d\n", cs++, val);
    }
}
