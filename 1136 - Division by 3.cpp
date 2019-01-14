
#include <bits/stdc++.h>

using namespace std;
int main()
{
    long long int t,i,d = 0,x,y;
    cin >> t;
    while(t--)
    {
        d++;
        cin >> x >> y;
        i = (((y/3)*2) +(y%3)/2) - ((((x-1)/3)*2) +((x-1)%3)/2);
        printf("Case %lld: %lld\n", d, i);
    }
}
