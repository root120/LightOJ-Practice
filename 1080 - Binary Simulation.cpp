#include <bits/stdc++.h>
#define ll long long int

using namespace std;
ll sTree[1000100], store[1000100];

void upDate(ll low, ll high, ll qx, ll qy, ll pos)
{
    if(low > high) return;

    if(store[pos] != 0)
    {
        sTree[pos] += store[pos];
        if(low != high)
        {
            store[pos*2+1] += store[pos];
            store[pos*2+2] += store[pos];
        }
        store[pos] = 0;
    }
    if(high<qx || low>qy) return;

    if(low>=qx && high<= qy)
    {
        sTree[pos] += 1;
        if(low != high)
        {
            store[pos*2+1] += 1;
            store[pos*2+2] += 1;
        }
        return;
    }
    ll mid = (low+high)/2;
    upDate(low, mid, qx, qy, pos*2+1);
    upDate(mid+1, high, qx, qy, pos*2+2);
}

ll wow(ll low, ll high, ll qx, ll pos)
{
    if(store[pos] != 0)
    {
        sTree[pos] += store[pos];
        if(low != high)
        {
            store[pos*2+1] += store[pos];
            store[pos*2+2] += store[pos];
        }
        store[pos] = 0;
    }
    if(low==high)
    {
        return sTree[pos];
    }
    ll mid = (low+high)/2;
    if(mid>=qx)
    {
        wow(low, mid, qx, pos*2+1);
    }
    else
    {
        wow(mid+1,high, qx, pos*2+2);
    }
}

int main()
{
    ll t, i,j,k, n, q, x, y, cs = 0;
    char ch;
    char str[100100];
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%s", str);
        scanf("%lld", &q);
        n = strlen(str);
        memset(sTree, 0, sizeof(sTree));
        memset(store, 0, sizeof(store));
        printf("Case %lld:\n", ++cs);
        while(q--)
        {
            getchar();
            scanf("%c", &ch);
            if(ch == 'I')
            {
                scanf("%lld%lld", &x,&y);
                upDate(0, n-1, x-1, y-1, 0);
            }
            else
            {
                scanf("%lld", &x);
                ll ans = wow(0,n-1, x-1, 0);
                if(ans%2 == 0)
                {
                    printf("%c\n",str[x-1]);
                }
                else
                {
                    if(str[x-1] == '0')
                    {
                        printf("1\n");
                    }
                    else printf("0\n");
                }
            }
        }

    }
}

