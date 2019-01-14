
#include <stdio.h>
int main()
{
    int t, a, d=0, ans,n,i;
    int arr[1000];
    scanf("%d", &t);
    while(t--)
    {
        d++;
        ans = 0;
        scanf("%d", &n);
        for(i=0; i<n; i++)
        {
            scanf("%d", &a);
            if(a>0)
            {
                ans += a;
            }
        }
        printf("Case %d: %d\n", d, ans);
    }
    return 0;
}
