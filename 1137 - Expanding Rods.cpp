
#include <bits/stdc++.h>

using namespace std;

double l, n, c, r, a;

double wow(double b)
{
    r = ((a*a)/(2*b)) + (b/2);
    double theta = 2 *asin(a/r);

    return r * theta;
}

int main()
{
    int t, i;

    scanf("%d", &t);

    for(i=1; i<=t; i++)
    {
        scanf("%lf%lf%lf", &l, &n, &c);
        double ans = (1.0+(n*c)) * l;
        double st = 0.0, en = l, mid;
        a = l*0.5;

        for(int j=1; j<=60; j++)
        {
            mid = (st+en)/2;
            if(wow(mid)>ans) en = mid;
            else st = mid;
        }
        printf("Case %d: %f\n", i,mid);
    }
}

