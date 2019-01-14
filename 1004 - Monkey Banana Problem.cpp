
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll arr[250][250];

int main()
{
    ll t,i,j,k,n,m,x,y,r, cs = 0, mx;
    scanf("%lld", &t);
    while(t--)
    {
        memset(arr, 0, sizeof(arr));
        scanf("%lld", &n);
        r = (n*2) -1;
        for(i=1; i<=n; i++)
        {
            for(j = (n-i) +1 ; j<n+i; j+= 2)
            {
                //cin >> arr[i][j];
                scanf("%lld", &arr[i][j]);
            }
        }
        x = 1;
        for(i=n+1; i<=r; i++)
        {
            x++;
            for(j = x; j<=r-x+1; j+=2)
            {
                scanf("%lld", &arr[i][j]);
            }
        }
        for(i=1; i<=r; i++)
        {
            for(j=1; j<=r; j++)
            {
                //arr[i][j] += arr[i-1][j-1] + arr[i-1][j+1];
                arr[i][j] = max(arr[i][j]+arr[i-1][j-1], arr[i][j]+arr[i-1][j+1]);
            }
        }
        mx = 0;
        for(i=0; i<=r; i++)
        {
            if(arr[r][i] > mx)
            {
                mx=  arr[r][i];
            }
        }
        printf("Case %lld: %lld\n", ++cs, mx);
    }
}
