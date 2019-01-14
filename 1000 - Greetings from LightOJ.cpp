#include <stdio.h>
int main()
{
    int t,a,b,d=0;
    scanf("%d", &t);
    while(t--)
    {
        d++;
        scanf("%d%d", &a, &b);
        printf("Case %d: %d\n", d, a+b);
    }
    return 0;
}
