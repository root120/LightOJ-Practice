
#include <bits/stdc++.h>
#define ll long long int

using namespace std;
double arr[1000010];

void gnrt()
{
    for(int i = 1; i<1000009; i++)
    {
        arr[i] = arr[i-1] + log(i);
    }
}
int main()
{
    gnrt();
    ll t, i,j,k,m,n, b, ans, cs = 0;
    cin >> t;
    while(t--)
    {
        cin >> n >> b;
        ans = arr[n] / log(b);
        ans += 1;
        cs++;
        cout << "Case " <<cs << ": " << ans << endl;
    }
}
