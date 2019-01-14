
#include <bits/stdc++.h>

using namespace std;
int life[20], n, ans;
int dp[(1<<15) +5];
int arr[20][20];

int Set(int N, int pos)
{
    return (N = N | (1<<pos));
}

bool check(int N, int pos)
{
    return (bool) (N & (1<<pos));
}

int wow(int mask)
{
    if(mask == (1<<n) -1) return 0;
    int &ret = dp[mask];

    if(ret != -1) return dp[mask];
    int mn = (1<<28), re;

    for(int i = 0; i<n; i++)
    {
        if(check(mask, i) == 0)
        {
            re = life[i] + wow(Set(mask, i));
            mn = min(re, mn);
        }
        else{
            for(int j = 0; j<n; j++)
            {
                 if(check(mask, j) == 0 && i!= j && arr[i][j] != 0)
                 {
                     int rem = (life[j] % arr[i][j]);
                     if (rem != 0) rem = 1;
                     else rem = 0;

                     re = (life[j] / arr[i][j]) + rem +wow(Set(mask, j));
                    mn = min(re, mn);
                    //cout << mn << endl;
                 }
            }
        }
    }
    return ret = mn;
}

int main()
{
    int t, i,j,k,m, cs = 0;
    string str;
    cin >> t;
    while(t--)
    {
        memset(dp, -1, sizeof(dp));
        cin >> n;
        for(i=0; i<n; i++)
        {
            cin >> life[i];
        }

        for(i= 0; i<n; i++)
        {
            cin >> str;
            for(j=0; j<n; j++)
            {
                arr[i][j] = str[j] - '0';
            }
            str.clear();
        }

        int res = wow(0);
        printf("Case %d: ", ++cs);
        cout << res << endl;
    }

}

/*1
3

10 10 10

010

100

111*/
