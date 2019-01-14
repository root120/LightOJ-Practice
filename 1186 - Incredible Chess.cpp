#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll a[110];
ll b[110];

vector < ll > v;

int main()
{
    ll n, t, i, j, k, val, sum, cs = 0;
    cin >> t;
    while(t--)
    {
        v.clear();
        cin >> n;
        for(i=0; i<n; i++)
        {
            cin >> a[i];
        }

        for(i=0; i<n; i++)
        {
            cin >> b[i];
        }


        for(i=0; i<n; i++)
        {
            val = b[i] - a[i] - 1;
            v.push_back(val);
        }

        sum = 0;
        for(i=0; i<v.size(); i++)
        {
            sum = sum ^ v[i];
        }
        if(sum == 0)
        {
            printf("Case %lld: black wins\n", ++cs);
        }
        else printf("Case %lld: white wins\n", ++cs);
    }
}


