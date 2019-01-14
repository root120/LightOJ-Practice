
#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

#define PI acos(-1)

int main()
{
    int t, i,j, cs = 0, r1, r2, h, p;
    double ans, R, v ;
    cin >> t;
    while(t--)
    {
        cin >> r1 >> r2 >> h >> p;
        R= r2 + (r1-r2)*(double(p)/h);
        v = 1/3.0 * PI * p *( R*R + R*r2 + r2*r2 );
        printf("Case %d: %lf\n", ++cs, v);
    }
    return 0;
}
