
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll t,n,i = 0, k;
    char str[20];
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld", &n);
        getchar();
        scanf("%s", str);
        printf("Case %lld: ", ++i);
        k = n%3;
        if(str[0] == 'A')
        {
            if(k == 0 || k == 2)
            {
                printf("Alice\n");
            }
            else
            {
                printf("Bob\n");
            }
        }
        else
        {
            if(k == 1 || k == 2)
            {
                printf("Bob\n");
            }
            else
            {
                printf("Alice\n");
            }
        }
    }
    return 0;
}

