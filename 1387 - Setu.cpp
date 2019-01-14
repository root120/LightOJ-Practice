
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll a,b,ans, t,cs = 1, q;
    string str;

    cin >> t;
    while(t--)
    {
        printf("Case %lld:\n", cs++);
        cin >> q;
        ans =0;
        while(q--)
        {
            cin >> str;
            if(str == "report")
                cout << ans << endl;
            else
            {
                cin >> a;
                ans += a;
            }
        }
    }
}
