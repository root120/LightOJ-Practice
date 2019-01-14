
#include <bits/stdc++.h>
#define mod  100000007

using namespace std;

vector < int > v;
int dp[10010];
int a[110];

int n;

//int wow(int st, int make)
//{
//    if(st>=n)
//    {
//        if(make == 0) return 1;
//        return 0;
//    }
//
//    int &ret = dp[st][make];
//    if(ret != -1) return ret;
//
//    int profit1 = 0, profit2 = 0;
//    if(make - a[st] >= 0)
//    {
//        profit1 = wow(st, make - a[st]);
//    }
//    profit2 = wow(st+1, make);
//    return ret = ((profit1%mod) + (profit2%mod))%mod;
//}


int main()
{
    int t, i, j, k, tmp, tc = 0;
    scanf("%d", &t);
    while(t--)
    {
//        v.clear();
        scanf("%d", &n);
        scanf("%d", &k);

        for(i=0; i<n; i++)
        {
            scanf("%d", &a[i]);
        }

        memset(dp, 0, sizeof dp);
        sort(a, a+n);
//
//        int ans = wow(0,k);

        dp[0] = 1;
//            dp[1] = 1;
        for(i=0; i<n; i++)
        {
            for(j=a[i]; j<=k; j++)
            {
                dp[j] += dp[j-a[i]];
                dp[j] %= mod;

            }

//            cout << "i " << i << " ";
//
//            for(j=0; j<=k; j++)
//            {
//                cout << dp[j] << " ";
//            }
//            cout << endl;

        }

//        for(i=0; i<=k; i++)
//        {
//            cout << dp[i] << " ";
//        }
//        cout << endl;
        printf("Case %d: %d\n", ++tc, dp[k]);
    }
    return 0;

}
