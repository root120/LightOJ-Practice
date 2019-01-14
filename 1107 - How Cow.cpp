
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll t,x1,x2, y1,y2,tx, ty, q, cs = 1;
    cin >> t;
    while(t--)
    {
        cin >> x1 >> y1>> x2 >>y2;
        cin >> q;
        printf("Case %lld:\n",cs++ );
        while(q--)
        {
            cin >> tx>> ty;
            if(tx>=x1 && ty>= y1 && tx<=x2 && ty<=y2)
            {
                cout <<"Yes"<< endl;
            }
            else cout <<"No"<< endl;
        }
    }
    return 0;
}
