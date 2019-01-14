
#include <bits/stdc++.h>
#define ll long long int
#define mn 0

ll a[100000], sTree[900000], store[900000], cnt;

using namespace std;

void upDate(ll low, ll high, ll qx, ll qy, ll val, ll pos)
{
    if(low>high)return;

    if(store[pos] != 0)
    {
        sTree[pos] += store[pos] * ((high-low) +1);
        if(low != high)
        {
            store[pos*2+1] += store[pos];
            store[pos*2+2] += store[pos];
        }
        store[pos] = 0;
    }
    if(high<qx || qy<low) return;

    if(low >= qx && high <= qy)
    {
        sTree[pos] += val  * ((high-low) +1);
        if(low != high)
        {
            store[pos*2+1] += val;
            store[pos*2+2] += val;
        }
        return;
    }
    ll mid = (low + high) /2;
    upDate(low, mid, qx, qy, val, pos*2+1);
    upDate(mid+1, high, qx, qy, val, pos*2+2);
    sTree[pos] = sTree[pos*2+1] + sTree[pos*2+2];
}

ll wow(ll low, ll high, ll qx, ll qy, ll pos)
{
    if(low>high) return mn;

    if(store[pos] != 0)
    {
        sTree[pos] += store[pos]  * ((high-low) +1);
        if(low != high)
        {
            store[pos*2+1] += store[pos];
            store[pos*2+2] += store[pos];
        }
        store[pos] = 0;
    }
    if(high<qx || qy<low) return mn;

    if(low >= qx && high <= qy)
    {
        return sTree[pos];
    }

    ll mid = (low + high)/2;
    ll ans1 = wow(low, mid, qx, qy, pos*2+1);
    ll ans2 = wow(mid+1,high, qx, qy, pos*2+2);
    return (ans1 + ans2);
}

int main()
{
    ll  t,i,j,k,n,m, cs=0, temp, x, y, v;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld%lld", &n, &m);
        memset(store, 0, sizeof(store));
        memset(sTree, 0, sizeof(sTree));

        printf("Case %lld:\n", ++cs);
        while(m--)
        {
            scanf("%lld", &temp);
            if(temp == 0)
            {
                scanf("%lld%lld%lld", &x, &y, &v);
                cnt = 0;
                upDate(0, n-1, x, y, v, 0);
            }
            else
            {
                scanf("%lld%lld", &x, &y);
                ll ans = wow(0, n-1, x, y, 0);
                printf("%lld\n", ans);
            }
        }
    }
    return 0;
}
