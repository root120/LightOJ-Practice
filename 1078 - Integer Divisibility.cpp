

#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll t, i, j, k, m, n, cnt, d, val, cs = 0;
    cin >> t;
    while(t--)
    {
        cin >> n >> d;
        val = d;
        cnt  = 1;
        while(val %n != 0)
        {
            val %= n;
            val *= 10;
            val += d;
            cnt++;
        }
        printf("Case %lld: ", ++cs);
        cout << cnt << endl;
    }
    return 0;
}
