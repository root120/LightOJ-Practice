#include <stdio.h>
#include <math.h>
#define PI 2 * acos (0.0)
int main()
{
    int k, t=0;
    double a,b,c,circle, squre;
    scanf("%d", &k);
    while(k--)
    {
        t++;
        scanf("%lf", &a);
        circle = PI * pow(a, 2);
        b = a+a;
        squre = pow(b, 2);
        c= squre - circle;
        printf("Case %d: %.2lf\n",t, c);
    }
    return 0;
}
