
#include <bits/stdc++.h>
#define mod  100000007

using namespace std;

vector < int > v;
int dp[55][22][1010];

struct my{
    int val;
    int fre;
}a[110];

int n;

int wow(int st, int cnt, int make)
{
    if(st>=n)
    {
        if(make == 0) return 1;
        return 0;
    }

    int &ret = dp[st][cnt][make];
    if(ret != -1) return ret;

    int profit1 = 0, profit2 = 0;
    if(make - a[st].val >= 0 && cnt+1<= a[st].fre)
    {
        profit1 = wow(st, cnt+1, make - a[st].val);
    }
    profit2 = wow(st+1, 0, make);
    return ret = ((profit1%mod) + (profit2%mod))%mod;
}


int main()
{
    int t, i, j, k, tmp, tc = 0;
    scanf("%d", &t);
    while(t--)
    {
        v.clear();
        scanf("%d", &n);
        scanf("%d", &k);

        for(i=0; i<2*n; i++)
        {
            scanf("%d", &tmp);
            v.push_back(tmp);
        }

        for(i=0; i<n; i++)
        {
            a[i].val = v[i];
            a[i].fre = v[n+i];
        }

        memset(dp, -1, sizeof dp);

        int ans = wow(0,0,k);
        ans %= mod;
        printf("Case %d: %d\n", ++tc, ans);
    }
    return 0;

}

