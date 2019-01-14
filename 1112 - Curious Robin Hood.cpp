
#include <bits/stdc++.h>
#define ll long long int
#define mn 0

using namespace std;
ll a[100010];
ll tree[1000010];

void build(ll low, ll high, ll pos)
{
    if(low == high)
    {
        tree[pos] = a[low];
        return;
    }
    ll mid  = (low+high)/2;
    build(low, mid, 2*pos+1);
    build(mid+1, high, 2*pos+2);
    tree[pos] = tree[2*pos+1]+tree[2*pos+2];
}

void reuse(ll pos, ll low,ll high, ll val, ll p)
{
    if(low == high)
    {
       tree[p] += val;
        return;
    }
    ll mid = (low + high)/2;
    if(mid>=pos)
    {
        reuse(pos, low, mid, val, p*2+1);
    }
    else
    {
        reuse(pos, mid+1, high, val, p*2+2);
    }
    tree[p] += val;

}

ll wow(ll low, ll high, ll qi, ll qj, ll pos)
{
    if(low>= qi && high<= qj)
    {
        return tree[pos];
    }
    if(low>qj || high< qi)
    {
        return mn;
    }
    ll mid = (low+high)/2;
    ll ans1 = wow(low, mid, qi, qj, pos*2+1);
    ll ans2 = wow(mid+1, high, qi, qj, pos*2+2);
    return (ans1 + ans2);
}

int main()
{
    ll t,n, q,p, i, cs = 0, v, j;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld%lld", &n, &q);
        for(i=0; i<n; i++)
        {
            scanf("%lld", &a[i]);
        }
        printf("Case %lld:\n", ++cs);
        build(0, n-1, 0);

        while(q--)
        {
            scanf("%lld", &p);
            if(p==1)
            {
                scanf("%lld", &i);
                printf("%lld\n",a[i]);
                reuse(i,0, n-1, a[i]*(-1), 0);
                a[i] = 0;
            }
            else if(p==2)
            {
                scanf("%lld%lld", &i, &v);
                a[i] += v;
                reuse(i,0, n-1, v, 0);
            }
            else
            {
                scanf("%lld%lld", &i, &j);
                ll ans = wow(0, n-1, i, j, 0);
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}
