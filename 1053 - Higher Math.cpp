
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c,tc,l =0;
    cin >> tc;
    while(tc--)
    {
        cin >> a >> b >> c;
        if((a*a)+(b*b) == (c*c) || (c*c)+(b*b) == (a*a) || (a*a)+(c*c) == (b*b))
        {
            printf("Case %d: yes\n", ++l);
        }
        else printf("Case %d: no\n", ++l);
    }
    return 0;
}
