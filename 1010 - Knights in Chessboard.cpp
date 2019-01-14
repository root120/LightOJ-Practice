
#include <stdio.h>
int main()
{
    int t, a,b,c,d = 0,k,i, count,rem;
    scanf("%d", &t);
    while(t--)
    {
       d++;
       scanf("%d%d", &a, &b);
       c = a * b;
       if(a==1 || b == 1)
       {
           printf("Case %d: %d\n", d, c);
       }
       else if(a==2 || b==2)
       {
           if(a> b)
            c = a;
           else c = b;
           count = 0;
           for(i=1;i<=c; i++)
           {
                rem = i%4;
               if(rem == 1 || rem == 2)
               {
                   count++;
               }
           }
           printf("Case %d: %d\n", d, count*2);
       }
      else if(c%2 == 1)
       {
           c += 1;
           printf("Case %d: %d\n", d, c/2);
       }
       else
        printf("Case %d: %d\n", d, c/2);
    }
    return 0;
}
