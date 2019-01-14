
#include <stdio.h>
#include <math.h>
#define PI 3.141592654

int main()
{
    int i,n,m,k,d = 0;
    double R, r, a;
    scanf("%d", &k);
    while(k--)
    {

        scanf("%lf", &R);
        scanf("%d", &n);
        d++;
        r = (sin(PI/n)*R) / (1+(sin(PI/n)));
        printf("Case %d: %.10lf\n",d, r);
    }
    return 0;
}
