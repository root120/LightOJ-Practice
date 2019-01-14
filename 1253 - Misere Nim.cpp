#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll a[55][55];


vector < ll > v;

int main()
{
    ll n,m,x, t, i, j, k, val, sum, cs = 0;
    cin >> t;
    while(t--)
    {
        cin >> n;
        bool flag = false;

        sum = 0;
        for(i=0; i<n; i++)
        {
            cin >> x;
            sum = sum ^ x;
            if(x>1)
            {
                flag  = true;
            }
        }


        if(!flag)
        {
            if(sum)
            {
                printf("Case %lld: Bob\n", ++cs);
            }
            else printf("Case %lld: Alice\n", ++cs);
        }
        else
        {
            if(sum == 0)
            {
                printf("Case %lld: Bob\n", ++cs);
            }
            else printf("Case %lld: Alice\n", ++cs);
        }
    }
}


