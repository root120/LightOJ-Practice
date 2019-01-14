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
        v.clear();
        memset(a, 0, sizeof a);
        cin >> n >>m;

        for(i=0; i<n; i++)
        {
            sum = 0;
            for(j=0; j<m; j++)
            {
                cin >> x;
                sum += x;
            }
             v.push_back(sum);
        }


        sum = 0;
        for(i=0; i<v.size(); i++)
        {
            sum = sum ^ v[i];
        }

        if(sum == 0)
        {
            printf("Case %lld: Bob\n", ++cs);
        }
        else printf("Case %lld: Alice\n", ++cs);
    }
}

