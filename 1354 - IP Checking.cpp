
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll i,j,t,a1,a2,b1,b2,c1, c2, d1, d2, cs = 1, val;
    cin >> t;
    while(t--)
    {
        scanf("%lld.%lld.%lld.%lld", &a1, &b1, &c1, &d1);
        scanf("%lld.%lld.%lld.%lld", &a2, &b2, &c2, &d2);
        //cout << a1 << " " << b1 <<" " << c1 <<" "<< d1 <<  endl;
        //cout << a2 << " " << b2 <<" " << c2 <<" "<< d2 <<  endl;
        j = a2;
        a2 = 0;
        val = 1;
        while(j!=0)
        {
            a2 += (j%10) * val;
            j /=10;
            val += val;
        }
        j = b2;
        b2 = 0;
        val = 1;
        while(j!=0)
        {
            b2 += (j%10) * val;
            j /=10;
            val += val;
        }

        j = c2;
        c2 = 0;
        val = 1;
        while(j!=0)
        {
            c2 += (j%10) * val;
            j /= 10;
            val += val;
        }

        j = d2;
        d2 = 0;
        val = 1;
        while(j!=0)
        {
            d2 += (j%10) * val;
            j /= 10;
            val += val;
        }

        printf("Case %lld: ", cs++);
        if(a1 == a2 && b1 == b2 && c1 == c2 && d1 == d2)
        {
            cout <<"Yes" << endl;
        }
        else cout <<"No"<< endl;
    }
}

