
#include <bits/stdc++.h>
#define ll long long int
#define mx 100020;

using namespace std;
ll a[100100];
ll tree[1000000];

void build(ll low, ll high, ll pos)
{
    if(low == high)
    {
        tree[pos] = a[low];
        return;
    }
    ll mid = (low+high)/2;
    build(low, mid, 2*pos+1);
    build(mid+1, high, 2*pos+2);
    tree[pos] = min(tree[pos*2+1], tree[pos*2+2]);
}

ll wow(ll low, ll high, ll qi, ll qj, ll pos)
{
    if(low>=qi && qj>= high)
    {
        return tree[pos];
    }
    if(low> qj || high<qi)
    {
        return mx;
    }
    ll mid = (low+high)/2;
    ll ans1 = wow(low, mid, qi, qj, pos*2+1);
    ll ans2 = wow(mid+1, high, qi, qj, pos*2+2);
    return min(ans1, ans2);
}

int main()
{
    ll n, i,j, k, q, u,v, cs = 0, t;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld%lld", &n, &q);
        for(i=0; i<n; i++)
        {
            scanf("%lld", &a[i]);
        }
        build(0, n-1, 0);
        printf("Case %lld:\n", ++cs);
        while(q--)
        {
            scanf("%lld%lld", &u, &v);
            ll ans = wow(0, n-1, u-1, v-1, 0);
            printf("%lld\n", ans);
        }
    }
    return 0;
}
