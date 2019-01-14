
#include <stdio.h>
int main()
{
    long long int a,b,c,d,e,f;
    int t,n,i,m = 0;
    long long int arr[10005];
    scanf("%d", &t);
    while(t--)
    {
        m++;
        scanf("%lld%lld%lld%lld%lld%lld%d",&a, &b,  &c, &d, &e, &f, &n);
        arr[0] = a;
        arr[1] = b;
        arr[2] = c;
        arr[3] = d;
        arr[4] = e;
        arr[5] = f;
        for(i=6; i<=n; i++)
        {
            arr[i] = (arr[i-1]+arr[i-2]+arr[i-3]+arr[i-4]+arr[i-5]+arr[i-6]);
            arr[i] = arr[i] % 10000007;
        }
        printf("Case %d: %d\n", m, arr[n] % 10000007);
    }
    return 0;
}
