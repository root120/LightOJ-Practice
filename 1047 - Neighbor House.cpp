#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t,n,i,j, x,y,z, cs= 0;
    int dp[21][5];
    scanf("%d", &t);
    while(t--)
    {
        scanf("\n%d", &n);
        memset(dp,0, sizeof(dp));
        for(i=1; i<=n; i++)
        {
            cin >> x >> y >> z;
            dp[i][0] = min(dp[i-1][1] + x,dp[i-1][2] + x);
            dp[i][1] = min(dp[i-1][0] + y,dp[i-1][2] + y);
            dp[i][2] = min(dp[i-1][0] + z,dp[i-1][1] + z);
        }
        printf("Case %d: ", ++cs);
        cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << endl;
    }

}
