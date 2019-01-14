
#include <bits/stdc++.h>

using namespace std;
int prime[120];
vector<int> v;

void khan()
{
    for(int i=2; i<= 100; i++) prime[i] = 1;

    for(int i = 2; i<= sqrt(100); i++)
    {
        if(prime[i])
        {
            for(int j = i*i; j<= 100; j+= i)
            {
                prime[j] = 0;
            }
        }
    }

    for(int i=2; i<=100; i++)
    {
        if(prime[i])
            v.push_back(i);
    }
    v.push_back(200);
}

int main()
{
    khan();
    int i,j,k = 0,m,n, t, cs = 0, val, ans;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        printf("Case %d: %d = ", ++cs, n);
        for(i = 0; v[i]<=n; i++)
        {
            val = n;
            ans = 0;
            while(val)
            {
                val /= v[i];
                ans += val;
            }
            if(i != 0)
            {
                cout << " * ";
            }
            printf("%d (%d)",v[i], ans);
        }
        printf("\n");

    }
    return 0;
}
