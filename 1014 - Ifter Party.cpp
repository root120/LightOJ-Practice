
#include <bits/stdc++.h>
#define ll long long int

using namespace std;
vector < ll > v;

int main()
{
    ll t,x,y,i,j, k, cs = 0;
    cin >> t;
    while(t--)
    {
        v.clear();
        cin >> x >> y;
        j  =x - y;
        for(i = 1; i<= sqrt(j); i++)
        {
            if(j %i == 0)
            {
                if(i>y) v.push_back(i);
                k = j / i;
                if(i != k && k>y)
                {
                    v.push_back(k);
                }
            }
        }
        printf("Case %lld: ", ++cs);
        sort(v.begin(), v.end());
        if(v.size() == 0)
        {
            cout << "impossible" << endl;
        }
        else {
            for(i=0; i<v.size()-1; i++)
            {
                cout << v[i] << " ";
            }
            cout << v[v.size() - 1] << endl;
        }
    }
}
