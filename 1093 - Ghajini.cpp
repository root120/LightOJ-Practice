
#include <bits/stdc++.h>
#define ll long long
#define sc(n) scanf("%lld", &n)
#define mxx 1000000000
#define mnn 0

using namespace std;

ll mx_tree[1000000];
ll a[100010];
ll mn_tree[1000000];

void build_mx(ll st, ll en, ll pos)
{
    if(st == en)
    {
        mx_tree[pos] = a[st];
        return;
    }
    ll mid = (st+en)/2;
    build_mx(st, mid, pos*2+1);
    build_mx(mid+1, en, pos*2+2);

    mx_tree[pos] = max(mx_tree[pos*2+1],  mx_tree[pos*2+2]);
//    mx_tree[pos] = min(build_mx(st, mid, pos*2+1), build_mx(st, mid, pos*2+2));

}

void build_mn(ll st, ll en, ll pos)
{
    if(st == en)
    {
        mn_tree[pos] = a[st];
        return;
    }
    ll mid = (st+en)/2;
    build_mn(st, mid, 2*pos+1);
    build_mn(mid+1, en, 2*pos+2);

    mn_tree[pos] = min(mn_tree[2*pos+1],  mn_tree[2*pos+2]);
//    mx_tree[pos] = min(build_mx(st, mid, pos*2+1), build_mx(st, mid, pos*2+2));

}
//void build(ll low, ll high, ll pos)
//{
//    if(low == high)
//    {
//        tree[pos] = a[low];
//        return;
//    }
//    ll mid = (low+high)/2;
//    build(low, mid, 2*pos+1);
//    build(mid+1, high, 2*pos+2);
//    tree[pos] = min(tree[pos*2+1], tree[pos*2+2]);
//}

ll wow_mn(ll st, ll en, ll tx, ll ty, ll pos)
{
    if(ty<st || tx>en) return mxx;
    if(tx<=st && ty>=en) return mn_tree[pos];
    ll mid = (st+en)/2;
    return min(wow_mn( st, mid, tx, ty, pos*2+1), wow_mn( mid+1, en, tx, ty, pos*2+2));
}

ll wow(ll low, ll high, ll qi, ll qj, ll pos)
{
    if(low>=qi && qj>= high)
    {
        return mn_tree[pos];
    }
    if(low> qj || high<qi)
    {
        return mxx;
    }
    ll mid = (low+high)/2;
    ll ans1 = wow(low, mid, qi, qj, pos*2+1);
    ll ans2 = wow(mid+1, high, qi, qj, pos*2+2);
    return min(ans1, ans2);
}

ll wow_mx(ll st, ll en, ll tx, ll ty, ll pos)
{
    if(ty<st || tx>en) return mnn;
    if(tx<=st && ty>=en) return mx_tree[pos];
    ll mid = (st+en)/2;
//    printf("st %d en %d max %d\n", st, en, max(wow_mx( st, mid, tx, ty, pos*2+1), wow_mx( mid+1, en, tx, ty, pos*2+2)));
    return max(wow_mx( st, mid, tx, ty, pos*2+1), wow_mx( mid+1, en, tx, ty, pos*2+2));
}

int main()
{
    ll i, j, k, m, n, d, t, tc = 0, ans;
    sc(t);
    while(t--)
    {
        ans = 0;
        sc(n);
        sc(d);

        for(i = 0; i<n; i++)
        {
            sc(a[i]);
        }

//        memset(mx_tree, 0, sizeof mx_tree);
//        memset(mn_tree, 0, sizeof mn_tree);

        build_mx(0, n-1, 0);
        build_mn(0, n-1, 0);

        for(i=0; i<n-d; i++)
        {
            ll mn = wow_mn(0, n-1, i, i+d-1, 0);
            ll mnnn = wow(0, n-1, i, i+d-1, 0);
            ll mx = wow_mx(0, n-1, i, i+d-1, 0);

//            cout << i << " i " << i+d-1<< " mx " << mx << " mn " << mn << "mnn" << mnnn<< endl;
             ans = max(ans, mx - mn);


        }
        printf("Case %lld: %lld\n", ++tc, ans);
    }
}
