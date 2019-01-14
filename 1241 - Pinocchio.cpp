#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, i, j,k, cnt, n, temp,val,x,cs = 0 ;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        cnt  = 0;
        x = 2;
        for(i=0; i<n; i++)
        {
            scanf("%d", &temp);
            val = temp - x;
            if(val != 0)
            {
                cnt++;
                cnt += val / 5;
                if(val %5 == 0) cnt--;

            }
            x = temp;
        }
        printf("Case %d: %d\n", ++cs, cnt);
    }
}
