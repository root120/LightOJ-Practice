
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i,j,k,m,n, t, cs = 0;
    string str;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &k);
        str.clear();
        for(i='A'; i<n + 'A'; i++)
        {
            str += i;
        }
        i = 0;
        printf("Case %d:\n", ++cs);
        do
        {
            i++;
            for(j=0; j<n; j++)
            {
                printf("%c", str[j]);
            }
            cout << endl;
            if(i == k) break;
        }
        while(next_permutation(str.begin(), str.end()));
    }
    return 0;
}
