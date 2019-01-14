
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll t,i,temp,j, cs = 1;
    cin >> t;
    while(t--)
    {
        cin >> temp;
        printf("Case %d: ", cs++);
        if(temp%2 == 1) cout << "Impossible" << endl;
        else
        {
            for(j=2; ; j+=j)
            {
                if((temp/j) %2 == 1)
                {
                    cout << temp/j << " " << j << endl;
                    break;
                }
            }
        }
    }
}
