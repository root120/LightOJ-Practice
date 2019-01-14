#include <stdio.h>
int main()
{
    int t,a,b;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &a);
        if(a <= 10)
        printf("%d %d\n",a, 0);
        else{
                b = a - 10;
            printf("%d %d\n", 10, b);
        }
    }
    return 0;
}
