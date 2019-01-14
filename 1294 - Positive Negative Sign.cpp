
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll y,c,x,m,n,t, cs = 1;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        x = n/(m*2);
        y  = (m*(m-1)) + m;
        printf("Case %lld: ", cs++);
        cout << x*y<< endl;
    }
}
