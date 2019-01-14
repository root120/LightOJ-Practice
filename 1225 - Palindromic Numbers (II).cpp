
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int t,n, cs = 1, i, m,p, j ;
    int arr[20];

    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld", &n);
        m = n;
        i = 0;
        while(m!=0)
        {
            arr[i] = m%10;
            m /= 10;
            i++;
        }
        p = 0;
        for(j=0; j<i/2; j++)
        {
            if(arr[j] != arr[i-j-1])
                p= 1;
        }
        printf("Case %lld: ", cs++);
        if(p == 0) printf("Yes\n");
        else printf("No\n");
    }
}
